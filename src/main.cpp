#include <PS4Controller.h>
#include "BluetoothSerial.h"

int r = 255;
int g = 0;
int b = 0;

// Calculates the next value in a rainbow sequence
void nextRainbowColor() {
  if (r > 0 && b == 0) {
    r--;
    g++;
  }
  if (g > 0 && r == 0) {
    g--;
    b++;
  }
  if (b > 0 && g == 0) {
    r++;
    b--;
  }
}


BluetoothSerial BT;

void setup() {
  Serial.begin(115200);
  PS4.begin();
  BT.begin();
  
  // while(!BT.connected()) delay(100);
  // BT.connect("fb:bb:cd:5a:f3:06");
  Serial.println(BT.getNumberOfBondedDevices());
}
  
void loop() {
  if (PS4.isConnected()) {
    if (PS4.Right()) Serial.println("Right Button");
    if (PS4.Down()) Serial.println("Down Button");
    if (PS4.Up()) Serial.println("Up Button");
    if (PS4.Left()) Serial.println("Left Button");

    if (PS4.Square()) Serial.println("Square Button");
    if (PS4.Cross()) Serial.println("Cross Button");
    if (PS4.Circle()) Serial.println("Circle Button");
    if (PS4.Triangle()) Serial.println("Triangle Button");

    if (PS4.UpRight()) Serial.println("Up Right");
    if (PS4.DownRight()) Serial.println("Down Right");
    if (PS4.UpLeft()) Serial.println("Up Left");
    if (PS4.DownLeft()) Serial.println("Down Left");

    if (PS4.L1()) Serial.println("L1 Button");
    if (PS4.R1()) Serial.println("R1 Button");

    if (PS4.Share()) Serial.println("Share Button");
    if (PS4.Options()) Serial.println("Options Button");
    if (PS4.L3()) Serial.println("L3 Button");
    if (PS4.R3()) Serial.println("R3 Button");

    if (PS4.PSButton()) Serial.println("PS Button");
    if (PS4.Touchpad()) Serial.println("Touch Pad Button");

    if (PS4.L2()) {
      Serial.printf("L2 button at %d\n", PS4.L2Value());
    }
    if (PS4.R2()) {
      Serial.printf("R2 button at %d\n", PS4.R2Value());
    }

    if (PS4.LStickX()) {
      Serial.printf("Left Stick x at %d\n", PS4.LStickX());
    }
    if (PS4.LStickY()) {
      Serial.printf("Left Stick y at %d\n", PS4.LStickY());
    }
    if (PS4.RStickX()) {
      Serial.printf("Right Stick x at %d\n", PS4.RStickX());
    }
    if (PS4.RStickY()) {
      Serial.printf("Right Stick y at %d\n", PS4.RStickY());
    }

    if (PS4.Charging()) Serial.println("The controller is charging");
    if (PS4.Audio()) Serial.println("The controller has headphones attached");
    if (PS4.Mic()) Serial.println("The controller has a mic attached");

    Serial.printf("Battery Level : %d\n", PS4.Battery());

    Serial.println();
    PS4.setLed(r, g, b);
    nextRainbowColor();

    // Sets how fast the controller's front light flashes
    // Params: How long the light is on in ms, how long the light is off in ms
    // Range: 0->2550 ms, Set to 0, 0 for the light to remain on
    PS4.setFlashRate(PS4.LStickY() * 10, PS4.RStickY() * 10);

    // Sets the rumble of the controllers
    // Params: Weak rumble intensity, Strong rumble intensity
    // Range: 0->255
    PS4.setRumble(PS4.L2Value(), PS4.R2Value());

    // Sends data set in the above three instructions to the controller
    PS4.sendToController();
    // This delay is to make the output more human readable
    // Remove it when you're not trying to see the output
    delay(100);
  }
}

