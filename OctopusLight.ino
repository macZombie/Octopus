
#include "./RGB.h"
#include "./colours.h"
#include "./DRGB.h"


static RGB head = RGB(42,44,46);
static RGB a = RGB(5,6,7);
static RGB b = RGB(8,9,10);

static DRGB c = DRGB(33,34,35);
static DRGB d = DRGB(23,24,25);
static DRGB e = DRGB(26,27,28);
static DRGB f = DRGB(29,30,31);

static RGB g = RGB(11,12,13);
static RGB h = RGB(2,3,4);


int analogPin = A0; 
int val = 0; 



void setAllRandom(){

  int r;
  
  r = random(1,7); a.setColourInt(r);
  r = random(1,7); b.setColourInt(r);
  r = random(1,7); c.setColourInt(r);
  r = random(1,7); d.setColourInt(r);
  r = random(1,7); e.setColourInt(r);
  r = random(1,7); f.setColourInt(r);
  r = random(1,7); g.setColourInt(r);
  r = random(1,7); h.setColourInt(r);




}





void setAll(long colour){

 a.set( colour       );
 b.set( colour       );
 c.set( colour       );
 d.set( colour       );
 e.set( colour       );
 f.set( colour       );
 g.set( colour       );
 h.set( colour       );

}

void walk(long colour,long background,int time){

  a.set(colour) ; delay (time);
  a.set(background) ; delay(time);
  b.set(colour) ; delay (time);
  b.set(background) ; delay(time);
  c.set(colour) ; delay (time);
  c.set(background) ; delay(time);
  d.set(colour) ; delay (time);
  d.set(background) ; delay(time);
  e.set(colour) ; delay(time);
  e.set(background) ; delay(time);
  f.set(colour) ; delay (time);
  f.set(background) ; delay(time);
  g.set(colour) ; delay (time);
  g.set(background) ; delay(time);
  h.set(colour) ; delay (time);
  h.set(background) ; delay(time);

}

void oldWalkToSound(long colour,long background,int time){

  a.set(colour) ; 	waitForSound(time);
  a.set(background) ; 	
  b.set(colour) ;	waitForSound(time);
  b.set(background) ; 
  c.set(colour) ; 	waitForSound(time);
  c.set(background) ; 	
  d.set(colour) ; 	waitForSound(time);
  d.set(background) ; 	
  e.set(colour) ; 	waitForSound(time);
  e.set(background) ; 	
  f.set(colour) ; 	waitForSound(time);
  f.set(background) ; 	
  g.set(colour) ; 	waitForSound(time);
  g.set(background) ; 	
  h.set(colour) ; 	waitForSound(time);
  h.set(background) ; 

}


void walkToSound(long colour,long background,int time){

  a.set(colour) ; 	waitForSound(time);
  a.set(background) ; 	waitForSound(time);
  b.set(colour) ;	waitForSound(time);
  b.set(background) ; 	waitForSound(time);
  c.set(colour) ; 	waitForSound(time);
  c.set(background) ; 	waitForSound(time);
  d.set(colour) ; 	waitForSound(time);
  d.set(background) ; 	waitForSound(time);
  e.set(colour) ; 	waitForSound(time);
  e.set(background) ; 	waitForSound(time);
  f.set(colour) ; 	waitForSound(time);
  f.set(background) ; 	waitForSound(time);
  g.set(colour) ; 	waitForSound(time);
  g.set(background) ; 	waitForSound(time);
  h.set(colour) ; 	waitForSound(time);
  h.set(background) ; 	waitForSound(time);

}

void walkBackwardsToSound(long colour,long background,int time){

  h.set(colour) ; 	waitForSound(time);
  h.set(background) ; 	waitForSound(time);
  g.set(colour) ;	waitForSound(time);
  g.set(background) ; 	waitForSound(time);
  f.set(colour) ; 	waitForSound(time);
  f.set(background) ; 	waitForSound(time);
  e.set(colour) ; 	waitForSound(time);
  e.set(background) ; 	waitForSound(time);
  d.set(colour) ; 	waitForSound(time);
  d.set(background) ; 	waitForSound(time);
  c.set(colour) ; 	waitForSound(time);
  c.set(background) ; 	waitForSound(time);
  b.set(colour) ; 	waitForSound(time);
  b.set(background) ; 	waitForSound(time);
  a.set(colour) ; 	waitForSound(time);
  a.set(background) ; 	waitForSound(time);

}







