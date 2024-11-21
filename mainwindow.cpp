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
    serial->setPortName("/dev/ttyACM0");  // Altere para o nome correto da porta
    serial->setBaudRate(QSerialPort::Baud9600);

    if (serial->open(QIODevice::ReadWrite)) {  // Mude para ReadWrite
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
    // Salva o valor atual do slider ao fechar o programa
    QSettings settings("save_last");
    settings.setValue("ultimoValorSlider", ui->porcento_horizontalSlider->value());

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

void MainWindow::readSerialData() {
    if (serial->canReadLine()) {
        QString line = serial->readLine();
        bool ok;
        int humidity = line.trimmed().toInt(&ok); // Parseia o valor
        if (ok) {
            ui->progressBar->setValue(humidity); // Atualiza o QProgressBar

            // Compara a umidade lida com o valor do QSlider
            int sliderValue = ui->porcento_horizontalSlider->value();
            if (humidity < sliderValue && (irrigacaoLigada == true)) {
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
        ui->irrigar_pushButton->setStyleSheet("color: lightgreen; font-weight: bold;"); // Cor do texto
    } else {
        ui->irrigar_pushButton->setText("Ligar a Irrigação");
        ui->irrigar_pushButton->setStyleSheet(""); // Reseta o estilo
    }
}
