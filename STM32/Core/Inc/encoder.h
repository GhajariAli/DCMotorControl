#include <stdint.h>
#include <stm32f4xx.h>

#define 	ENCODER_PORT  	GPIOA
#define 	ENCODER_PIN_A 	GPIO_PIN_6
#define 	ENCODER_PIN_B 	GPIO_PIN_7

enum direction {
  CW=1,
  CCW=2,
};

typedef struct{
	int EncoderState[4];
	int EncoderLastState;
	enum direction direction;
	int32_t EncoderValue ;
	int32_t PreviousEncoderValue;
	int32_t SpeedRPM;
}encoder_data;

void GetEncoderValue(encoder_data *encoder);
