#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString DBpath = "student.db";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DBpath);

    if(db.open()){
        QMessageBox msgBox;
        msgBox.setText("Connected");
        msgBox.exec();
    }
    else
    {
        QMessageBox::critical(this,tr("SQLite connection"), tr("Unable connect to DB."));
        exit(1);
    }

    db_model = new QSqlTableModel(this, db);
    db_model->setTable("Student");
    db_model->setEditStrategy(QSqlTableModel::OnFieldChange);
    db_model->select();

    ui->tableView->setModel(db_model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(ui->pushButton, SIGNAL(clicked()), SLOT(edit_student()));
    connect(ui->pushButton_2, SIGNAL(clicked()), SLOT(delete_student()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::delete_student()
{
    QModelIndexList ids = ui->tableView->selectionModel()->selection().indexes();
    QSet<int> *rowsToDelete = new QSet<int>();
    for (int i = 0; i < ids.count(); i++)
    {
        QModelIndex id = ids.at(i);
        rowsToDelete->insert(id.row());
    }

    QAbstractItemModel *model = ui->tableView->model();
    QSet<int>::iterator i;
    for (i = rowsToDelete->begin(); i != rowsToDelete->end(); ++i)
    {
        model->removeRow(*i);
    }
}

void MainWindow::edit_student()
{
    QModelIndex currentIndex = ui->tableView->currentIndex();
    if (currentIndex.isValid())
    {
        ui->tableView->edit(currentIndex);
    }
}
