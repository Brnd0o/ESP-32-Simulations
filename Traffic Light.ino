# define RED_PIN 19
# define YELLOW_PIN 18
# define GREEN_PIN 17

#define RED_TIME 1500
#define YELLOW_TIME 1500
#define GREEN_TIME 1500




void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
}

void loop() {
  // Red LED
  digitalWrite (RED_PIN, HIGH);   // Red is on
  digitalWrite (YELLOW_PIN, LOW);   // Yellow is off
  digitalWrite (GREEN_PIN, LOW);  // Green is off
  delay(RED_TIME);

  // Yellow LED
  digitalWrite (RED_PIN, LOW);    // Red is off
  digitalWrite (YELLOW_PIN, HIGH);  // Yellow is on
  digitalWrite (GREEN_PIN,LOW);   // Green is off
  delay(YELLOW_TIME);

  //Green LED
  digitalWrite (RED_PIN, LOW);    // Red is off
  digitalWrite (YELLOW_PIN, LOW);   // Yellow is off
  digitalWrite (GREEN_PIN, HIGH); // Green is on
  delay(GREEN_TIME);
}
