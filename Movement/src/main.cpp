#include <Arduino.h>
#include "board.h"
#include "turn_and_go.h"
#include "binserial.h"


// #include "lidar.h"
// #include "odometry.h"

float distance = 100;
int state = 0;

TurnAndGo turn_and_go;

void move(int r, int theta){
    if (turn_and_go.run() == STOP) {
        // writeData(turn_and_go.getPosition(), sizeof(position_t));
        if(state==0){
            turn_and_go.translateFrom(2000);
            state++;
        }
        else if(state==1){
            turn_and_go.rotateFrom(M_PI);
            state = 0;
        }
        delay(10000);

    }
}



//servo_gauche: 40° = deployé

void switch_led(){
    state = !state;
}


void setup() {
    // Setup serial link
    // Serial.begin(9600);
    // while(!Serial);

    //***INIT LED TEENSY Mouvement
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN,HIGH);
    
    //**INIT LED DEBUG
    pinMode(DEBUG_LED1, OUTPUT);
    pinMode(DEBUG_LED2, OUTPUT);
    digitalWrite(DEBUG_LED1, HIGH);
    digitalWrite(DEBUG_LED2, HIGH);

    //***SETUP TURN & GO
    turn_and_go.setMaximumSpeed(200);
    turn_and_go.setAcceleration(500);
    
    //**SETUP SAFETY DELAY
    delay(2000);
    digitalWrite(LED_BUILTIN,LOW);
    digitalWrite(DEBUG_LED1, LOW);
    digitalWrite(DEBUG_LED2, LOW);
}

void loop() {
    

}
