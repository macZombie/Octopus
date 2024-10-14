// DRGB.h

#ifndef DRGB_h

#define DRGB_h

#include "Arduino.h"





class DRGB{
    public:
      DRGB::DRGB(int redPin, int greenPin, int bluePin );
      void setDRGB(int r, int g, int b );
      void test();
      void set(long colour);
      void setColourInt(int index);
     


    private:
      int myRedDPin;
      int myGreenDPin;
      int myBlueDPin;

      int myRedDValue;
      int myGreenDValue;
      int myBlueDValue;

      


};

#endif

