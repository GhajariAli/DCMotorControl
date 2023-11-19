typedef struct{
    double Kp;
    double Ki;
    double Kd;
    double min_output;
    double max_output;
    double target;
    double prev_error;
    double integral;
    double dt;
    double output;
}PID_Controller;

void updatePID(PID_Controller* pid, double current);

