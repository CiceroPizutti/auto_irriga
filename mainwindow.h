#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer> // Para ler o valor periodicamente
#include <QDebug>

#include <QMainWindow>

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
    void readSerialData();  // Declaração do método
    void on_irrigar_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    QTimer *timer;
    bool irrigacaoLigada;
};
#endif // MAINWINDOW_H
