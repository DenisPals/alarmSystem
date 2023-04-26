int buzzerPin = 2; // the number of the buzzer pin
int buzzerVoltage = 11;
int ledPin = 10; // the number of the led pin  
int sensorPin = 7;
float sinVal; // Define a variable to save sine value
int toneVal; // Define a variable to save sound frequency

void setup() {
  pinMode(ledPin, OUTPUT); // Set ledPin to output mode
  pinMode(buzzerPin, OUTPUT); // Set Buzzer pin to output mode
  pinMode(sensorPin, INPUT);
  pinMode(buzzerVoltage, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(sensorPin) == HIGH) {
    digitalWrite(buzzerVoltage, HIGH);
    digitalWrite(ledPin, HIGH);
    push_notification();
    for (int times = 0; times < 20; times++) {
      sound_alarm();
    }
    digitalWrite(buzzerVoltage, LOW);
  } else {
    digitalWrite(ledPin, LOW);
    delay(3000);
  }
}

void sound_alarm() {
  for (int x = 0; x < 360; x++) { // X from 0 degree->360 degree
   sinVal = sin(x * (PI / 180)); // Calculate the sine of x
   toneVal = 2000 + sinVal * 500; // Calculate sound frequency according to the sine of x
   tone(buzzerPin, toneVal); // Output sound frequency to buzzerPin
   delay(1);
   }
}

void push_notification() {
  // Print ALARM so that push notification API will be prompted
  Serial.println("ALARM");
}
