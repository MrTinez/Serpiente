// The basic application include file
#include <QApplication> 
#include "window.h"



int main(int argc, char *argv[])
   {
    // Constructor for the application and initialize it with 
    //the argument vector
    QApplication app(argc, argv);
    
    // Create an instance of your main window
  
    Window window;

    // Set it to be displayed
    window.show();
   


    
    // Return the return value from your application when 
    // it is finished
    return app.exec();
}
