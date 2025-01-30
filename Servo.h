#include <Servo.h>

#define LDR_LEFT A0  
#define LDR_RIGHT A1  
#define ERROR_MARGIN 10  

Servo solarServo;  
int servoPosition = 90;  

void setup() {
    solarServo.attach(9);
    solarServo.write(servoPosition);
    delay(1000);
}

void loop() {
    int ldrLeftValue = analogRead(LDR_LEFT);   
    int ldrRightValue = analogRead(LDR_RIGHT); 
    int difference = abs(ldrLeftValue - ldrRightValue);

    if (difference > ERROR_MARGIN) {
        servoPosition += (ldrLeftValue > ldrRightValue) ? -1 : 1;
        servoPosition = constrain(servoPosition, 0, 180);
        solarServo.write(servoPosition);
    }

    delay(100);
}
