////// Motor 0
void CW0(){
      digitalWrite (RPWM0, HIGH);
      digitalWrite (LPWM0, LOW);
}

void CCW0(){
      digitalWrite (RPWM0, LOW);
      digitalWrite (LPWM0, HIGH);
}

void STOP0(){
      digitalWrite (RPWM0, LOW);
      digitalWrite (LPWM0, LOW);
}
                ////// Motor 1

                void CW1(){
                      digitalWrite (RPWM1, HIGH);
                      digitalWrite (LPWM1, LOW);
                }

                void CCW1(){
                      digitalWrite (RPWM1, LOW);
                      digitalWrite (LPWM1, HIGH);
                }

                void STOP1(){
                      digitalWrite (RPWM1, LOW);
                      digitalWrite (LPWM1, LOW);
                }
                                  ////// Motor 0
                                  void CW2(){
                                        digitalWrite (RPWM2, HIGH);
                                        digitalWrite (LPWM2, LOW);
                                  }

                                  void CCW2(){
                                        digitalWrite (RPWM2, LOW);
                                        digitalWrite (LPWM2, HIGH);
                                  }

                                  void STOP2(){
                                        digitalWrite (RPWM2, LOW);
                                        digitalWrite (LPWM2, LOW);
                                  }
