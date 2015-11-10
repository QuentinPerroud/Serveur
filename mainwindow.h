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
   void connexion(QString s2);

   void deconnexion(QString s1);

   void  Echange(QString s1 ,QString s2,QString s3);

private slots:
     void readPendingDatagrams();

private:
    Ui::MainWindow *ui;
    QUdpSocket* soc;
    QMap<QString,QHostAddress> tbl;
    QMap<QString,QHostAddress>::iterator it;
};

#endif // MAINWINDOW_H
