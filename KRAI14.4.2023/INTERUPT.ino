void ISR_Encoder_A(){
  if(digitalRead(pEchB)){
    //clockwise
    countPulses++;
  }else{
    //counter clockwise
    countPulses++;
  }
}

void ISR_Encoder_A1(){
  if(digitalRead(pEchB1)){
    //clockwise
    countPulses1++;
  }else{
    //counter clockwise
    countPulses1++;
  }
}

void ISR_Encoder_A2(){
  if(digitalRead(pEchB2)){
    //clockwise
    countPulses2++;
  }else{
    //counter clockwise
    countPulses2++;
  }
}