void swim(long colour,long background,int time){

  a.set(colour) ; 	
  h.set(colour) ; 	waitForSound(time);

  b.set(colour) ; 	
  g.set(colour) ; 	waitForSound(time);

  c.set(colour) ; 	
  f.set(colour) ; 	waitForSound(time);

  d.set(colour) ; 	
  e.set(colour) ; 	waitForSound(time);




  head.set(background) ; 	waitForSound(time);

}

long chooseColour(int x){

  long colour;

  switch(x){

    case 0: colour = RED; break;
    case 1: colour = GREEN; break;
    case 2: colour = BLUE; break;
    case 3: colour = LIGHT_BLUE; break;
    case 4: colour = VIOLET; break;
    case 5: colour = YELLOW; break;
    case 6: colour = BLACK; break;
    default: colour = WHITE; break;




  }


  return(colour);


}


void waitForSound( int timeout){

  int mic;
  
  int count;

  boolean delaying;

  mic = 0;

  count = 0;

  delaying = true;

  while(delaying){

    mic = analogRead(analogPin); 
      
    mic = mic - 76; // remove offset

   

    delay(50);



    count++;

    if ( ( count >= timeout)|| ( mic > 500 ) ){

      delaying = false;

    }



  }


  
  return;




}



void walkBoth(long colour,long background,int time){

  walkToSound(colour,background,time);
  walkBackwardsToSound(colour,background,time);

}


void phaseOne(){

 a.set( RED       );
 b.set( GREEN     );
 c.set( BLUE      );
 d.set( RED       );
 e.set( GREEN     );
 f.set( BLUE      );
 g.set( RED       );
 h.set( GREEN     );
 head.set( BLUE   );

 delay(1000);


}




void phaseTwo(){
  setAll(RED);
  head.set(GREEN);
  delay(1000);
  walkBoth(GREEN,RED,100);
  walkBoth(BLUE,RED,100);

  setAll(GREEN);
  head.set(RED);
  delay(1000);
  walkBoth(RED,GREEN,100);
  walkBoth(BLUE,GREEN,100);
  
  setAll(BLUE);
  head.set(GREEN);
  delay(1000);
  walkBoth(RED,BLUE,100);
  walkBoth(GREEN,BLUE,100);

  delay(1000);
  
}





void phaseThree(){


  setAll(RED);
  head.set(GREEN);
  delay(1000);
  walkToSound(GREEN,RED,100);
  walkToSound(BLUE,RED,100);

  setAll(GREEN);
  head.set(RED);
  delay(1000);
  walkToSound(RED,GREEN,100);
  walkToSound(BLUE,GREEN,100);
  
  setAll(BLUE);
  head.set(GREEN);
  delay(1000);
  walkToSound(RED,BLUE,100);
  walkToSound(GREEN,BLUE,100);

  delay(1000);

}



void phaseFour(){
  int x;

  for ( x = 0; x < 200 ; x++ ){

    setAllRandom();
    waitForSound(200);
    head.setColourInt(  random(1,7) );

  }

}


void phaseFive(){
   
  head.set(VIOLET);

  int x;

  for ( x = 0 ; x < 50; x++ ){

    setAll(RED);
    head.set(BLUE);
    waitForSound(400);
    setAll(GREEN);
    head.set(RED);
    waitForSound(400);
    setAll(BLUE);
    head.set(GREEN);
    waitForSound(400);
    setAll(VIOLET);
    head.set(RED);
    waitForSound(400);

  }





}

void phaseSix(){

  setAll(RED);
  head.set(GREEN);
  delay(1000);
  swim(GREEN,RED,100);
  swim(BLUE,RED,100);

  setAll(GREEN);
  head.set(RED);
  delay(1000);
  swim(RED,GREEN,100);
  swim(BLUE,GREEN,100);
  
  setAll(BLUE);
  head.set(GREEN);
  delay(1000);
  swim(RED,BLUE,100);
  swim(GREEN,BLUE,100);

  delay(1000);


}



void setup() {

  setAll(WHITE);
  
  head.set(WHITE);
  
  delay(500);

}





void loop() {

  int x;

  //head.fade();


  phaseOne();

  phaseFour(); // random

  phaseTwo();

  phaseFour(); // random

  phaseThree();

  phaseFour(); // random

  phaseFive();

  phaseFour(); // random

  phaseSix();

  phaseFour(); // random


  

}