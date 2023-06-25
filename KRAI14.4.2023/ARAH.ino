void g315(){
sp=193/4;
sp1=141/4;
sp2=52/4;
CW0();
CCW1();
CCW2();
last_error = 0;
last_error1 = 0;
last_error2 = 0;
errorb = 0;
error1 = 0;
error2 = 0;
}

void  g0(){
sp=50/2;
sp1=100/2;
sp2=50/2;
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

void  g45(){
sp=52/4;
sp1=141/4;
sp2=193/4;
CCW0();
CCW1();
CW2();
last_error = 0;
last_error1 = 0;
last_error2 = 0;
errorb = 0;
error1 = 0;
error2 = 0;
}

void  g270(){
sp=173/4;
sp1=0;
sp2=173/4;
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

void  g135(){
sp=193/4;
sp1=141/4;
sp2=52/4;
CCW0();
CW1();
CW2();
last_error = 0;
last_error1 = 0;
last_error2 = 0;
errorb = 0;
error1 = 0;
error2 = 0;
}

void  g225(){
    sp=52/4;
    sp1=141/4;
    sp2=193/4;

      digitalWrite (RPWM0, HIGH);
      digitalWrite (LPWM0, LOW);

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


void  g180(){
    sp=50/2;
    sp1=100/2;
    sp2=50/2;

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

void  g90(){
    sp=173/4;
    sp1=0;
    sp2=173/4;

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

void stop(){
    sp=0;
    sp1=0;
    sp2=0;


      digitalWrite (RPWM0, LOW);
            digitalWrite (LPWM0, LOW);

      digitalWrite (RPWM1, LOW);
            digitalWrite (LPWM1, LOW);

      digitalWrite (RPWM2, LOW);
            digitalWrite (LPWM2, LOW);
}


void putarkanan(){
      sp=30;
    sp1=30;
    sp2=30;

      digitalWrite (RPWM0, LOW);
      digitalWrite (LPWM0, HIGH);

      digitalWrite (RPWM1, LOW);
      digitalWrite (LPWM1, HIGH);

      digitalWrite (RPWM2, LOW);
      digitalWrite (LPWM2, HIGH);
}


void putarkiri(){
    sp=30;
    sp1=30;
    sp2=30;

      digitalWrite (RPWM0, HIGH);
      digitalWrite (LPWM0, LOW);

      digitalWrite (RPWM1, HIGH);
      digitalWrite (LPWM1, LOW);

      digitalWrite (RPWM2, HIGH);
      digitalWrite (LPWM2, LOW);
}