#include <Arduino.h>
#include "board.h"
#include "turn_and_go.h"
#include "binserial.h"
#include "IntervalServo.h"

IntervalTimerServo servo_gauche;


// #include "lidar.h"
// #include "odometry.h"

float distance = 100;
int state = 0;

/* bool servo_gauche_state = 0;
bool servo_gauche_timer_state = 0;

void servo_gauche_update_low_deployed();
void servo_gauche_update_low_hidden();
void servo_gauche_update_high_deployed();
void servo_gauche_update_high_hidden(); */

TurnAndGo turn_and_go;
/*
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

*/

//servo_gauche: 40° = deployé

void switch_led(){
    state = !state;
}


/* void servo_gauche_deploy(){
    //faire basculer le timer servo gauche de 20ms à Xms
    servo_gauche_state = 1;
    if(servo_gauche_timer_state==0){
        servo_gauche_update_low_deployed();
        servo_gauche_timer_state = 1;
    }
}
void servo_gauche_releaseTimer(){
    servo_gauche_timer_state = 0;
    servoTimer_gauche.end();
}
void servo_gauche_hide(){
    servo_gauche_state = 0;
    if(servo_gauche_timer_state==0){
        servo_gauche_update_low_hidden();
        servo_gauche_timer_state = 1;
    }
}


void servo_gauche_update_low_deployed(){
    servoTimer_gauche.begin(servo_gauche_update_high_deployed,20000);
    digitalWrite(SERVO3, LOW);
}
void servo_gauche_update_low_hidden(){
    servoTimer_gauche.begin(servo_gauche_update_high_hidden,20000);
    digitalWrite(SERVO3, LOW);
}
void servo_gauche_update_high_deployed(){
    servoTimer_gauche.begin(servo_gauche_update_low_deployed,2000);
    digitalWrite(SERVO3, HIGH);
}
void servo_gauche_update_high_hidden(){
    servoTimer_gauche.begin(servo_gauche_update_low_hidden,900);
    digitalWrite(SERVO3, HIGH);
}
 */

void setup() {
    // Setup serial link
    // Serial.begin(9600);
    // while(!Serial);
    pinMode(LED_BUILTIN, OUTPUT);
    /* turn_and_go.setMaximumSpeed(200);
    turn_and_go.setAcceleration(500); */
    digitalWrite(LED_BUILTIN,HIGH);
    delay(2000);

    servo_gauche.attach(SERVO3);

}

void loop() {
    digitalWrite(LED_BUILTIN,state);
/*
    servo_gauche_releaseTimer();
    servo_gauche_deploy();
    delay(2500);
    servo_gauche_releaseTimer();
    servo_gauche_hide();
    delay(2500);*/


    
}
