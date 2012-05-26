
#ifndef __JOYSTICK_H
#define __JOYSTICK_H

//--------------------------------------------------------------------------
//                           I N C L U D E
//--------------------------------------------------------------------------

#ifndef WIN32 // Linux
#include "linux/joystick.h"
#endif

//--------------------------------------------------------------------------
//                             Class Joystick
//--------------------------------------------------------------------------

// a common structure for 2 axes and 4 buttons
typedef struct
{
  int x;
  int y;
  int z;
  int i;

  int i1;
  int i2;
  int i3;
  int i4;

  int i5;
  int i6;

  int i7;
  int i8;
  int i9;
  int i10;
  
  bool button1;
  bool button2;
  bool button3;
  bool button4;
} JoystickStatus;

/* This class gives access to a joystick under Win32 and Linux.
 * 2 axes and 4 buttons are used at the moment.
 */
class Joystick
{
private:

#ifndef WIN32
  int joy_fd, num_of_axis, num_of_buttons;
  int* axis;
  char* button;
  struct js_event jse;
#endif

public:

  Joystick();
  virtual ~Joystick();

  bool init();
  bool GetStatus(JoystickStatus& js);
  void close();
};

#endif  // __JOYSTICK_H


