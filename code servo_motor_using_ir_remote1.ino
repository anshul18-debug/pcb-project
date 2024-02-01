#include <IRremote.h>
#include <Servo.h>

#define plus 0xEF10BF00
#define minus 0xEE11BF00

int RECV_PIN = 2;
Servo servo;
int val;
bool cwRotation, acwRotation;

void setup() {
  Serial.begin(96000);
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);
  servo.attach(9);
}

void loop() {
  if (IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    IrReceiver.resume();
    if (IrReceiver.decodedIRData.decodedRawData == plus) {
      cwRotation = !cwRotation;
      acwRotation = false;
    }
    if (IrReceiver.decodedIRData.decodedRawData == minus) {
      acwRotation = !acwRotation;
      cwRotation = false;
    }
  }

  if (cwRotation && (val != 180)) {
    val++;
  }
  if (acwRotation && (val != 0)) {
    val--;
  }
  servo.write(val);
  delay(20);
}
