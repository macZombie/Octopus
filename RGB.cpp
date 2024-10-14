// RGB.cpp

#include "Arduino.h"
#include "RGB.h"
#include "colours.h"



int myRedPin;
int myGreenPin;
int myBluePin;

int myRedValue;
int myGreenValue;
int myBlueValue;



RGB::RGB(int rPin, int gPin , int bPin ){

  myRedPin = rPin;
  myGreenPin = gPin;
  myBluePin = bPin;

  myRedValue = 0;
  myGreenValue = 0;
  myBlueValue = 0;

  pinMode(rPin,OUTPUT);
  pinMode(gPin,OUTPUT);
  pinMode(bPin,OUTPUT);

  analogWrite(myRedPin,myRedValue);
  analogWrite(myGreenPin,myGreenValue);
  analogWrite(myBluePin,myBlueValue);

}

void RGB::setRGB(int r, int g, int b ){


  myRedValue = r;
  myGreenValue = g;
  myBlueValue = b;

  analogWrite(myRedPin,myRedValue);
  analogWrite(myGreenPin,myGreenValue);
  analogWrite(myBluePin,myBlueValue);

}

void RGB::set(long colour){

  int r;
  int g;
  int b;


  r = ( colour & 0XFF0000 ) >> 16;
  g = ( colour & 0X00FF00 ) >> 8;
  b = ( colour & 0X0000FF );


  setRGB(r,g,b);



}



void RGB::makeColour(float ratio){


    unsigned long top;
    long slots;
    long boundary;
    long value;


    unsigned long upper;
    unsigned long lower;
    long phase;
    long index;
    float local;

    long red;
    long green;
    long blue;
    
    float position;

    top = 0XFFFFFF; // this is the 24 bpp range 
    slots = 7;      // this is the number of colour windows 

    boundary = top / slots; //the width of a colour window 


    value = 0XFFFFFF * ratio;


    for ( index = 0; index < slots; index++ ){

        lower = index * boundary;

        upper = lower + boundary;


        if ( ( value >= lower ) && ( value < upper ) ){
            phase = index ;  //which window 
        }


    } /// for index


    position = value - ( phase * boundary );

    local = position / boundary ;

    switch(phase){

        case 0: red = local * 255         ; green = 0                     ; blue = 0              ; break;  // black to red
        case 1: red = 255                 ; green = local * 255           ; blue = 0              ; break;  // red to yellow
        case 2: red = 255 - (local * 255) ; green = 255                   ; blue = 0              ; break;  // yellow to green
        case 3: red =  0                  ; green = 255                   ; blue = local * 255    ; break;  // green to cyan
        case 4: red =  0                  ; green = 255 - ( local * 255 ) ; blue = 255            ; break;  // cyan to blue
        case 5: red = local * 255         ; green = 0                     ; blue = 255            ; break;  // blue to purple
        case 6: red = 255                 ; green = local * 255           ; blue = 255            ; break;  // purple to white
        default: red = 0;  green = 0      ; blue = 0; break;


    } // switch index 


    setRGB( red, green, blue );


    return;

}


void RGB::setSolid(int value){


  int r;
  int g;
  int b;

  switch(value){

    case 0: b = 0 ; g = 0 ; r = 0 ; break;
	  case 1: b = 0 ; g = 0 ; r = 1 ; break;
	  case 2: b = 0 ; g = 1 ; r = 0 ; break;
	  case 3: b = 0 ; g = 1 ; r = 1 ; break;
	  case 4: b = 1 ; g = 0 ; r = 0 ; break;
	  case 5: b = 1 ; g = 0 ; r = 1 ; break;
	  case 6: b = 1 ; g = 1 ; r = 0 ; break;
	  case 7: b = 1 ; g = 1 ; r = 1 ; break;
    default: b = 1 ; g = 1 ; r = 1 ; break;


   

  } // switch value

  setRGB(r * 255, g * 255, b * 255);





}


void RGB::setGrayCode(int value){

  int ledValue;
  int gray[] = { 0 , 1 , 3 , 2 , 6, 7 , 5 , 4 };
  int *pGray;

  pGray = &gray[0];

  if ( value > 7 ){
    value = 7;
  }

  if ( value < 0 ){
    value = 0;
  }


  ledValue = pGray[value];

  setSolid(ledValue);

}




void RGB::fade(){

  float index;


    for ( index = 0.0 ; index < 1.0; index = index + 0.001 ){

      makeColour(index);

      delay(4);

    }


    for ( index = 0.99999 ; index > 0.0; index = index - 0.001 ){

      makeColour(index);

     delay(5);

   }

  


}


void RGB::solid(){

  int solid;

  for ( solid = 0; solid <= 7; solid++){

    setSolid(solid);

    delay(2000);

  }



}

void RGB::gray(){

  int solid;

  for ( solid = 0; solid <= 7; solid++){

    setGrayCode(solid);

    delay(2000);

  }

}

void RGB::demo(){

  int del = 500;

  setRGB(255,0,0);

  delay(del);

  setRGB(0,255,0);

  delay(del);

  setRGB(0,0,255);

  delay(del);

  setRGB(0,0,0);

  delay(del);

}


void RGB::flash(int period){

  set(0XFFFFFF);
  delay(period);
  set(0X000000);
  delay(period);





}






void RGB::setColourInt(int index){

  switch(index){	
    case(0): set(BLACK); break;
	  case(1): set(BLUE); break;
	  case(2): set(GREEN); break;
	  case(3): set(LIGHT_BLUE); break;
	  case(4): set(RED); break;
	  case(5): set(VIOLET); break;
	  case(6): set(YELLOW); break;
	  case(7): set(WHITE); break;
    default: break;
  }

}


