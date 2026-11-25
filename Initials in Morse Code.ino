// Define pins for LED and Buzzer
const int ledPin = 23;
const int buzzerPin = 22;

const int dotDuration = 200;                 // "Dot" duration (1t)
const int dashDuration = dotDuration * 3;    // "Dash" duration (3t)
const int interElementGap = dotDuration;     // Gap between elements of a letter (1t)
const int interLetterGap = dotDuration * 3;  // Gap between letters (3t)
const int interWordGap = dotDuration * 7;    //  Gap between SOS sequences (7t)

void signalOn();
void signalOff();
void dot();
void dash();
void letterY();
void letterB();
void letterS();
void playYBS();

void setup() {
  Serial.begin(115200);
  Serial.println("Preparing to transmit code");

  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  signalOff();
  delay(2000);  
}

void loop() {
  playYBS();

  Serial.print("Waiting ");
  Serial.print(interWordGap);
  Serial.println(" milliseconds before repeating...\n");
  delay(interWordGap);
}

// Turn on both LED and Buzzer simultaneously
void signalOn() {
  digitalWrite(ledPin, HIGH);
  digitalWrite(buzzerPin, HIGH);
}

// Turn off both LED and Buzzer simultaneously
void signalOff() {
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);
}

// Dot signal
void dot() {
  signalOn();
  delay(dotDuration);
  signalOff();
}

// Dash signal
void dash() {
  signalOn();
  delay(dashDuration);
  signalOff();
}

// Transmit the letter 'Y' (-.--): three dashes and one dot
void letterY() {
  Serial.print("-");
  dash();
  delay(interElementGap);
  Serial.print(".");
  dot();
  delay(interElementGap);
  Serial.print("-");
  dash();
  delay(interElementGap);
  Serial.print("-");
  dash();
}

// Transmit the letter 'B' (-...): one dashe and three dots
void letterB() {
  Serial.print("-");
  dash();
  delay(interElementGap);
  Serial.print(".");
  dot();
  delay(interElementGap);
  Serial.print(".");
  dot();
  delay(interElementGap);
  Serial.print(".");
  dot();
}

// Transmit the letter 'S' (...): three dots
void letterS() {
  Serial.print(".");
  dot();
  delay(interElementGap);
  Serial.print(".");
  dot();
  delay(interElementGap);
  Serial.print(".");
  dot();
}

// Play the complete SOS sequence
void playYBS() {
  Serial.print("Transmitting Y: ");
  letterY();
  Serial.print(" | ");
  delay(interLetterGap);

  Serial.print("Transmitting B: ");
  letterB();
  Serial.print(" | ");
  delay(interLetterGap);

  Serial.print("Transmitting S: ");
  letterS();
  Serial.println();
  Serial.println("Morse Code sequence transmission complete.");
}
