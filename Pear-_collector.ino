

 // Pear_Collector by Darren 
 
 

 
 

/*
 * Adapted from "Blink,"  The basic Arduino example.  
 * http://www.arduino.cc/en/Tutorial/Blink
 */
#include <MeggyJrSimple.h>    // Required code, line 1 of 2.
int x=0;
int y=0;
int xpear = random(8);
int ypear = random(8);
int xdot = random(8);
int ydot = random(8);
int speed = 350;
int timer = 0;
int direction;
boolean gotpear=true;
void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
}

void loop()                     // run over and over again
{
  DrawPx(xpear,ypear,Green); 
  DrawPx(xdot,ydot,Blue);
  while (xpear == xdot && ypear == ydot)
  {      
    xdot = random(8);
    ydot = random(8);
  }
  DisplaySlate();
  delay(speed);
  CheckButtonsPress();
  ClearSlate();
   if (Button_Right)
  {
    direction=90;
  }
  if (Button_Up)
  {
     direction=0;
  }
  if (Button_Down)
  {
     direction=180;
  }
  if (Button_Left)
  {
     direction=270;
  }
  
 
}

void update()
{
// Move dot
if (direction == 0)
{
  ydot = ydot+1
  if (ydot >7)
  {
    ydot=0:
  } 
}
if (direction == 90)
{
  xdot = xdot+1
  if (xdot >7)
  {
    xdot=0;
  }
}
if (direction == 180)
{
  ydot= ydot-1
  if (ydot <0)
  {
   ydot=7; 
  }
}
if (direction == 270)
{
  xdot= xdot-1;
  if (xdot <0)
  {
    xdot=7;
  }
}
}
