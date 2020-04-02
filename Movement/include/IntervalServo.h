#include <Arduino.h>


class IntervalTimerServo
{
private:
    /* data */
    uint8_t attachedPin;
    bool timerState;
    bool inWriteLoop;
    unsigned int idle_time;
    IntervalTimer servoTimer_;
    int position;
    void update_low();
    void update_high();
public:
    IntervalTimerServo();
    void attach(uint8_t pin);
    void write(unsigned int value);
    void release();
};