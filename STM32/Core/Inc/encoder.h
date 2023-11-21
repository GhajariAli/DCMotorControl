#include <stdint.h>
#include <stm32f4xx.h>

enum direction {
  CW=1,
  CCW=2,
};

typedef struct{
	int PreviusGrayCode;
	enum direction direction;
	int32_t EncoderValue ;
	int32_t PreviousEncoderValue;
	int32_t SpeedRPM;
}encoder_data;

void GetEncoderValue(encoder_data *encoder);
