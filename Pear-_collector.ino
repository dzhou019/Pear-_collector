

 // Pear_Collector by Darren 
 
 

 
 

/*
 * Adapted from "Blink,"  The basic Arduino example.  
 * http://www.arduino.cc/en/Tutorial/Blink
 */
#include <MeggyJrSimple.h>    // Required code, line 1 of 2.
int screen [8][8]; 

int x=0;
int y=0;
int xpear = random(8);
int ypear = random(8);
int xdot = random(8);
int ydot = random(8);
int xwall = random(8);
int ywall = random(8);
int binary = 0;
int speed = 200;
int timer = 0;
int dir;
//int xgap = random(7-xwall);
int xgap = 2;
//int ygap = random(7-ywall);
int ygap = 4;
int direction;
boolean gotpear=true;
boolean generate=true;

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup(); 
  Serial.begin(9600);                    // Required code, line 2 of 2.
}

void loop()                     // run over and over again
{
                  
//  DrawPx(xwall,ywall,Orange);     // Spawwn random walls and have them make other walls                             
  int dir;
  int choice = random(2);  
  if (generate == true)
  {
    wall();
  }
  //Savescreen();
  
  DrawPx(xpear,ypear,Green); 
  DrawPx(xdot,ydot,Blue);
  update(); 
  
  // Have eaten pear
  if (ReadPx(xdot,ydot)==Green)
  {
   xpear=random(8);
   ypear=random(8);
   if (binary < 128)
   {
    binary = binary * 2 + 1;
   }
   else
   {
    binary = 0; 
    speed = 200;
   }
  } 
  
  SetAuxLEDs(binary);
  DisplayScreen();
  DisplaySlate();
  delay(speed);
  CheckButtonsDown();
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
void Savescreen()                     // Got from Mr.Kiang's Github
{
 for (int x = 0; x < 8; x++)
 {
  for (int y = 0; y < 8; x++)
  {
   screen[x][y] = ReadPx(x,y);      // create an array named screen
  }
 }  
}
void DisplayScreen()               // Mr. Kiang's rotate code used
{
  ClearSlate();
  for (int x = 0; x < 8; x++)
 {
  for (int y = 0; y < 8; x++)
  {
   screen[x][y] = ReadPx(x,y);
  }
 }
  
}
void PrintScreen()
{
 for (int x = 0; x < 8; x++)
 {
  for (int y = 0; y < 8; x++)
  {
   Serial.print(screen[x][y]);
   Serial.print(" ");
  }
  Serial.println();
 }
}

void wall()
{
  int choice = random(2);  
  if (choice == 1)
  {   
     dir = 0;
     {
      xgap = 8 - xwall;
      for (int i=0 ;i < xgap; i++)
      {
        DrawPx(xwall + i,ywall,Orange);
        Serial.print(xgap);
        Serial.print("  ");
        Serial.println(i);
      }
     }
  }   
  else
  {
     dir = 90;
     {
      ygap = 8 - ywall;
      for (int i=0; i< ygap; i++)
      DrawPx(xwall,ywall + i,Orange);
     }
  }

  generate=false;
}

