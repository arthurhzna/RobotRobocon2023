//Master Arduino Code:

//SPI MASTER (ARDUINO)

//SPI COMMUNICATION BETWEEN TWO ARDUINO 

//CIRCUIT DIGEST
#include<SPI.h>
#include <PS2X_lib.h>
PS2X ps2x;
#define RPWM0 30
#define LPWM0 31
#define PWM0 5

#define RPWM1 32
#define LPWM1 33
#define PWM1 6
int x;
int error;
byte type = 0;
byte vibrate = 0;

#define Se1 27
#define Se2 25

int kondisiSE1 = 0;
int kondisiSE2 = 0;

int kondisiPE = 0;


#define RPWL1 45
#define LPWL1 49
#define PWML1 7

#define RPWPE 35
#define LPWPE 39
#define PWMPE 4

#define sudut1 41
#define sudut2 43
#define PWMsudut 6

void setup (void)
{
  Serial.begin(115200);                   //Starts Serial Communication at Baud Rate 115200 
                   
// selenoid 
pinMode (Se1, OUTPUT);
pinMode (Se2, OUTPUT);

pinMode (RPWL1, OUTPUT);
pinMode (LPWL1, OUTPUT);
pinMode (PWML1, OUTPUT);


pinMode (RPWPE, OUTPUT);
pinMode (LPWPE, OUTPUT);
pinMode (PWMPE, OUTPUT);


  SPI.begin();                            //Begins the SPI commnuication
  SPI.setClockDivider(SPI_CLOCK_DIV8);    //Sets clock for SPI communication at 8 (16/8=2Mhz)
  digitalWrite(SS,HIGH);                  // Setting SlaveSelect as HIGH (So master doesnt connnect with slave)
  while (true) {
    error = ps2x.config_gamepad(13, 11, 10, 12, true, true);
    Serial.println("Error = " + String(error));
    if (error == 0){break;}
    else if (error == 1){Serial.println("No controller found");}
    else if (error > 1){ Serial.println("Controller found but not accepting commands");}
  }
  Serial.println("Found Controller, configured successful");
  digitalWrite(Se1,LOW);
  digitalWrite(Se2,LOW);
}
void loop(void)
{
  byte Mastersend,Mastereceive;          
  if (error == 1) 
    return;
    
    else { //DualShock Controller
    Ldiam();
     x=8; 
    analogWrite(PWMPE, 0);
    digitalWrite (RPWPE, LOW);
    digitalWrite (LPWPE, LOW);
    digitalWrite (sudut1,LOW);
    digitalWrite (sudut2,LOW);
    analogWrite(PWMsudut,0);
    digitalWrite(Se1,HIGH);
    digitalWrite(Se2,HIGH);
    ps2x.read_gamepad(false, vibrate);
    //Serial.print(ps2x.Analog(PSS_LY));Serial.print("\t");
    //Serial.print(ps2x.Analog(PSS_LX));Serial.print("\t");
    ///Serial.print(ps2x.Analog(PSS_RY));Serial.print("\t");
    //Serial.print(ps2x.Analog(PSS_RX));Serial.println("\t");
  
//-----------------------------------------------------------------------------------------------------------------------------------//
    if (ps2x.Button(PSB_PAD_UP)) {
      //Serial.println("UP");
      x=0;
      //Serial.println("UP");
      
    }
     if (ps2x.Button(PSB_PAD_RIGHT)) {//belakang
      //Serial.println("KANAN");
      x=1;
    analogWrite(PWMPE, 80);
    digitalWrite (RPWPE, LOW);
    digitalWrite (LPWPE, HIGH);
    }
     if (ps2x.Button(PSB_PAD_LEFT)) {//depan
      //Serial.println("KIRI");
      x=2;
    analogWrite(PWMPE, 180);
    digitalWrite (RPWPE, LOW);
    digitalWrite (LPWPE, HIGH);
      } 
     if (ps2x.Button(PSB_PAD_DOWN)) {
      Serial.println("DOWN");
      x=3;
      analogWrite(PWMPE, 80);
      digitalWrite (RPWPE, HIGH);
      digitalWrite (LPWPE, LOW);
      }

     if ((ps2x.Button(PSB_CROSS)) && (ps2x.Button(PSB_PAD_RIGHT))){
      Serial.println("lempar");
      digitalWrite(Se1,LOW);
      // x=4;
//      if (kondisiSE1 == 0) {
//        digitalWrite(Se1,HIGH);
//        kondisiSE1 = 1;
//      }
//      else {
//        digitalWrite(Se1,LOW);
//        kondisiSE1 = 0;
//      }
    }

    if ((ps2x.Button(PSB_CROSS)) && (ps2x.Button(PSB_PAD_LEFT))){
      Serial.println("lempar1");
      digitalWrite(Se2,LOW);
      // x=4;
//      if (kondisiSE1 == 0) {
//        digitalWrite(Se1,HIGH);
//        kondisiSE1 = 1;
//      }
//      else {
//        digitalWrite(Se1,LOW);
//        kondisiSE1 = 0;
//      }
    }
//-----------------------------------------------------------------------------------------------------------------------------------//
      
   if (ps2x.Button(PSB_CIRCLE)){
      Serial.println("CIRCLE");
      digitalWrite(Se1,LOW);
      // x=4;
//      if (kondisiSE1 == 0) {
//        digitalWrite(Se1,HIGH);
//        kondisiSE1 = 1;
//      }
//      else {
//        digitalWrite(Se1,LOW);
//        kondisiSE1 = 0;
//      }
    }
     if (ps2x.Button(PSB_CROSS)){
       Serial.println("CROSS");
       digitalWrite(Se2,LOW);
       // x=5;
//       if (kondisiSE2 == 0) {
//        digitalWrite(Se2,HIGH);
//        kondisiSE2 = 1;
//      }
//      else {
//        digitalWrite(Se2,LOW);
//        kondisiSE2 = 0;
//      }
     }
     if (ps2x.Button(PSB_TRIANGLE)){
      Serial.println("TRIANGLE");
      // x=6;
      
    }
    if (ps2x.Button(PSB_SQUARE)){
      Serial.println("SQUARE");
      // x=7;
     
    }
//-----------------------------------------------------------------------------------------------------------------------------------//


     if ( (ps2x.Analog(PSS_RY) <= 10) && (ps2x.Analog(PSS_RX) >= 118) && (ps2x.Analog(PSS_RX) <= 138))                  //MAJU LEFT
    {
      //Serial.println("RMAJUANALOG"); 
      //maju();
      x=9;
    }
    if ( (ps2x.Analog(PSS_RY) >= 245) && (ps2x.Analog(PSS_RX) >= 118) && (ps2x.Analog(PSS_RX) <= 138))                 //MUNDUR LEFT
    {
      //Serial.println("RMUNDURANALOG");
      //mundur();
       x=10;
    }
    // if ( (ps2x.Analog(PSS_RY) >= 118) && (ps2x.Analog(PSS_RY) <= 138) && (ps2x.Analog(PSS_RX) >= 245))                 //putarkanan RIGHT
    // {
    //   //Serial.println("RKANANANALOG");
    //   //kanan();
    //    x=11;
    // }
   if ( (ps2x.Analog(PSS_RY) >= 118) && (ps2x.Analog(PSS_RY) <= 138) && (ps2x.Analog(PSS_RX) <= 10))                  //putarkiri RIGHT
    {
      //Serial.println("RKIRIANALOG");
      //kiri();
      x=12;
    }
//// test kanan 
    if ( (ps2x.Analog(PSS_RY) >= 118) && (ps2x.Analog(PSS_RY) <= 138) && (ps2x.Analog(PSS_RX) >= 245))                 //putarkanan RIGHT
    {
      //Serial.println("RKANANANALOG");
      //kanan();
       x=30;
    }   
        if ( (ps2x.Analog(PSS_RY) >= 118) && (ps2x.Analog(PSS_RY) <= 138) && (ps2x.Analog(PSS_RX) >= 129) && (ps2x.Analog(PSS_RX) < 245))                 //putarkanan RIGHT
    {
      //Serial.println("RKANANANALOG");
      //kanan();
       x=11;
    } 

//-----------------------------------------------------------------------------------------------------------------------------------//

    if ( (ps2x.Analog(PSS_RX) > 138) && (ps2x.Analog(PSS_RY) < 118))                  //SERONG KANAN ATAS LEFT
    {
      //Serial.println("RSerongKananAtas");
      //serongkananatas();
      x=13;
    }
    if ( (ps2x.Analog(PSS_RY) < 118) && (ps2x.Analog(PSS_RX) < 118))                   //SERONG KIRI ATAS LEFT
    {
      //Serial.println("RSerongKiriAtas");
      //serongkiriatas();
      x=14;
    }   
    if ( (ps2x.Analog(PSS_RY) > 128) && (ps2x.Analog(PSS_RX) <= 255)&& (ps2x.Analog(PSS_RX) > 128) )                  //SERONG KIRI BAWAH LEFT
    {
      //Serial.println("RSerongKananBawah");
      //serongkananbawah();
       x=15;
    }
    if ( (ps2x.Analog(PSS_RY) > 138) && (ps2x.Analog(PSS_RX) < 118))                 //SERONG KANAN BAWAH LEFT
    {  
      //Serial.println("RSerongKiriBawah");
      //serongkiribawah();
      x=16;
    }
//-----------------------------------------------------------------------------------------------------------------------------------//


    if ((ps2x.Analog(PSS_RY) <= 10) && (ps2x.Analog(PSS_RX) >= 118) && (ps2x.Analog(PSS_RX) <= 138) && ps2x.Button(PSB_PAD_UP)  )                //MAJU LEFT
    {
      //Serial.println("RMAJUANALOGLAMBAT"); 
      //maju();
      x=17;
    }
    if ( (ps2x.Analog(PSS_RY) >= 245) && (ps2x.Analog(PSS_RX) >= 118) && (ps2x.Analog(PSS_RX) <= 138) && (ps2x.Button(PSB_PAD_UP)))                 //MUNDUR LEFT
    {
      //Serial.println("RMUNDURANALOGLAMBAT");
      //mundur();
       x=18;
    }
    if ( (ps2x.Analog(PSS_RY) >= 118) && (ps2x.Analog(PSS_RY) <= 138) && (ps2x.Analog(PSS_RX) >= 245) && (ps2x.Button(PSB_PAD_UP)))                 //putarkanan RIGHT
    {
      //Serial.println("RKANANANALOGLAMBAT");
      //kanan();
       x=19;
    }
    if ( (ps2x.Analog(PSS_RY) >= 118) && (ps2x.Analog(PSS_RY) <= 138) && (ps2x.Analog(PSS_RX) <= 10) && (ps2x.Button(PSB_PAD_UP)))                  //putarkiri RIGHT
    {
      //Serial.println("RKIRIANALOGLAMBAT");
      //kiri();
      x=20;
    }
    if ( (ps2x.Analog(PSS_RX) > 138) && (ps2x.Analog(PSS_RY) < 118) && (ps2x.Button(PSB_PAD_UP)))                  //SERONG KANAN ATAS LEFT
    {
      //Serial.println("RSerongKananAtasLAMBAT");
      //serongkananatas();
      x=21;
    }
    if ( (ps2x.Analog(PSS_RY) < 118) && (ps2x.Analog(PSS_RX) < 118) && (ps2x.Button(PSB_PAD_UP)))                   //SERONG KIRI ATAS LEFT
    {
      //Serial.println("RSerongKiriAtasLAMBAT");
      //serongkiriatas();
      x=22;
    }   
    if ( (ps2x.Analog(PSS_RY) > 128) && (ps2x.Analog(PSS_RX) <= 255)&& (ps2x.Analog(PSS_RX) > 128) && (ps2x.Button(PSB_PAD_UP)))                  //SERONG KIRI BAWAH LEFT
    {
      //Serial.println("RSerongKananBawahLAMBAT");
      //serongkananbawah();
       x=23;
    }
    if ((ps2x.Analog(PSS_RY) > 138) && (ps2x.Analog(PSS_RX) < 118)&& (ps2x.Button(PSB_PAD_UP)))                 //SERONG KANAN BAWAH LEFT
    {
      //Serial.println("RSerongKiriBawahLAMBAT");
      //serongkiribawah();
      x=24;
    }

    
//-----------------------------------------------------------------------------------------------------------------------------------//




     if ( (ps2x.Analog(PSS_LY) < 55) && (ps2x.Analog(PSS_LX) > 98) && (ps2x.Analog(PSS_LX) < 158) )                  //MAJU LEFT
    {
      //Serial.println("LMAJUANALOGLAMBAT");
      x=25;
    }   
     if ( (ps2x.Analog(PSS_LY) > 200) && (ps2x.Analog(PSS_LX) > 98) && (ps2x.Analog(PSS_LX) < 158) )                 //MUNDUR LEFT
    {
      //Serial.println("LMUNDURANALOGLAMBAT");
      x=26;
    }
     if ( (ps2x.Analog(PSS_LY) > 98) && (ps2x.Analog(PSS_LY) < 158) && (ps2x.Analog(PSS_LX) > 200) )                 //putarkanan RIGHT
    {
      //Serial.println("LKANANANALOGLAMBAT");
      x=27;
    }
    if ( (ps2x.Analog(PSS_LY) > 98) && (ps2x.Analog(PSS_LY) < 158) && (ps2x.Analog(PSS_LX) < 55) )                  //putarkiri RIGHT
    {
      //Serial.println("LKIRIANALOGLAMBAT");
      x=28;
    }
    if (ps2x.Button(PSB_R1))
    {
     Serial.println("R1");
     digitalWrite (sudut1,HIGH);
     digitalWrite (sudut2,LOW);
     analogWrite(PWMsudut,255);
    }
    if (ps2x.Button(PSB_R2))
    {
     Serial.println("R2");
     digitalWrite (sudut1,LOW);
     digitalWrite (sudut2,HIGH);
     analogWrite(PWMsudut,255); 
    }
    // if (ps2x.ButtonPressed(PSB_L2))
    // {
    //  digitalWrite(Se1,LOW); // RELAY ON          
    // }
    if (ps2x.Button(PSB_L1))
    {
      Serial.print("L1");
      Lnaik();
    }
    if (ps2x.Button(PSB_L2))
    {
      Serial.print("L2");
      Lturun();
    }
    //if (ps2x.ButtonPressed(PSB_CIRCLE))
    //{
     // Serial.print("L2");
      
   // }
    

    // if (ps2x.ButtonPressed(PSB_R1))
    // {
    //   Serial.print("R1");
    //   if (kondisiPE == 0) {
    //     digitalWrite (RPWPE, HIGH);
    //     digitalWrite (RPWPE, LOW);
    //     kondisiPE = 1;
    //   }
    //   else {
    //     digitalWrite (RPWPE, LOW);
    //     digitalWrite (RPWPE, LOW);
    //     kondisiPE = 0;
    //   }
    // }

//-----------------------------------------------------------------------------------------------------------------------------------//
    delay(50);
  }
  digitalWrite(SS, LOW);                  //Starts communication with Slave connected to master
  Mastersend = x;    
  SPI.transfer(Mastersend);                        
  //Mastereceive=SPI.transfer(Mastersend); //Send the mastersend value to slave also receives value from slave
  Serial.print(Mastereceive);Serial.print("\t");Serial.println(Mastersend);

}
