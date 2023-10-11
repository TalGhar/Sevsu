#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QLineEdit"
#include "QTextEdit"
#include "QDateEdit"
#include "QLayout"
#include "QLabel"
#include "QPushButton"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //ui->setupUi(this);

    setWindowTitle("News poster");

    // Title LineEdit and Label vertical box
    newsTitle = new QLineEdit();
    QLabel *titleLabel = new QLabel("Title");
    QVBoxLayout *titleVLayout = new QVBoxLayout();
    titleVLayout->addWidget(titleLabel);
    titleVLayout->addWidget(newsTitle);

    // Text TextEdit and Label vertical box
    newsText = new QTextEdit();
    QLabel *textLabel = new QLabel("Text");
    QVBoxLayout *textVLayout = new QVBoxLayout();
    titleVLayout->addWidget(textLabel);
    titleVLayout->addWidget(newsText);

    // Text and Title vertical box
    QVBoxLayout *titleAndTextVLayout = new QVBoxLayout();
    titleAndTextVLayout->addLayout(titleVLayout);
    titleAndTextVLayout->addLayout(textVLayout);

    // Date DateEdit and Label vertical box
    newsDate = new QDateEdit();
    QLabel *dateLabel = new QLabel("Date");
    QVBoxLayout *dateVLayout = new QVBoxLayout();
    dateVLayout->addWidget(dateLabel);
    dateVLayout->addWidget(newsDate);

    // Date box and PushButton vertical box
    postNews = new QPushButton("Post");
    QVBoxLayout *dateAndConfirmVLayout = new QVBoxLayout();
    dateAndConfirmVLayout->addStretch(60);
    dateAndConfirmVLayout->addLayout(dateVLayout);
    dateAndConfirmVLayout->addWidget(postNews);
    dateAndConfirmVLayout->addStretch(60);

    QHBoxLayout *formHLayout = new QHBoxLayout();
    formHLayout->addLayout(titleAndTextVLayout);
    formHLayout->addLayout(dateAndConfirmVLayout);

    // Table
    table = new QTableWidget(0,3);
    table->setShowGrid(false);
    table->setHorizontalHeaderLabels({"Title", "Text", "Date"});

    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(postNews, SIGNAL(clicked()), this, SLOT(onPushClick()));

    QVBoxLayout *centralLayout = new QVBoxLayout();
    centralLayout->addLayout(formHLayout);
    centralLayout->addWidget(table);

    QWidget *centralWidget = new QWidget();
    centralWidget->setLayout(centralLayout);
    this->setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
    //delete ui;
}

void MainWindow::onPushClick()
{
    int currentRowsCount = table->rowCount();
    table->insertRow(currentRowsCount);
    table->setItem(currentRowsCount, 0, new QTableWidgetItem(newsTitle->text()));
    table->setItem(currentRowsCount, 1, new QTableWidgetItem(newsText->toPlainText()));
    table->setItem(currentRowsCount, 2, new QTableWidgetItem(newsDate->date().toString("yyyy.MM.dd")));
}
