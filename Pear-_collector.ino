

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
int xbomb = random(8);            // Draws out the enemy bomb
int ybomb = random(8);
int xwall = random(8);
int ywall = random(8);
int speed = 200;
int timer = 0;
int dir;
//int xgap = random(7-xwall);
int xgap = 2;
//int ygap = random(7-ywall);
int ygap = 5;
int direction;
boolean gotpear=true;
void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup(); 
  Serial.begin(9600);                    // Required code, line 2 of 2.
}

void loop()                     // run over and over again
{
                  
  DrawPx(xwall,ywall,Orange);     // Spawwn random walls and have them make other walls                             
  int dir;
  int choice = random(2);  
  if (choice == 1)   
     dir = 0;
     {
      for (int i=0 ;i < xgap; i++)
      {
        DrawPx(xwall + i,ywall,Orange);
        Serial.print(xgap);
        Serial.print("  ");
        Serial.println(i);
      }
     }   
  if (choice == 2)
     dir = 90;
     {
      for (int i=0; i< ygap; i++)
      DrawPx(xwall,ywall + i,Orange);
     }
  DrawPx(xpear,ypear,Green); 
  DrawPx(xdot,ydot,Blue);
  DrawPx(xbomb,ybomb,Red);

  
  if (xpear == xdot && ypear == ydot)        
  {      
    xdot = random(8);        
    ydot = random(8);
  }
  if (xpear == xbomb && ypear == ybomb)      
  {
    xbomb = random(8);
    ybomb = random(8);                         
  }
  if (xdot == xbomb && ydot == ybomb)
  {
    xdot = random(8);
    ydot = random(8);
  }
 
  
  // Have eaten pear
  if (ReadPx(xdot,ydot)==Green)
  {
    xpear=random(8);
    ypear=random(8);
  }
  update();            
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
  ydot = ydot+1;
  if (ydot >7)
  {
    ydot=0;
  } 
}
if (direction == 90)
{
  xdot = xdot+1;
  if (xdot >7)
  {
    xdot=0;
  }
}
if (direction == 180)
{
  ydot= ydot-1;
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
