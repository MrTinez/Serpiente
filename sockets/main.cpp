#include <QApplication>
#include "socket.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);  

	Socket *window = new Socket();
	window->show();

  return app.exec();
}
