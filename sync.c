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

/*
Pin  declerations in broadcom pin numbers. 
I commented the numbers in wiring pi also. i think these are right
but i really have no freaking idea.
*/
#define sync_pin  13  //pin 5 on module (red)
#define data_pin  15 //pin 6 on module (white)
#define clock_pin 16 //14 //pin 7 on module. (blue)
#define test_pin 7
/*
Defined commands. 
*/
int led_cmd[10] = {0,0,1,0,0,0,0,1,0,0}; //init and center light
int anim_cmd[10] = {0,0,1,0,0,0,0,1,0,1}; //startup animation
int sync_cmd[10] = {0,0,0,0,0,0,0,1,0,0}; //sync process

/*
This is the part that gives a hard time. the data isn't being sent properly it seems.
*/
void sendData(int cmd_do[]){
	pinMode(data_pin, OUTPUT);
	digitalWrite(test_pin, LOW);
	digitalWrite(data_pin, LOW); //pull the data pin low to start sending the command...
	int prev = 1;
	int i;

	printf(" Sending cmd \n");
	for(i = 0; i < 10; i++){
		//printf("  Waiting for clock\n"); 
		//while (prev == digitalRead(clock_pin)){} //pause until there is a change in clock
		//prev = digitalRead(clock_pin);
		digitalWrite(data_pin, cmd_do[i]);

		//while (prev == digitalRead(clock_pin)){}
		//prev = digitalRead(clock_pin);

		}
	digitalWrite(data_pin, HIGH);
	pinMode(data_pin, INPUT);


}

/*
these two commands are just wrappers for the sendData command
*/
void initLEDs(){
	sendData(led_cmd);
	delay(50);
	sendData(anim_cmd);
	delay(50);
	}

void sync(){
	printf("=====Starting Sync Process=====\n");
	printf(" This doesn't work yet...\n");	
}


/*
main program and loop
*/
int main() 
{







printf("=====Initializing GPIO=====\n");
wiringPiSetup();

  //this is the setup portion of the arduino code
  pinMode(sync_pin, INPUT);
  printf("  sync_pin set as input\n");

  
  digitalWrite(sync_pin,HIGH);
  printf("  Setting sync_pin HIGH\n");

  
  pinMode(data_pin, INPUT);
  printf("  data_pin set as input\n");
  
  pinMode(clock_pin, INPUT);
  printf("  clock_pin set as input\n");

  pinMode(test_pin, OUTPUT);
  printf("  test_pin set as output\n");
  delay(2000);
printf("  testing led on\n");
digitalWrite(test_pin, HIGH);

printf("=====Starting LEDs=====\n");
  initLEDs();
//sendcmd(led_cmd);

//while(){
	printf("Waiting for Sync Button to be pressed...\n");
	while(digitalRead(sync_pin) != 1){
		//wait for the button to be pushed then start the sync.
		//i might put a cute little animation here for userspace execution of this program.
	}
	sync();
//}
return 0;

}
