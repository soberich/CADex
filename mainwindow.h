#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_btnTetraedr_clicked();

    void on_btnHexsaedr_clicked();

    void on_btnOctaedr_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
