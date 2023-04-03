 const int t1_LED = 13;
// unsigned int on_off = 0;

const int t2_LED = 12;
unsigned int t_high = 0;

// unsigned long t1_prev = 0;
// const unsigned long t1_delay = 500;

unsigned long t2_prev = 0;
const unsigned long t2_delay = 10;

const int buttonPin = 2;  // the number of the pushbutton pin
int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  pinMode(t1_LED, OUTPUT);
  pinMode(t2_LED, OUTPUT);
  pinMode(buttonPin, INPUT);

}

void loop() {
  // unsigned long t1_now = millis();
  // if (t1_now - t1_prev >= t1_delay) {
  //   t1_prev = t1_now;

  //   on_off++;
  //   if(on_off>1) on_off =0;
  //   digitalWrite(t1_LED, on_off);
  // }

  unsigned long t2_now = millis();
  if (t2_now - t2_prev >= t2_delay) {
    t2_prev = t2_now;

    t_high++;
    if(t_high>255) t_high =0;
    analogWrite(t2_LED, t_high);
  }

  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == LOW) {
    // turn LED on:
    digitalWrite(t1_LED, HIGH);
  } else {
    // turn LED off:
    digitalWrite(t1_LED, LOW);
  }

}
