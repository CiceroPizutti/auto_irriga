#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>
#include <QDebug>
#include <QMainWindow>
#include <QVector>
#include <QPair>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QFileDialog>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_porcento_horizontalSlider_valueChanged(int value);
    void readSerialData();
    void on_irrigar_pushButton_clicked();
    void on_exportar_pushButton_clicked(); // Novo slot para exportar
    void checkWeatherForecast(); // Slot para verificar previsão do tempo

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    QTimer *timer;
    QTimer weatherTimer; // Timer para checar previsão do tempo
    bool irrigacaoLigada;
    bool chuvaPrevista = false; // Indica se há previsão de chuva

    QNetworkAccessManager *networkManager; // Gerenciador de requisições de rede
    QVector<QPair<QDateTime, int>> historicoUmidade; // Histórico de dados do sensor

    void exportarCSV(); // Método para exportar histórico
};

#endif // MAINWINDOW_H
