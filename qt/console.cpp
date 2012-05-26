#include <QApplication>
#include <QDesktopWidget>
#include <QWidget>
#include <QPushButton>


class MyButton : public QWidget
{
 public:
     MyButton(QWidget *parent = 0);
};

void center(QWidget *widget, int w, int h)
{
  int x, y;
  int screenWidth;
  int screenHeight;

  QDesktopWidget *desktop = QApplication::desktop();

  screenWidth = desktop->width();
  screenHeight = desktop->height();
 
  x = (screenWidth - w) / 2;
  y = (screenHeight - h) / 2;

  widget->move( x, y );
}

MyButton::MyButton(QWidget *parent)
    : QWidget(parent)
{
  int WIDTH = 250;
  int HEIGHT = 150;

  setFixedSize(WIDTH, HEIGHT);

  QPushButton *quit = new QPushButton("Quit", this);
  quit->setGeometry(50, 40, 75, 30);

  center(this, WIDTH, HEIGHT);

  connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
}


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);  

  MyButton window;

  window.setWindowTitle("button");
  window.show();

  return app.exec();
}
