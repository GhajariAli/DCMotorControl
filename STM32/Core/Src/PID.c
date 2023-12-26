#include "PID.h"

void updatePID(PID_Controller* pid, double current) {
	double error=0;
	switch (pid->ControlMode){
	case Velocity:
		error = pid->target - current;
		break;
	case Position:
		error = pid->target - current;
		if (error >0){
			error=(ENCODER_RESOLUTION/2)-error;
		}
		else if (error<0){
			error=-((ENCODER_RESOLUTION/2)+error);
		}
		else{
			error= 0;
		}
		break;
	case Torque:

		break;

	}
	pid->CurrentError=error;
	double P,D;
	if (pid->ControlMode!=Position){
		// Proportional
		P = pid->Kp * error;
		// Integral
		pid->integral += pid->Ki * error * (pid->dt/1000);
		// Derivative
		D = pid->Kd * (error - pid->prev_error) / (pid->dt/1000);
		// Total
		pid->output = P + pid->integral + D;
		// Integral with anti-windup
		if (pid->integral > pid->max_output) {
			pid->integral = pid->max_output;
		} else if (pid->integral < pid->min_output) {
			pid->integral = pid->min_output;
		}
	}
	else {
		P = pid->Kp * error;
		pid->integral += pid->Ki * error * (pid->dt/1000);
		// Integral with anti-windup
		if (pid->integral > pid->max_Integral) {
			pid->integral = pid->max_Integral;
		} else if (pid->integral < pid->min_Integral) {
			pid->integral = pid->min_Integral;
		}
		D = pid->Kd * (error - pid->prev_error) / (pid->dt/1000);
		// Total
		pid->output = (PWM_MAXVALUE/2) + P + pid->integral + D;
	}


	// Saturate output within limits
	if (pid->output > pid->max_output) {
		pid->output = pid->max_output;
	} else if (pid->output < pid->min_output) {
		pid->output = pid->min_output;
	}
	pid->prev_error = error;
}
