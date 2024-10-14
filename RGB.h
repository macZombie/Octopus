// RGB.h

#ifndef RGB_h

#define RGB_h

#include "Arduino.h"





class RGB{
    public:
      RGB::RGB(int redPin, int greenPin, int bluePin );
      void setRGB(int r, int g, int b );
      void set(long colour);
      void makeColour(float ratio);
      void setSolid(int value); 
      void setGrayCode(int value);
      void fade();
      
      void solid();
      void gray();
      void demo();
      void flash(int period);
      void setColourInt(int index);
      


    private:
      int myRedPin;
      int myGreenPin;
      int myBluePin;

      int myRedValue;
      int myGreenValue;
      int myBlueValue;

      


};

#endif

