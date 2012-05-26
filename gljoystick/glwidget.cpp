#include <QtGui>
#include <QtOpenGL>
#include <math.h>
#include "glwidget.h"
#include <stdio.h>

GLWidget::GLWidget(QWidget *parent)
  : QGLWidget(parent)
{
	RaphaelJoy = NULL;
  // Start off at no rotation
  xRot = 0;
  yRot = 0;
  zRot = 0;
  
    Ticker = new QTimer(this);
    connect(Ticker,   SIGNAL(timeout()),       SLOT(slot_Ticker()));
    Ticker->start( 0.1 );
}

GLWidget::~GLWidget()
{
  // Delete anything you have created
}

QSize GLWidget::minimumSizeHint() const
{
  return QSize(50, 50);
}

QSize GLWidget::sizeHint() const
{
  return QSize(400, 400);
}

void GLWidget::setXRotation(int angle)
{
  normalizeAngle(&angle);
  if (angle != xRot) {
    xRot = angle;
    emit xRotationChanged(angle);
    updateGL();
  }
}


void GLWidget::setYRotation(int angle)
{
  normalizeAngle(&angle);
  if (angle != yRot) {
    yRot = angle;
    emit yRotationChanged(angle);
    updateGL();
  }
}


void GLWidget::setZRotation(int angle)
{
  normalizeAngle(&angle);
  if (angle != zRot) {
    zRot = angle;
    // tell everyone we have changed the angle
    emit zRotationChanged(angle);
    updateGL();
  }
}


void GLWidget::initializeGL()
{
  // Set the way we want things to look
  glShadeModel(GL_FLAT);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
}

void GLWidget::paintGL()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glTranslated(0.0, 0.0, -10.0);
  glRotated(xRot / 16.0, 1.0, 0.0, 0.0);
  glRotated(yRot / 16.0, 0.0, 1.0, 0.0);
  glRotated(zRot / 16.0, 0.0, 0.0, 1.0);
  // A basic square to impress all your friends
  glBegin(GL_LINE_LOOP);
     glVertex3d(0,0,0);
     glVertex3d(1,0,0);
     glVertex3d(1,1,0);
     glVertex3d(0,1,0);
  glEnd();
}


void GLWidget::resizeGL(int width, int height)
{
  int side = qMin(width, height);
  glViewport((width - side) / 2, (height - side) / 2, side, side);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.5, +1.5, +1.5, -1.5, 4.0, 15.0);
  glMatrixMode(GL_MODELVIEW);
}


/*void GLWidget::mousePressEvent(QMouseEvent *event)
{
  lastPos = event->pos();
}*/


/*void GLWidget::mouseMoveEvent(QMouseEvent *event)
{

  int dx = event->x() - lastPos.x();
  int dy = event->y() - lastPos.y();
  if (event->buttons() & Qt::LeftButton) {
    setXRotation(xRot + 8 * dy);
    setYRotation(yRot + 8 * dx);
  } else if (event->buttons() & Qt::RightButton) {
    setXRotation(xRot + 8 * dy);
    setZRotation(zRot + 8 * dx);
  }
  lastPos = event->pos();
}*/
   
   
void GLWidget::slot_Ticker()
{
	if(!RaphaelJoy) 
	{ 
	  RaphaelJoy = new Joystick(); 
	  if(RaphaelJoy->init() == false)
	  { 
               printf("\nJoystick not detected"); exit(1);  
          }
	}

	RaphaelJoy->GetStatus(js);
	printf("\n%d %d %d %d   X   %d %d %d %d   X   %d %d   X   %d %d %d %d ",js.x,js.y,js.z,js.i,   js.i1,js.i2,js.i3,js.i4,  js.i5,js.i6,    js.i7,js.i8,js.i9,js.i10 );

        char buff[50];
        
	sprintf(buff,"%d",js.x);
	
      

		if(fabs(js.y) > 10)
			setXRotation(xRot + 1 * (js.y/32767) * 90);
		if(fabs(js.x) > 10)
    		setYRotation(yRot + 1 * (js.x/32767) * 90);
    	if(fabs(js.z) > 10)	
    		setZRotation(zRot + 1 * (((32767 + js.z)/32767) * 90));

}

void GLWidget::normalizeAngle(int *angle)
{
  while (*angle < 0)
    *angle += 360 * 16;
  while (*angle > 360 * 16)
    *angle -= 360 * 16;
}
