
#include "MainFrame.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);  

  MainFrame *window =  new MainFrame();
   window->show();


  return app.exec();
}
