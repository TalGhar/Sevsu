#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "QTableWidget"
#include "QPushButton"
#include "QTextEdit"
#include "QDateEdit"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPushButton *postNews;
    QTableWidget *table;
    QTextEdit *newsText;
    QLineEdit *newsTitle;
    QDateEdit *newsDate;

private slots:
    void onPushClick();
};
#endif // MAINWINDOW_H
