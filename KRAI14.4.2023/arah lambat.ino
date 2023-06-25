void  g0l(){
    sp=25;
    sp1=50;
    sp2=25;

      digitalWrite (RPWM0, LOW);
      digitalWrite (LPWM0, HIGH);

      digitalWrite (RPWM1, HIGH);
      digitalWrite (LPWM1, LOW);

      digitalWrite (RPWM2, LOW);
      digitalWrite (LPWM2, HIGH);
      last_error = 0;
last_error1 = 0;
last_error2 = 0;
errorb = 0;
error1 = 0;
error2 = 0;
}


void  g90l(){
    sp=44;
    sp1=0;
    sp2=44;

      digitalWrite (RPWM0, LOW);
      digitalWrite (LPWM0, HIGH);

      digitalWrite (RPWM1, LOW);
      digitalWrite (LPWM1, LOW);

      digitalWrite (RPWM2, HIGH);
      digitalWrite (LPWM2, LOW);
      last_error = 0;
last_error1 = 0;
last_error2 = 0;
errorb = 0;
error1 = 0;
error2 = 0;
}


void  g180l(){
sp=25;
sp1=50;
sp2=25;
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


void  g270l(){
sp=44;
sp1=0;
sp2=44;
CW0();
STOP1();
CCW2();
last_error = 0;
last_error1 = 0;
last_error2 = 0;
errorb = 0;
error1 = 0;
error2 = 0;
}