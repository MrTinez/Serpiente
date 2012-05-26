#include <QtGui>
// Need to include glwidget (the one we will create next)
#include "glwidget.h"
// Include the header for this window
#include "window.h"
// The constructor for this window

Window::Window()
{
   // Add the OpenGL widget
   glWidget = new GLWidget;
 
   // Create three sliders to control the X, Y, and Z rotation 
   // and connect their changed event (SIGNAL) 
   // to the proper handler function (SLOT)
   xSlider = createSlider(SIGNAL(xRotationChanged(int)),
                          SLOT(setXRotation(int)));
   ySlider = createSlider(SIGNAL(yRotationChanged(int)),
                          SLOT(setYRotation(int)));
   zSlider = createSlider(SIGNAL(zRotationChanged(int)),
                          SLOT(setZRotation(int)));

   // Create a horizontal layout box 
   // (container for all the widgets)
   QHBoxLayout *mainLayout = new QHBoxLayout;

   // Add each of the widgets
   mainLayout->addWidget(glWidget);
   mainLayout->addWidget(xSlider);
   mainLayout->addWidget(ySlider);
   mainLayout->addWidget(zSlider);

   // Set the layout box as the main object
   setLayout(mainLayout);

   // And give some initial values
   xSlider->setValue(15 * 16);
   ySlider->setValue(345 * 16);
   zSlider->setValue(0 * 16);
   setWindowTitle(tr("Hello GL"));
}

//Function that creates the sliders
QSlider *Window::createSlider(const char *changedSignal, 
                              const char *setterSlot)
{
   QSlider *slider = new QSlider(Qt::Vertical);
   slider->setRange(0, 360 * 16);
   slider->setSingleStep(16);
   slider->setPageStep(15 * 16);
   slider->setTickInterval(15 * 16);
   slider->setTickPosition(QSlider::TicksRight);
   connect(slider, SIGNAL(valueChanged(int)), 
                   glWidget, setterSlot);
   connect(glWidget, changedSignal, slider, 
                     SLOT(setValue(int)));
   return slider;
}
