#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->helloButton, &QPushButton::clicked,
            this, &MainWindow::displayHello);
    connect(ui->holaButton, &QPushButton::clicked,
            this, &MainWindow::onHolaClicked);
    bonjourConnection = connect(ui->bonjourButton, &QPushButton::clicked,
            [this](){ui->plainTextEdit->appendPlainText(QString("Bonjour!"));});
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayHello()
{
    ui->plainTextEdit->appendPlainText(QString("Hello!"));
}

void MainWindow::onHolaClicked()
{
    ui->plainTextEdit->appendPlainText(QString("Hola!"));
    disconnect(ui->helloButton, &QPushButton::clicked, this, &MainWindow::displayHello);
    disconnect(bonjourConnection);
}
