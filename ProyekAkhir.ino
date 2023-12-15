#include <Servo.h>
#include <AFMotor.h>

#define Echo A0
#define Trig A1
#define motor 10
#define INT_1 2
#define Speed 170
#define spoint 103
#define LedManualMode 13
#define LedAutoMode 9

char value;
int distance;
int Left;
int Right;
int L = 0;
int R = 0;
int L1 = 0;
int R1 = 0;
int ManualMode = 1;
int AutoMode = 0;

Servo servo;
AF_DCMotor M1(1);
AF_DCMotor M2(2);
AF_DCMotor M3(3);
AF_DCMotor M4(4);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(INT_1, INPUT);
  pinMode(LedManualMode, OUTPUT);
  pinMode(LedAutoMode, OUTPUT);
  servo.attach(motor);
  attachInterrupt(digitalPinToInterrupt(INT_1), SensorSentuh1, FALLING);
  M1.setSpeed(Speed);
  M2.setSpeed(Speed);
  M3.setSpeed(Speed);
  M4.setSpeed(Speed);

}

// function gerakan maju
void maju(){
  M1.run(FORWARD);
  M2.run(FORWARD);
  M3.run(FORWARD);
  M4.run(FORWARD);
  }
  
// function gerakan mundur
void mundur(){
  M1.run(BACKWARD);
  M2.run(BACKWARD);
  M3.run(BACKWARD);
  M4.run(BACKWARD);
  }
  
// function gerakan belok kanan
void kanan(){
  M1.run(BACKWARD);
  M2.run(BACKWARD);
  M3.run(FORWARD);
  M4.run(FORWARD);
  }
  
// function gerakan belok kiri
void kiri(){
  M1.run(FORWARD);
  M2.run(FORWARD);
  M3.run(BACKWARD);
  M4.run(BACKWARD);
  }

// function untuk berhenti
void berhenti() {
  M1.run(RELEASE);
  M2.run(RELEASE);
  M3.run(RELEASE);
  M4.run(RELEASE);
}

// function untuk Ultrasonik
int ultrasonic() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(4);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  long t = pulseIn(Echo, HIGH);
  int distance = t * 0.034 / 2;
  return distance;
}

// function untuk gerakan Ultrasonik
int tengokKanan() {
  digitalWrite(LedManualMode, LOW);
  digitalWrite(LedAutoMode, HIGH);
  servo.write(20);
  delay(800);
  Left = ultrasonic();
  return Left;
  }

int tengokKiri(){
  digitalWrite(LedManualMode, LOW);
  digitalWrite(LedAutoMode, HIGH);
  servo.write(180);
  delay(800);
  Right = ultrasonic();
  return Right;
}

// function mode manual mobil
void ModeManual(){
  if (Serial.available()>0){
    value = Serial.read();
    Serial.println(value);
    }
  if (value == 'F') {
    maju();
    }
  else if (value == 'L'){
    kiri();
    }
  else if (value == 'B'){
    mundur();
    }
  else if (value == 'R'){
    kanan();
    }
  else if (value == 'S'){
    berhenti();
    }
  }

// funtion mode auto mobil
void ModeAuto(){
  distance = ultrasonic();
  
  if (distance > 10 && distance < 50){
    maju ();
    delay(200);
    berhenti();
  }
  else if (distance <= 10) {
    berhenti();
    delay(100);
    L = tengokKiri();
    servo.write(spoint);
    delay(800);
    R = tengokKanan();
    servo.write(spoint);
     if (L<R){
      kanan();
      delay(500);
      berhenti();
      delay(200);
      }
    else if(L>R){
      kiri();
      delay(500);
      berhenti();
      delay(200);
      }
    }
    else {
      maju();
      delay(100);
      berhenti();
      }
  }

// function untuk Interrupt
void SensorSentuh1(){
  ManualMode = ManualMode^1;
  AutoMode = AutoMode^1;
  }


// Program utama
void loop() {
  // put your main code here, to run repeatedly:
  if (ManualMode == 1 && AutoMode == 0){
    digitalWrite(LedManualMode, HIGH);
    digitalWrite(LedAutoMode, LOW);
    ModeManual();
    }
  else if(ManualMode == 0 && AutoMode == 1){
    digitalWrite(LedManualMode, LOW);
    digitalWrite(LedAutoMode, HIGH);
    ModeAuto();
    }
}
