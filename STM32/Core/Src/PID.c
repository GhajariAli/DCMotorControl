#include "PID.h"

void updatePID(PID_Controller* pid, double current) {
    double error = pid->target - current;
    // Proportional
    double P = pid->Kp * error;
    // Integral term (with anti-windup)
    pid->integral += pid->Ki * error * (pid->dt/1000);
    if (pid->integral > pid->max_output) {
        pid->integral = pid->max_output;
    } else if (pid->integral < pid->min_output) {
        pid->integral = pid->min_output;
    }
    // Derivative
    double D = pid->Kd * (error - pid->prev_error) / (pid->dt/1000);
    // Total
    pid->output = P + pid->integral + D;
    // Saturate output within limits
    if (pid->output > pid->max_output) {
    	pid->output = pid->max_output;
    } else if (pid->output < pid->min_output) {
    	pid->output = pid->min_output;
    }
    pid->prev_error = error;
}
