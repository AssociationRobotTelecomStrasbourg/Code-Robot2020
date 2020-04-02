#ifndef MICROSERVO_H
#define MICROSERVO_H

#include <Arduino.h>


class MicrosServo
{
private:
    /* data */
    uint8_t attributedPin;
    int state;
    int idle_time;
    int timer;
    int value;
public:
    MicrosServo();
    void assign(uint8_t new_pin);
    void write(int new_value);

};

MicrosServo::MicrosServo(){
    state = 0;
    idle_time = 20000;
    timer = 0;
    value = 1500;
}

void MicrosServo::assign(uint8_t new_pin){
    attributedPin = new_pin;
    pinMode(attributedPin, OUTPUT);
    digitalWrite(attributedPin, 0);
}

void MicrosServo::write(int new_value){

    digitalWrite(attributedPin, state);
    
    if(micros()%idle_time == 0 && state == 0){
        state = 1;
        timer = micros();
        Serial.println("1");
    }

    else if(micros()-timer > value && state == 1){
        state = 0;
        Serial.println("0");
    }
}

#endif