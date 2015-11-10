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

   void  echange(QString s1 ,QString s2,QString s3);

private slots:
     void readPendingDatagrams();

     void on_clear_clicked();

private:
    Ui::MainWindow *ui;
    QUdpSocket* soc;
    QMap<QString,QHostAddress> tbl;
    QMap<QString,QHostAddress>::iterator it;
     QHostAddress sender  ;
};

#endif // MAINWINDOW_H
