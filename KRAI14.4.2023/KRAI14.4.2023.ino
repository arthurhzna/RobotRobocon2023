//Slave Arduino Code:
//SPI SLAVE (ARDUINO)
//SPI COMMUNICATION BETWEEN TWO ARDUINO 
//CIRCUIT DIGEST
//Pramoth.T
#include<SPI.h>                             //Library for SPI 
#define LED 7           

#define RPWM0 28
#define LPWM0 26
#define PWM0 7

#define RPWM1 36
#define LPWM1 34
#define PWM1 5

#define RPWM2 32
#define LPWM2 30
#define PWM2 6

const int pEchA = 20; 
const int pEchB = 21; 

const int pEchA1 = 18; 
const int pEchB1 = 17; 

const int pEchA2 = 2; 
const int pEchB2 = 3; 

volatile long countPulses = 0;
const int TimeSampling = 30; //ms
unsigned long lastTime = 0;


volatile long countPulses1 = 0;
const int TimeSampling1 = 30; //ms
unsigned long lastTime1 = 0;
  

volatile long countPulses2 = 0;
const int TimeSampling2 = 30; //ms
unsigned long lastTime2 = 0;

unsigned long tigakali = 0;
float kp = 0.0005;//0,2
float ki = 0.2;
float kd = 3;

int errorb = 0;
int last_error = 0;
int sum_error = 0; 
int motorSpeed = 0; 

float kp1 = 0.0005;
float ki1 = 0.2;
float kd1 = 3;

int error1 = 0;
int last_error1 = 0;
int sum_error1 = 0; 
int motorSpeed1 = 0;


float kp2 = 0.0005;
float ki2 = 0.2;
float kd2 = 3;

int error2 = 0;
int last_error2 = 0;
int sum_error2 = 0; 
int motorSpeed2 = 0;


volatile boolean received;
volatile byte Slavereceived,Slavesend;
int x;
int sp;
int sp1;
int sp2;


void setup()
{
  Serial.begin(115200);              
  pinMode (RPWM0, OUTPUT);
  pinMode (PWM0, OUTPUT);
  pinMode (LPWM0, OUTPUT);
  pinMode (RPWM1, OUTPUT);
  pinMode (PWM1, OUTPUT);
  pinMode (LPWM1, OUTPUT);
  pinMode (RPWM2, OUTPUT);
  pinMode (PWM2, OUTPUT);
  pinMode (LPWM2, OUTPUT);

  
  pinMode(MISO,OUTPUT);                   //Sets MISO as OUTPUT (Have to Send data to Master IN 
  
  pinMode(pEchA, INPUT_PULLUP);
  pinMode(pEchB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pEchA), ISR_Encoder_A, RISING); //Rising Edge --> low to high

  pinMode(pEchA1, INPUT_PULLUP);
  pinMode(pEchB1, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pEchA1), ISR_Encoder_A1, RISING); //Rising Edge --> low to high

  pinMode(pEchA2, INPUT_PULLUP);
  pinMode(pEchB2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pEchA2), ISR_Encoder_A2, RISING); //Rising Edge --> low to high
  
  SPCR |= _BV(SPE);                       //Turn on SPI in Slave Mode
  received = false;
  SPI.attachInterrupt();                  //Interuupt ON is set for SPI commnucation
  Serial.println("START");
}
ISR (SPI_STC_vect)                        //Inerrrput routine function 
{
  Slavereceived = SPDR;         // Value received from master if store in variable slavereceived
  received = true;                        //Sets received as True 
}



