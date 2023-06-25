void PID(){
  
   unsigned long currentTime = millis();
    float deltaTime = currentTime - lastTime;
    if(deltaTime>=TimeSampling){
    float freqSignal = (float)countPulses/(deltaTime/1.0e3); //(deltaTime/1.0e3) --> convert ms to s
    float rpm = freqSignal * 60.0 / 249.6; //249,6 = p*N; p=step-up gear ratio; N=pulses per revolution
    lastTime = currentTime;
    countPulses = 0;
    errorb = sp - rpm;    
    sum_error = sum_error + errorb;
    motorSpeed = (kp*errorb) + (ki*sum_error) + (errorb-last_error);
    if (motorSpeed > 255) motorSpeed =255;
    else if(motorSpeed < 0) motorSpeed = 0;    
  analogWrite(PWM0, motorSpeed);
    last_error = errorb;
  } 

                  unsigned long currentTime1 = millis();
                  float deltaTime1 = currentTime1 - lastTime1;
                  if(deltaTime1>=TimeSampling1){
                  float freqSignal1 = (float)countPulses1/(deltaTime1/1.0e3); //(deltaTime/1.0e3) --> convert ms to s
                  float rpm1 = freqSignal1 * 60.0 / 249.6; //249,6 = p*N; p=step-up gear ratio; N=pulses per revolution
                  lastTime1 = currentTime1;
                  countPulses1 = 0;
                  error1 = sp1 - rpm1;    
                  sum_error1 = sum_error1 + error1;
                  motorSpeed1 = (kp1*error1) + (ki1*sum_error1) + (error1-last_error1);

                  if (motorSpeed1 > 255) motorSpeed1 =255;
                  else if(motorSpeed1 < 0) motorSpeed1 = 0;    
                
                analogWrite(PWM1, motorSpeed1);
                  last_error1 = error1;
                }

                                          unsigned long currentTime2 = millis();
                                          float deltaTime2 = currentTime2 - lastTime2;
                                          if(deltaTime2>=TimeSampling2){
                                          float freqSignal2 = (float)countPulses2/(deltaTime2/1.0e3); //(deltaTime/1.0e3) --> convert ms to s
                                          float rpm2 = freqSignal2 * 60.0 / 249.6; //249,6 = p*N; p=step-up gear ratio; N=pulses per revolution
                                          lastTime2 = currentTime2;
                                          countPulses2 = 0;
                                          error2 = sp2 - rpm2;    
                                          sum_error2 = sum_error2 + error2;
                                          motorSpeed2 = (kp2*error2) + (ki2*sum_error2) + (error2-last_error2);

                                          if (motorSpeed2 > 255) motorSpeed2 =255;
                                          else if(motorSpeed2 < 0) motorSpeed2 = 0;    
                                        
                                        analogWrite(PWM2, motorSpeed2);
                                          last_error2 = error2;
                                        }

}