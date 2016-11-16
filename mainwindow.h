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

public slots:
    void displayHello();
    void onHolaClicked();

private:
    Ui::MainWindow *ui;
    QMetaObject::Connection bonjourConnection;
};

#endif // MAINWINDOW_H
