#include "stdio.h"
#include <QApplication>
 #include <QtNetwork>
#include "socket.h"
#include <QAbstractSocket>
#include <QTcpSocket>

Socket::Socket()
{
	setupUi(this);
	sock = NULL;
	
	connect(boton, SIGNAL(clicked()),  SLOT(conectar()));
}

Socket::~Socket()
{

}

void Socket::conectar()
{
	char  * data = "1\n";
	char * dataread;
	printf(data);
	sock = new QTcpSocket(this);
	sock->connectToHost("192.168.1.16",10001);
	sock->write(data, qstrlen(data));
	sock->read(dataread,sizeof(dataread));
	label_2->setText(QString(dataread));

}
