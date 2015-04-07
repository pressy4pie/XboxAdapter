/*
Adapted from yaywoop and Alexander Martinex and dilandou by Connor Rigby
5/7/15

on original xbox 360 rf board:
pins 1-4 will be usb. step pin one down to 3.3 volts for power.
pin 2 and 3 are white and green d- & d+ and pin 4 is ground.

pins 5-7 will be plugged into the gpio header.
pin 5 is the power button and will be repurposed for sync.
pin 6 is data
pin 7 is clock

Don't forget to get a common ground also.
This program requires wiringPi be installed.
*/

#include <wiringPi.h>
#include <stdio.h>

#define sync_pin 21  //pin 5 on module (red)
#define data_pin 20 //pin 6 on module (white)
#define clock_pin 26 //pin 7 on module. (blue)

int led_cmd[10] = {0,0,1,0,0,0,0,1,0,0}; //init and center light
int anim_cmd[10] = {0,0,1,0,0,0,0,1,0,1}; //startup animation
int sync_cmd[10] = {0,0,0,0,0,0,0,1,0,0}; //sync process

void sleepMS(int msecs){
	usleep(ms*1000); //convert to microseconds
	return;
}

void sendData(int cmd_do[]){
	pinMode(data_pin, OUTPUT);
	digitalWrite(data_pin, 0);
	int prev = 1;
	for(int = 0; i < 10; i++){
		while (prev == digitalRead(clock_pin)){} //pause until there is a change in clock
		prev = digitalRead(clock_pin);
		digitalWrite(data_pin, cmd_do[i]);

		while (prrrev == digitalRead(clock_pin)){}
		prev = digitalRead(clock_pin);

		}
	digitalWrite(data_pin, 1);
	pinMode(data_pin, INPUT);
	}
	
void initLEDs(){
	sendData(led_cmd);
	sleepMS(50);
	sendData(anim_cmd);
	sleepMS(50);
	}

int main (void) 
{
  //this is the setup portion of the arduino code
  pinMode(sync_pin, INPUT);
  digitalWrite(sync_pin,1);
  pinMode(data_pin, INPUT);
  pinMode(clock_pin, INPUT);
  sleepMS(2000); //2 seconds
  
  initLEDs();
	
	
	return 0;

}
