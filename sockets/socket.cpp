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
	QString qString1 = text_mensaje->text();
	QByteArray byteArray = qString1.toUtf8();
	char * data =  byteArray.data();
	char * dataread;
	printf("Evento");
	printf(data);
	sock = new QTcpSocket(this);
	sock->connectToHost("192.168.1.16",10001);
	sock->write(data, qstrlen(data));
	sock->read(dataread,sizeof(dataread));
	label_2->setText(QString(dataread));

}
