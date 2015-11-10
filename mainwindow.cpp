#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    soc = new QUdpSocket (this);
    soc->bind(QHostAddress("0.0.0.0"), 1234);

        connect(soc, SIGNAL(readyRead()),
                this, SLOT(readPendingDatagrams()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readPendingDatagrams()
{
   while (soc->hasPendingDatagrams()) {
       QByteArray datagram;
       datagram.resize(soc->pendingDatagramSize());

       quint16 senderPort ;
       soc->readDatagram(datagram.data(), datagram.size(),
                               &sender, &senderPort);

       QString er1QString;
       QString eme2QString;
       QString eme3QString;
       QDataStream ds(datagram);
       ds >> er1QString >> eme2QString >> eme3QString;



       //traitement de la connexion
        if (er1QString=="")
        {
              connexion(eme2QString);
        }
        else if (eme2QString=="")
        {
              deconnexion(er1QString);
        }
        else
        {
              echange(er1QString,eme2QString,eme3QString);
        }



   }
}

void MainWindow::connexion(QString s2)
{



        if(tbl.find(s2)!= tbl.end())
        {

            QByteArray ba;
            QDataStream ds2(&ba,QIODevice::WriteOnly);
            ds2 << QString ("Vous etes déja connecté !")  ;
            soc->writeDatagram(ba,sender,1234);

        }
        else{
            tbl[s2]=sender;
            ui->Affichage->append(s2 + " est connecté son IP est : "+sender.toString());
            QByteArray ba;
            QDataStream ds2(&ba,QIODevice::WriteOnly);
            ds2 << QString ("Bienvenue " + s2)  ;
            soc->writeDatagram(ba,sender,1234);
        }
   }


void MainWindow::deconnexion(QString s1)
{

}

void MainWindow::echange(QString s1 ,QString s2,QString s3)
{
        if(tbl.find(s1)!= tbl.end())
        {
             if(tbl.find(s2)!= tbl.end())
             {
                 QByteArray ba;
                 QDataStream ds3(&ba,QIODevice::WriteOnly);
                 ds3 << QString (s1 + " : " + s3)  ;
                 soc->writeDatagram(ba,tbl[s2],1234);
             }
        }
}

void MainWindow::on_clear_clicked()
{

    ui->listepseudo->clear();
}
