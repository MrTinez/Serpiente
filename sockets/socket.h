#ifndef SOCKET_H
#define SOCKET_H


#include <QWidget>
#include <QAbstractSocket>
#include <QTcpSocket>
#include <QtNetwork>
#include "ui_main.h"
 
class Socket : public QMainWindow,  public Ui_MainWindow
{
	Q_OBJECT
	public:
		Socket();
		~Socket();
		
			QTcpSocket *sock;
			
			
	private slots:
		void conectar();
};




#endif
