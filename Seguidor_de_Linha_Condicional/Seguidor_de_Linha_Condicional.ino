#include "Ultrasonic.h"

#define LIMIT 38
#define SENSOR_DIREITO A0
#define SENSOR_ESQUERDO A1
#define ENA 6
#define ENB 9
#define IN1 13
#define IN2 12
#define IN3 11
#define IN4 10
#define TRIGGER 7
#define ECHO 8

#define FWD_SPD 100
#define BACK_SPD 100

 
Ultrasonic ultrasonic(TRIGGER, ECHO);

void setup() {

  Serial.begin(9600);
  pinMode(SENSOR_DIREITO, INPUT);
  pinMode(SENSOR_ESQUERDO, INPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


void loop() {

  if (ultrasonic.read() <= 10) {
    while(ultrasonic.read() <= 10) {
      analogWrite(ENA, 0);
      analogWrite(ENB, 0);
      delay(500);
    }
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    
    analogWrite(ENA, FWD_SPD);
    analogWrite(ENB, FWD_SPD);
    delay(20);
  }
  

  int l_esq = analogRead(SENSOR_ESQUERDO);
  int l_dir = analogRead(SENSOR_DIREITO);


  if(l_esq < LIMIT && l_dir < LIMIT) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    
    analogWrite(ENA, FWD_SPD);
    analogWrite(ENB, FWD_SPD);

    Serial.println("BB");
  }
  
  if(l_esq < LIMIT && l_dir >= LIMIT) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    
    analogWrite(ENA, FWD_SPD);
    analogWrite(ENB, BACK_SPD);
    Serial.println("BP");
  }

  if(l_esq >= LIMIT && l_dir < LIMIT) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    
    analogWrite(ENA, BACK_SPD);
    analogWrite(ENB, FWD_SPD);
    
    Serial.println("PB");
  }

  if(l_esq >= LIMIT && l_dir >= LIMIT) {
    digitalWrite(ENA, LOW);
    digitalWrite(ENB, LOW);
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
    Serial.println("PP");

  }
}
