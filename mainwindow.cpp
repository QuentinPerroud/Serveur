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
       QHostAddress sender  ;
       quint16 senderPort ;
       soc->readDatagram(datagram.data(), datagram.size(),
                               &sender, &senderPort);

       QString er1QString;
       QString eme2QString;
       QString eme3QString;
       QDataStream ds(datagram);
       ds >> er1QString >> eme2QString >> eme3QString;

   }
}
