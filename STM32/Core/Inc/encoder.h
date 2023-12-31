#include <stdint.h>
#include <stm32f4xx.h>
//select only one of the following modes:
#define ENCODER_GPIO_MODE
//#define ENCODER_INTERRUPT_MODE
//#define ENCODER_TIMER_MODE

enum direction {
  CW=1,
  CCW=2,
};

typedef struct{
	int IT_EncoderChA,IT_EncoderChB; //used with interrupt only
	int EncoderRawValue;
	int PreviusGrayCode;
	int GrayCode;
	enum direction direction;
	int32_t EncoderValue ;
	int32_t PreviousEncoderValue;
	int32_t SpeedRPM;
}encoder_data;

void GetEncoderValue(encoder_data *encoder);
