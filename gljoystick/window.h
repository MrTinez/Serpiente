// Set it to only include once
#ifndef WINDOW_H
#define WINDOW_H
  
// A simple object for the window is just a generic widget
#include <QWidget>

// Class pre-declarations just to speed up compilation
class QSlider;
class GLWidget;

// Create a class for the window based on the generic QWidget
class Window : public QWidget{

// A bit of magic – Just put it here.
Q_OBJECT

public:
   // Default constructor
   Window();
private:
   // Part of the magic. This connects the event (changedSignal) 
   // to the handler (setterSlot) 
   QSlider *createSlider(const char *changedSignal, 
                         const char *setterSlot);
   // A gl Widget for the main object
   GLWidget *glWidget;
   // Three sliders to create manipulate the object.
   QSlider *xSlider;
   QSlider *ySlider;
   QSlider *zSlider;
   };
#endif
