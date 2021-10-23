//define pin LED indicator
int x0 = 8; //left
int x1 = 9; //right
int x2 = 10; //straight

void setup() {
  Serial.begin(9600);
  //  for led indicator
  pinMode(x0, OUTPUT);
  pinMode(x1, OUTPUT);
  pinMode(x2, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char key = Serial.read();
    Serial.println(key);
    //  for LED indicator
    if (key == '1') {
      // mentah
      LED(1, 0, 0);
    }
    if (key == '2') {
      // matang
      LED(0, 1, 0);
    }
    if (key == '3') {
      // lewat matang
      LED(0, 0, 1);
    }
    if (key == '4') {
      // berhenti
      LED(0, 0, 0);
    }
    delay(500);
  }
}


void LED(int a, int b, int c) {
  digitalWrite(x0, a);
  digitalWrite(x1, b);
  digitalWrite(x2, c);
}
