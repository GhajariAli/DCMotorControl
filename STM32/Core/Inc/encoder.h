#include <stdint.h>
#include <stm32f4xx.h>

enum direction {
  CW=1,
  CCW=2,
};

typedef struct{
	int PreviusGrayCode;
	enum direction direction;
	uint32_t EncoderValue ;
	uint32_t PreviousEncoderValue;
	int32_t SpeedRPM;
}encoder_data;

void GetEncoderValue(encoder_data *encoder);
