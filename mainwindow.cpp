#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Configura o valor inicial da QLabel para o valor atual do QSlider
    int sliderValue = ui->porcento_horizontalSlider->value();
    ui->porcentagem_label->setText(QString::number(sliderValue) + "%");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_porcento_horizontalSlider_valueChanged(int value)
{
    // Atualiza o texto da QLabel para mostrar a porcentagem do slider
    ui->porcentagem_label->setText(QString::number(value) + "%");
}

