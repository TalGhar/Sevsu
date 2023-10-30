/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGridLayout *gridLayout;
    QPushButton *getButton;
    QPushButton *postButton;
    QLabel *urlLabel;
    QLineEdit *urlLine;
    QLabel *dataLabel;
    QLineEdit *dataLine;
    QPushButton *submitButton;
    QPushButton *resetButton;
    QLabel *responseTitleLabel;
    QTextBrowser *textBrowser;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(360, 530);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        getButton = new QPushButton(centralWidget);
        getButton->setObjectName(QString::fromUtf8("getButton"));

        gridLayout->addWidget(getButton, 0, 0, 1, 1);

        postButton = new QPushButton(centralWidget);
        postButton->setObjectName(QString::fromUtf8("postButton"));

        gridLayout->addWidget(postButton, 0, 2, 1, 1);

        urlLabel = new QLabel(centralWidget);
        urlLabel->setObjectName(QString::fromUtf8("urlLabel"));

        gridLayout->addWidget(urlLabel, 1, 0, 1, 1);

        urlLine = new QLineEdit(centralWidget);
        urlLine->setObjectName(QString::fromUtf8("urlLine"));

        gridLayout->addWidget(urlLine, 1, 1, 1, 2);

        dataLabel = new QLabel(centralWidget);
        dataLabel->setObjectName(QString::fromUtf8("dataLabel"));

        gridLayout->addWidget(dataLabel, 2, 0, 1, 1);

        dataLine = new QLineEdit(centralWidget);
        dataLine->setObjectName(QString::fromUtf8("dataLine"));

        gridLayout->addWidget(dataLine, 2, 1, 1, 2);

        submitButton = new QPushButton(centralWidget);
        submitButton->setObjectName(QString::fromUtf8("submitButton"));

        gridLayout->addWidget(submitButton, 3, 0, 1, 1);

        resetButton = new QPushButton(centralWidget);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));

        gridLayout->addWidget(resetButton, 3, 2, 1, 1);

        responseTitleLabel = new QLabel(centralWidget);
        responseTitleLabel->setObjectName(QString::fromUtf8("responseTitleLabel"));

        gridLayout->addWidget(responseTitleLabel, 4, 0, 1, 1);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        gridLayout->addWidget(textBrowser, 4, 1, 1, 2);


        verticalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\"\n"
"\"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\"> p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; textindent:0px;\"><span style=\" font-size:10pt; fontweight:600;\">Http Get and\n"
"Post</span></p></body></html>", nullptr));
        getButton->setText(QCoreApplication::translate("MainWindow", "Get", nullptr));
        postButton->setText(QCoreApplication::translate("MainWindow", "Post", nullptr));
        urlLabel->setText(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\"\n"
"\"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2';\n"
"font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px;\n"
"margin-left:0px; margin-right:0px; -qt-block-indent:0; text-\n"
"indent:0px;\">Enter Url</p></body></html>", nullptr));
        dataLabel->setText(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\"\n"
"\"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\"> p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-\n"
"indent:0px;\"><span style=\" font-size:8pt;\">Enter\n"
"Data</span></p></body></html>", nullptr));
        submitButton->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        responseTitleLabel->setText(QCoreApplication::translate("MainWindow", "Response", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
