

// Linux version from http://lgdc.sunsite.dk/articles/19.html

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include "joy.h"

//--------------------------------------------------------------------------
//                             Class Joystick
//--------------------------------------------------------------------------

// Linux version from http://lgdc.sunsite.dk/articles/19.html
#define JOY_DEV "/dev/input/js0"

Joystick::Joystick()
{
  axis = 0;
  button = 0;
}

Joystick::~Joystick()
{
}

bool Joystick::init()
{
  
  joy_fd = open( JOY_DEV , O_RDONLY);

  if( joy_fd != -1 )
  {

    ioctl( joy_fd, JSIOCGAXES, &num_of_axis );
    ioctl( joy_fd, JSIOCGBUTTONS, &num_of_buttons );
num_of_axis = 14;
num_of_buttons = 17;
#if 1
    axis = new int[num_of_axis];
    button = new char[num_of_buttons];

    fcntl( joy_fd, F_SETFL, O_NONBLOCK );	/* use non-blocking mode */
#endif
	printf( "Open joystick device %s\n", JOY_DEV);
	printf( "number of axis: %d\n", num_of_axis);
	printf( "number of buttons: %d\n", num_of_buttons);
		
    return true;
  }
  else
  {
	printf( "Couldn't open joystick device %s\n", JOY_DEV );
    return false;
  }
}

bool Joystick::GetStatus(JoystickStatus& js)
{
  js.x = js.y = js.z = js.i = js.i1 = js.i2 = js.i3 = js.i4 = js.i5 = js.i6 = js.i7 = js.i8 = js.i9 = js.i10 = 0;
  js.button1 = js.button2 = js.button3 = js.button4 = false;

  /* read the joystick state */
  while( read(joy_fd, &jse, sizeof(struct js_event))>0 )
  {

    /* see what to do with the event */
    switch (jse.type & ~JS_EVENT_INIT)
    {
      case JS_EVENT_AXIS:
        axis [ jse.number ] = jse.value;
        break;
      case JS_EVENT_BUTTON:
        button [ jse.number ] = jse.value;
        break;
    }
  }
  
  js.x = axis[0];
  js.y = axis[1];
  js.z = axis[2];
  js.i = axis[3];

  js.i1 = axis[4];
    js.i2 = axis[5];
      js.i3 = axis[6];
  js.i4 = axis[7];

  js.i5 = axis[8];
    js.i6 = axis[9];

  js.i7 = axis[10];
    js.i8 = axis[11];
  js.i9 = axis[12];
    js.i10 = axis[13];

              
  js.button1 = button[0] > 0;
  js.button2 = button[1] > 0;
  js.button3 = button[2] > 0;
  js.button4 = button[3] > 0;
  
  return true;
}

void Joystick::close()
{
  if( axis )
    delete [] axis;
  if( button )
    delete [] button;

  ::close( joy_fd );
}


