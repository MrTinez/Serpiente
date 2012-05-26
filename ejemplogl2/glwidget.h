// Only include once
#ifndef GLWIDGET_H
#define GLWIDGET_H
// base class for the GLWidget
#include <QGLWidget>


class GLWidget : public QGLWidget
{
   // Magic stuff here
   Q_OBJECT
public:
   // Constructor and destructor
   GLWidget(QWidget *parent = 0);
   ~GLWidget();

   //Basic setup
   QSize minimumSizeHint() const;
   QSize sizeHint() const;

   // The holders for the values for the rotation
   int xRotation() const { return xRot; }
   int yRotation() const { return yRot; }
   int zRotation() const { return zRot; }

// Not really C++ but these are the handler functions 
// for the events
public slots:
   void setXRotation(int angle);
   void setYRotation(int angle);
   void setZRotation(int angle);

// And these are the messages that connect to the previous 
// handlers
signals:
   void xRotationChanged(int angle);
   void yRotationChanged(int angle);
   void zRotationChanged(int angle);
   protected:
   void initializeGL();
   void paintGL();
   void resizeGL(int width, int height);
   void mousePressEvent(QMouseEvent *event);
   void mouseMoveEvent(QMouseEvent *event);
   void normalizeAngle(int *angle);
   GLuint object;
   int xRot;
   int yRot;
   int zRot;
   QPoint lastPos;
};
#endif
