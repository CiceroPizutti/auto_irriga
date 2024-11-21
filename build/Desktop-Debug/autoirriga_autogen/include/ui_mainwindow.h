/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *umidade_label;
    QProgressBar *progressBar;
    QLabel *ativar_status_label;
    QSlider *porcento_horizontalSlider;
    QLabel *porcentagem_label;
    QPushButton *irrigar_pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(740, 420);
        MainWindow->setIconSize(QSize(23, 23));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        umidade_label = new QLabel(centralwidget);
        umidade_label->setObjectName(QString::fromUtf8("umidade_label"));
        QFont font;
        font.setPointSize(14);
        umidade_label->setFont(font);

        verticalLayout->addWidget(umidade_label);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        verticalLayout->addWidget(progressBar);

        ativar_status_label = new QLabel(centralwidget);
        ativar_status_label->setObjectName(QString::fromUtf8("ativar_status_label"));
        ativar_status_label->setFont(font);

        verticalLayout->addWidget(ativar_status_label);

        porcento_horizontalSlider = new QSlider(centralwidget);
        porcento_horizontalSlider->setObjectName(QString::fromUtf8("porcento_horizontalSlider"));
        QFont font1;
        font1.setPointSize(20);
        porcento_horizontalSlider->setFont(font1);
        porcento_horizontalSlider->setMaximum(100);
        porcento_horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(porcento_horizontalSlider);

        porcentagem_label = new QLabel(centralwidget);
        porcentagem_label->setObjectName(QString::fromUtf8("porcentagem_label"));
        QFont font2;
        font2.setPointSize(21);
        font2.setBold(true);
        porcentagem_label->setFont(font2);

        verticalLayout->addWidget(porcentagem_label, 0, Qt::AlignHCenter);

        irrigar_pushButton = new QPushButton(centralwidget);
        irrigar_pushButton->setObjectName(QString::fromUtf8("irrigar_pushButton"));

        verticalLayout->addWidget(irrigar_pushButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 740, 18));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        umidade_label->setText(QCoreApplication::translate("MainWindow", "Umidade do Solo:", nullptr));
        ativar_status_label->setText(QCoreApplication::translate("MainWindow", "Ativar irriga\303\247\303\243o quando umidade for menor que (%)", nullptr));
        porcentagem_label->setText(QString());
        irrigar_pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
