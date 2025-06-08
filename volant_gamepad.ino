#include <Joystick.h>

Joystick_ joystick;//create Joystick called "joystick"

const int potentiometer=A0;//potentiometer wired on analogic pin 0 (wired on 5v)
const int power1=A1;
const int power2=A2;
const int power3=A3;
const int power4=A4;
const int power5=A5;
const int thrust_l=0;
const int thrust_r=1;
const int L2=2;
const int L3=3;
const int R2=4;
const int R3=5;
const int croix=6;
const int carre=7;
const int triangle=8;
const int rond=9;
const int PS=10;
const int options=11;
const int share=12;

int p_axis=0;
int joyxaxis=0;
int joyyaxis=0;

void setup() {
  Serial.begin(9600);

  pinMode(power1,OUTPUT);
  pinMode(power2,OUTPUT);
  pinMode(power3,OUTPUT);
  pinMode(power4,OUTPUT);
  pinMode(power5,OUTPUT);
  pinMode(thrust_l,INPUT_PULLUP);
  pinMode(thrust_r,INPUT_PULLUP);
  pinMode(L2,INPUT_PULLUP);
  pinMode(L3,INPUT_PULLUP);
  pinMode(R2,INPUT_PULLUP);
  pinMode(R3,INPUT_PULLUP);
  pinMode(croix,INPUT_PULLUP);
  pinMode(carre,INPUT_PULLUP);
  pinMode(triangle,INPUT_PULLUP);
  pinMode(rond,INPUT_PULLUP);
  pinMode(PS,INPUT_PULLUP);
  pinMode(options,INPUT_PULLUP);
  pinMode(share,INPUT_PULLUP);

  joystick.begin();//false mean you need to call a function to refresh a value
}

void loop() {
  //Joystick left
  p_axis=analogRead(potentiometer);//get potentiometer analogic value
  p_axis=map(p_axis,62,800,0,255);//joystick works from 0 to 255, I remap p_axis to the joystick range
  p_axis=constrain(p_axis,0,255);//if steering wheel turned too strong
  Serial.println(p_axis);
  
  joystick.setXAxis(p_axis);//set right joystick x axis to p_axis 

  if (digitalRead(thrust_l)==LOW)
  {joystick.pressButton(0);}
  else
  {joystick.releaseButton(0);}

  if (digitalRead(thrust_r)==LOW)
  {joystick.pressButton(1);}
  else
  {joystick.releaseButton(1);}

  if (digitalRead(L2)==LOW)
  {joystick.pressButton(2);}
  else
  {joystick.releaseButton(2);}

  if (digitalRead(L3)==LOW)
  {joystick.pressButton(3);}
  else
  {joystick.releaseButton(3);}

  if (digitalRead(R2)==LOW)
  {joystick.pressButton(4);}
  else
  {joystick.releaseButton(4);}

  if (digitalRead(R3)==LOW)
  {joystick.pressButton(5);}
  else
  {joystick.releaseButton(5);}

  if (digitalRead(croix)==LOW)
  {joystick.pressButton(6);}
  else
  {joystick.releaseButton(6);}

  if (digitalRead(carre)==LOW)
  {joystick.pressButton(7);}
  else
  {joystick.releaseButton(7);}

  if (digitalRead(triangle)==LOW)
  {joystick.pressButton(8);}
  else
  {joystick.releaseButton(8);}

  if (digitalRead(rond)==LOW)
  {joystick.pressButton(9);}
  else
  {joystick.releaseButton(9);}

  if (digitalRead(PS)==LOW)
  {joystick.pressButton(10);}
  else
  {joystick.releaseButton(10);}

  if (digitalRead(options)==LOW)
  {joystick.pressButton(11);}
  else
  {joystick.releaseButton(11);}

  if (digitalRead(share)==LOW)
  {joystick.pressButton(12);}
  else
  {joystick.releaseButton(12);}

  delay(50);
}
