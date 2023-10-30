#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtSql>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void delete_student();
    void edit_student();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlTableModel *db_model;
};
#endif // MAINWINDOW_H
