#ifndef TURN_AND_GO_H
#define TURN_AND_GO_H

#include <TMC2130Stepper.h>
#include <TeensyStep.h>
#include "board.h"

// Movements parameters
const bool backward = true; // Allow the robot to go backward

// Odometry parameters
const float step_ratio = 0.99; // Ratio of the two wheel perimeter wheel1/wheel2
const float wheel_perimeter = 50.8; // in mm (4" = 101.6mm /diameter) / 3 reduction ratio 
const float center_distance = 106.25; // in mm [Distance between wheels = 220mm]

// Stepper parameters
const uint16_t current = 1100;
const uint8_t microstep = 16;
const bool interpolate = true;
const uint32_t step_per_turn = 200*microstep;

struct position_t {
	float x, y, theta;
};

enum state_t {STOP, ROTATE, TRANSLATE, BRAKE};

class TurnAndGo {
public:
	// Initialize TurnAndGo
	TurnAndGo(const float maximum_speed = 1000, const float acceleration = 1000);

	// Go to (x,y) in mm
	void goTo(const float x, const float y);

	// Rotate to theta in rad
	void rotateTo(const float theta);

	// Rotate from delta_theta in rad
	void rotateFrom(const float delta_theta);

	// Translate from distance in rad
	void translateFrom(const float distance);

	// Move steppers from delta_steps
	void stepFrom(const int32_t delta_step1, const int32_t delta_step2);

	// Stop steppers
	void stop();

	// Return if steppers are moving
	bool isMoving();

	// Run the control of the motor
	state_t run();

	// Get position
	const position_t* getPosition() const;

	// Get maximum speed
	const float getMaximumSpeed() const;

	// Get acceleration
	const float getAcceleration() const;

	// Set position
	void setPosition(const position_t* position);

	// Set maximum speed
	void setMaximumSpeed(const float maximum_speed);

	// Set acceleration
	void setAcceleration(const float acceleration);

private:
	TMC2130Stepper _stepper_config1, _stepper_config2;
	Stepper _stepper1, _stepper2;
	StepControl _controller;
	position_t _position;
	state_t _state;
	int32_t _step1, _d_step1, _step2, _d_step2;

	float _angle, _distance;

	float _maximum_speed, _acceleration;
};

// Return the angle between [-pi, pi)
float angleModulo(float angle);

#endif
