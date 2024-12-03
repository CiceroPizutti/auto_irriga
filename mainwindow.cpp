#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSettings>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , irrigacaoLigada(false) // Inicializa a irrigação como desligada
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
    serial->setPortName("/dev/ttyACM2");  // Altere para o nome correto da porta
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
}

MainWindow::~MainWindow()
{
    // Removido o código de salvamento automático do histórico de umidade
    // QSettings settings("save_last");
    // settings.setValue("ultimoValorSlider", ui->porcento_horizontalSlider->value());

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
            if (humidity < sliderValue && irrigacaoLigada) {
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

        // Cabeçalho
        stream << "Data/Hora,Umidade (%)\n";

        // Dados
        for (const auto &entry : historicoUmidade) {
            stream << entry.first.toString("yyyy-MM-dd HH:mm:ss") << "," << entry.second << "\n";
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
