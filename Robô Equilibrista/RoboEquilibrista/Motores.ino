const int IN1 = 8;
const int IN2 = 9;
const int IN3 = 6;
const int IN4 = 7;

const int PWM1 = 3;
const int PWM2 = 5;

int dir;
void init_motores() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void PWMControleMotores(double comando) {

  if (comando > 0) {
    analogWrite(PWM1, abs(comando));
    analogWrite(PWM2, abs(comando));

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else if (comando < 0) {
    analogWrite(PWM1, abs(comando));
    analogWrite(PWM2, abs(comando));

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  } else {
    analogWrite(PWM1, abs(comando));
    analogWrite(PWM2, abs(comando));

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }
}