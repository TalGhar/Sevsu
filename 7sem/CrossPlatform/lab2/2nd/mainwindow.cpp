#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(changeTitle()));
    connect(ui->plainTextEdit, SIGNAL(textChanged()), this, SLOT(replaceALetters()));
    connect(ui->plainTextEdit_2, SIGNAL(textChanged()), this, SLOT(countStars()));
    connect(ui->label_count, SIGNAL(isLimit()), this, SLOT(setDisabled()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeTitle()
{
    ui->lineEdit->text().size() ? QWidget::setWindowTitle(ui->lineEdit->text()) : QWidget::setWindowTitle(" ");
}

void MainWindow::replaceALetters()
{
    ui->plainTextEdit_2->setPlainText(ui->plainTextEdit->toPlainText().replace("a","*").replace('A','*'));
}

void MainWindow::countStars()
{
    ui->label_count->setText(QString("Total number of *'s: %0").arg(ui->plainTextEdit_2->toPlainText().count('*')));
    if (ui->plainTextEdit_2->toPlainText().count('*') >= 10) {emit ui->label_count->isLimit();};
}

void MainWindow::setDisabled()
{
    ui->plainTextEdit->setReadOnly(true);
    ui->label_count->setText("You've reached the limit of typing a's");
}
