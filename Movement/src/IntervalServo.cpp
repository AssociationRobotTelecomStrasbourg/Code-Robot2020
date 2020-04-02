#include "IntervalServo.h"

IntervalTimerServo::IntervalTimerServo(){
    timerState = 0;
    inWriteLoop = 0;
    position = 0;
    idle_time = 20000;
}

void IntervalTimerServo::attach(uint8_t pin){
    attachedPin = pin;
}

void IntervalTimerServo::write(unsigned int value){
    position = value;
    if(timerState == 0){
        timerState = 1;
        servoTimer_.begin(this->update_high,this->idle_time);
    }
}

void IntervalTimerServo::release(){
    position = 0;
    servoTimer_.end();
    timerState = 0;
}

void IntervalTimerServo::update_low(){
    this->servoTimer_.begin(this->update_high,this->idle_time);
    digitalWrite(attachedPin, LOW);
}
void IntervalTimerServo::update_high(){
    this->servoTimer_.begin(this->update_low,this->position);
    digitalWrite(attachedPin, HIGH);
}