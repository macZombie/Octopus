// LED.cpp

#include "LED.h"

int myPin;

LED::LED(){


}

void LED::init(int pin){

  myPin = pin;

  pinMode(myPin, OUTPUT);



  myValue = 0;

  info();


}

void LED::set(int value){

  analogWrite(myPin,value);

  myValue = value;

}

void LED::on(){
  set(255);
}

void LED::off(){
  set(0);
}

int LED::get(){

  int value;

  value = myValue;

  return(value);

}


void LED::info(){

  Serial.println("\n");
  Serial.print("myPin = ");
  Serial.println(myPin);

  int value;

  value = myValue;

  return(value);

}
