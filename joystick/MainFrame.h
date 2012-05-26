#ifndef MAINFRAME_H
#define MAINFRAME_H

#include "joy.h"
#include "ui_main.h"

#include <QWidget>


class MainFrame : public QMainWindow,  public Ui_MainWindow
{
  Q_OBJECT  

  public:
    MainFrame();
      ~MainFrame();

        Joystick *RaphaelJoy;
        QTimer *Ticker;
       	JoystickStatus js;

private slots:
	void slot_Ticker();
};

#endif