void loop(){ 
if(received)                            //Logic to SET LED ON OR OFF depending upon the value recerived from master
{
  
    if(Slavereceived == 0)                   //Logic for setting the LED output depending upon value received from slave
  {
   Serial.println("UP");
      
  }
  if(Slavereceived == 1)                   //Logic for setting the LED output depending upon value received from slave
  {
   Serial.println("kanan");
    
  }
  if(Slavereceived == 2)                   //Logic for setting the LED output depending upon value received from slave
  {
   Serial.println("kiri");
  }
  if(Slavereceived == 3)                   //Logic for setting the LED output depending upon value received from slave
  {
    Serial.println("bawah");
  }
  if(Slavereceived == 8)                   //Logic for setting the LED output depending upon value received from slave
  {
    Serial.println("stop");
  stop();        
  }


//-----------------------------------------------------------------------------------------------------------------------------------//
  if(Slavereceived == 9)                   //Logic for setting the LED output depending upon value received from slave
  {
    Serial.println("RMAJUANALOG");
    g90();
  }
  if(Slavereceived == 10)                   //Logic for setting the LED output depending upon value received from slave
  {
    Serial.println("RMUNDURANALOG");
    g270();
  }
  if(Slavereceived == 11)                   //Logic for setting the LED output depending upon value received from slave
  {
    Serial.println("RKANANANALOG");
    g0();
    // g180();
  }
  if(Slavereceived == 12)                   //Logic for setting the LED output depending upon value received from slave
  {
    Serial.println("RKIRIANALOG");
    g180();
    // g0();
  }
  if(Slavereceived == 30)                   //Logic for setting the LED output depending upon value received from slave
  {
sp=50;
sp1=100;
sp2=50;
CW0();
CCW1();
CW2();
last_error = 0;
last_error1 = 0;
last_error2 = 0;
errorb = 0;
error1 = 0;
error2 = 0;
  }
  if(Slavereceived == 19)                   //Logic for setting the LED output depending upon value received from slave
  {
sp=100;
sp1=200;
sp2=100;
CW0();
CCW1();
CW2();
last_error = 0;
last_error1 = 0;
last_error2 = 0;
errorb = 0;
error1 = 0;
error2 = 0;
  }
  

//-----------------------------------------------------------------------------------------------------------------------------------//

  if(Slavereceived == 13)                   //Logic for setting the LED output depending upon value received from slave
  {
    Serial.println("RSerongKananAtas");
     g45();
        //  g225();
  }
  if(Slavereceived == 14)                   //Logic for setting the LED output depending upon value received from slave
  {
    Serial.println("RSerongKiriAtas");
    g135();
      //  g315();
  }
  if(Slavereceived == 15)                   //Logic for setting the LED output depending upon value received from slave
  {
    Serial.println("RSerongKananBawah");
    g315();
        // g135();
  }
  if(Slavereceived == 16)                   //Logic for setting the LED output depending upon value received from slave
  {
    Serial.println("RSerongKiriBawah");
    g225();
    // g45();
  }
  
//-----------------------------------------------------------------------------------------------------------------------------------//
  
  if(Slavereceived == 17)                   //Logic for setting the LED output depending upon value received from slave
  {
    Serial.println("RMAJUANALOGLAMBAT");
  g90l();
  }
  if(Slavereceived == 18)                   //Logic for setting the LED output depending upon value received from slave
  {
    Serial.println("RMUNDURANALOGLAMBAT");
    g270l();
  }
  // if(Slavereceived == 19)                   //Logic for setting the LED output depending upon value received from slave
  // {
  //   Serial.println("RKANANANALOGLAMBAT");
  //   g0l();
  // }
  if(Slavereceived == 20)                   //Logic for setting the LED output depending upon value received from slave
  {
    Serial.println("RKIRIANALOGLAMBAT");
    g180l();
  }
//-----------------------------------------------------------------------------------------------------------------------------------//

  if(Slavereceived == 21)                   //Logic for setting the LED output depending upon value received from slave
  {
    Serial.println("RSerongKananAtasLAMBAT");
  }
  if(Slavereceived == 22)                   //Logic for setting the LED output depending upon value received from slave
  {
    Serial.println("RSerongKiriAtasLAMBAT");
  }
  if(Slavereceived == 23)                   //Logic for setting the LED output depending upon value received from slave
  {
    Serial.println("RSerongKananBawahLAMBAT");
  }
  if(Slavereceived == 24)                   //Logic for setting the LED output depending upon value received from slave
  {
    Serial.println("RSerongKiriBawahLAMBAT");
  }
  
  
  
  
  
  
  if(Slavereceived == 25)                   //Logic for setting the LED output depending upon value received from slave
  {
    Serial.println("LMAJUANALOGLAMBAT");
  }
  if(Slavereceived == 26)                   //Logic for setting the LED output depending upon value received from slave
  {
    Serial.println("LMUNDURANALOGLAMBAT");
  }
  if(Slavereceived == 27)                   //Logic for setting the LED output depending upon value received from slave
  {
    Serial.println("LKANANANALOGLAMBAT");
putarkanan();

  }
  if(Slavereceived == 28)                   //Logic for setting the LED output depending upon value received from slave
  {
    Serial.println("LKIRIANALOGLAMBAT");
putarkiri();
  }




x = 20;
Slavesend=x;                             
SPDR = Slavesend;                           //Sends the x value to master via SPDR 
Serial.print(Slavereceived);Serial.print("\t");Serial.println(Slavesend);

Serial.print(countPulses);
Serial.print(countPulses1);
Serial.print(countPulses2);
  }
PID();}

