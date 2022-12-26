
const int echo = 10;
const int trig = 9;
int red = 13;
int yellow = 12;
int green = 11;

// motor
const int m1 = 7;   // left   YELLOW
const int m2 = 8;   // right  RED

bool isClosed, isOpen;

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  
  opening();
}

void opening(){
  isOpen = true;
  isClosed = false;
  digitalWrite(m2, HIGH);
  digitalWrite(m1, LOW);
  delay(4000);
  digitalWrite(m2, LOW);
}
void closing(){
    isClosed = true;
    isOpen = false;
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    delay(4000);
    digitalWrite(m1, LOW);
}

void loop() {
  long duration, distance;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(2);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);   // in micro seconds
  distance = (duration / 2) / 29.1;   // half of distance since it's transmiting and receiving
  Serial.print(distance);
  Serial.println("CM");
  delay(200);

  if(distance >=0 && distance <= 15){
    digitalWrite(red, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
  }else if(distance >15 && distance <=25){
    digitalWrite(yellow, HIGH);
     digitalWrite(red, LOW);
    digitalWrite(green, LOW);
  }else if(distance >25){
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
  }

  if(distance < 6 ){
    closing();
  }

}
