// LED.h

#ifndef LED_h

#define LED_h

#include "Arduino.h"





class LED{
    public:
      LED::LED();
      void init(int pin);
      void set(int value);
      void on();
      void off();
      int get();
      void LED::info();
      



    private:
      int myPin;
      int myValue;


};

#endif