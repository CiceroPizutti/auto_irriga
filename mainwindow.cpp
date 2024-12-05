#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSettings>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , irrigacaoLigada(false) // Inicializa a irrigação como desligada
    , networkManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    // Cria uma instância de QSettings
    QSettings settings("save_last");

    // Recupera o último valor salvo do slider
    int lastSliderValue = settings.value("ultimoValorSlider", 0).toInt(); // Padrão 0 se não existir
    ui->porcento_horizontalSlider->setValue(lastSliderValue); // Define o valor do slider
    ui->porcentagem_label->setText(QString::number(lastSliderValue) + "%"); // Atualiza a label

    // Configuração da porta serial
    serial = new QSerialPort(this);
    serial->setPortName("/dev/ttyACM0");  // Altere para o nome correto da porta
    serial->setBaudRate(QSerialPort::Baud9600);

    if (serial->open(QIODevice::ReadWrite)) {
        // Configurar temporizador para ler os dados periodicamente
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &MainWindow::readSerialData);
        timer->start(1000); // Ler a cada 1 segundo
    } else {
        qDebug() << "Erro ao abrir a porta serial!";
    }

    ui->irrigar_pushButton->setText("Ligar a Irrigação");

    // Verifica previsão de chuva periodicamente
    connect(&weatherTimer, &QTimer::timeout, this, &MainWindow::checkWeatherForecast);
    weatherTimer.start(3600000); // Verifica a cada 1 hora

    checkWeatherForecast(); // Primeira verificação ao iniciar
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_porcento_horizontalSlider_valueChanged(int value)
{
    // Atualiza o texto da QLabel para mostrar a porcentagem do slider
    ui->porcentagem_label->setText(QString::number(value) + "%");

    // Salva o valor do slider em QSettings
    QSettings settings("save_last");
    settings.setValue("ultimoValorSlider", value);
}

void MainWindow::readSerialData()
{
    if (serial->canReadLine()) {
        QString line = serial->readLine();
        bool ok;
        int humidity = line.trimmed().toInt(&ok); // Parseia o valor
        if (ok) {
            ui->progressBar->setValue(humidity); // Atualiza o QProgressBar

            // Armazena no histórico
            historicoUmidade.append(qMakePair(QDateTime::currentDateTime(), humidity));

            // Compara a umidade lida com o valor do QSlider
            int sliderValue = ui->porcento_horizontalSlider->value();
            if (humidity < sliderValue && irrigacaoLigada && !chuvaPrevista) {
                // Enviar '1' para o Arduino para ligar o relé
                serial->write("1");
            } else {
                // Enviar '0' para o Arduino para desligar o relé
                serial->write("0");
            }
        }
    }
}

void MainWindow::on_irrigar_pushButton_clicked()
{
    irrigacaoLigada = !irrigacaoLigada; // Alterna o estado

    if (irrigacaoLigada) {
        ui->irrigar_pushButton->setText("Irrigação Ligada");
        ui->irrigar_pushButton->setStyleSheet("color: lightgreen; font-weight: bold;");
    } else {
        ui->irrigar_pushButton->setText("Ligar a Irrigação");
        ui->irrigar_pushButton->setStyleSheet("");
    }
}

void MainWindow::exportarCSV()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Salvar Histórico", "", "CSV Files (*.csv)");

    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);

        // Cabeçalho com colunas separadas para ano, mês, dia e umidade
        stream << "Ano,Mes,Dia,Umidade (%)\n";

        // Dados
        for (const auto &entry : historicoUmidade) {
            QDateTime dateTime = entry.first;
            stream << dateTime.date().year() << ","
                   << dateTime.date().month() << ","
                   << dateTime.date().day() << ","
                   << entry.second << "\n";
        }

        file.close();
        QMessageBox::information(this, "Exportação", "Histórico exportado com sucesso!");
    } else {
        QMessageBox::warning(this, "Erro", "Não foi possível salvar o arquivo.");
    }
}

void MainWindow::on_exportar_pushButton_clicked()
{
    exportarCSV();
}

void MainWindow::checkWeatherForecast()
{
    QString apiKey = "6f0ac825b28eae56f29d6858168bc641"; // Substitua pela sua chave da API
    QString city = "Passo Fundo,BR";   // Substitua pela cidade desejada
    QString url = QString("https://api.openweathermap.org/data/2.5/weather?q=%1&appid=%2&units=metric&lang=pt_br")
                      .arg(city)
                      .arg(apiKey);
    // Usa o QNetworkAccessManager
    QNetworkRequest request((QUrl(url)));
    QNetworkReply *reply = networkManager->get(request);

    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
            QJsonObject obj = doc.object();

            if (obj.contains("weather")) {
                QJsonArray weatherArray = obj.value("weather").toArray();
                if (!weatherArray.isEmpty()) {
                    QString description = weatherArray.first().toObject().value("description").toString();
                    chuvaPrevista = description.contains("chuva", Qt::CaseInsensitive);

                    if (chuvaPrevista) {
                        ui->clima_label->setText("Previsão de chuva! Irrigação desativada automaticamente.");
                    } else {
                        ui->clima_label->setText("Sem previsão de chuva. Monitore o sistema.");
                    }
                }
            }
        } else {
            qDebug() << "Erro na API de clima:" << reply->errorString();
            chuvaPrevista = false; // Em caso de erro, assume que não há chuva prevista
            ui->clima_label->setText("Erro ao obter informações meteorológicas.");
        }

        reply->deleteLater();
    });
}
