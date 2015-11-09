#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <qdatastream>
#include <qstring>
#include <QMap>

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
     void readPendingDatagrams();

private:
    Ui::MainWindow *ui;
    QUdpSocket* soc;
};

#endif // MAINWINDOW_H
