void Lnaik(){
digitalWrite (RPWL1, HIGH);
digitalWrite (LPWL1, LOW);
analogWrite(PWML1, 255);
}

void Lturun(){
digitalWrite (RPWL1, LOW);
digitalWrite (LPWL1, HIGH);
analogWrite(PWML1, 255);
}

void Ldiam(){
digitalWrite (RPWL1, LOW);
digitalWrite (LPWL1, LOW);
analogWrite(PWML1, 255);
}