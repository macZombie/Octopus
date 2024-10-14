// DRGB.cpp

#include "Arduino.h"
#include "DRGB.h"



int myRedDPin;
int myGreenDPin;
int myBlueDPin;

int myRedDValue;
int myGreenDValue;
int myBlueDValue;



DRGB::DRGB(int rPin, int gPin , int bPin ){

  myRedDPin = rPin;
  myGreenDPin = gPin;
  myBlueDPin = bPin;

  myRedDValue = 0;
  myGreenDValue = 0;
  myBlueDValue = 0;

  pinMode(rPin,OUTPUT);
  pinMode(gPin,OUTPUT);
  pinMode(bPin,OUTPUT);

  //analogWrite(myRedPin,myRedValue);
  //analogWrite(myGreenPin,myGreenValue);
  //analogWrite(myBluePin,myBlueValue);

}

void DRGB::setDRGB(int r, int g, int b ){


  myRedDValue = r;
  myGreenDValue = g;
  myBlueDValue = b;


  if ( myRedDValue == 0 ){
    digitalWrite(myRedDPin,LOW);
  }else{
    digitalWrite(myRedDPin,HIGH);
  }

  if ( myGreenDValue == 0 ){
    digitalWrite(myGreenDPin,LOW);
  }else{
    digitalWrite(myGreenDPin,HIGH);
  }

  if ( myBlueDValue == 0 ){
    digitalWrite(myBlueDPin,LOW);
  }else{
    digitalWrite(myBlueDPin,HIGH);
  }


  //analogWrite(myRedPin,myRedValue);
  //analogWrite(myGreenPin,myGreenValue);
  //analogWrite(myBluePin,myBlueValue);

}

void DRGB::test(){
  digitalWrite(myRedDPin   ,HIGH);
  digitalWrite(myGreenDPin ,LOW); 
  digitalWrite(myBlueDPin ,LOW); 
  delay(200);
  digitalWrite(myRedDPin   ,LOW);
  digitalWrite(myGreenDPin ,HIGH); 
  digitalWrite(myBlueDPin ,LOW); 
  delay(200);
  digitalWrite(myRedDPin   ,LOW);
  digitalWrite(myGreenDPin ,LOW); 
  digitalWrite(myBlueDPin ,HIGH); 
  delay(200);

  digitalWrite(myRedDPin   ,HIGH);
  digitalWrite(myGreenDPin ,HIGH); 
  digitalWrite(myBlueDPin ,HIGH); 
  delay(200);


}


void DRGB::set(long colour){


  int r;
  int g;
  int b;


  r = ( colour & 0XFF0000 ) >> 16;
  g = ( colour & 0X00FF00 ) >> 8;
  b = ( colour & 0X0000FF );


  setDRGB(r,g,b);


}


void DRGB::setColourInt(int index){

  switch(index){	
    case(0): setDRGB(0,0,0); break;
	  case(1): setDRGB(0,0,1); break;
	  case(2): setDRGB(0,1,0); break;
	  case(3): setDRGB(0,1,1); break;
	  case(4): setDRGB(1,0,0); break;
	  case(5): setDRGB(1,0,1); break;
	  case(6): setDRGB(1,1,0); break;
	  case(7): setDRGB(1,1,1); break;
    default: break;
  }

}





