enum Mode{
	Velocity = 0,
	Position = 1,
	Torque = 2,
};

typedef struct{
	enum Mode ControlMode;
    double Kp;
    double Ki;
    double Kd;
    double min_output;
    double max_output;
    double min_Integral;
    double max_Integral;
    double target;
    double CurrentError;
    double prev_error;
    double integral;
    double dt; //sample time in msec
    double output;
}PID_Controller;
#define ENCODER_RESOLUTION 256
#define PWM_MAXVALUE	1000


void updatePID(PID_Controller* pid, double current);

