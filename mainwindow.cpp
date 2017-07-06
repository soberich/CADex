#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnTetraedr_clicked()
{
   ui->stageWidget->pickedTetraedr();
   ui->textBrowser->setText("Tetraedr\nNumber of triangles: 4");
}

void MainWindow::on_btnHexsaedr_clicked()
{
    ui->stageWidget->pickedHexaedr();
    ui->textBrowser->setText("Hexsaedr\nNumber of triangles: 12");
}

void MainWindow::on_btnOctaedr_clicked()
{
    ui->stageWidget->pickedOctaedr();
    ui->textBrowser->setText("Parallelepiped\nNumber of triangles: 12");
}
