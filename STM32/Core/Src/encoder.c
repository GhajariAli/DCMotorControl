#include "encoder.h"

void GetEncoderValue(encoder_data *encoder){
	  int EncoderGrayCode = 0;
	  int GrayCodeConvert[]={0,1,3,2};
	  //reading encoder value as gray code
	  EncoderGrayCode=GrayCodeConvert[(HAL_GPIO_ReadPin(ENCODER_PORT, ENCODER_PIN_A) <<1 | HAL_GPIO_ReadPin(ENCODER_PORT, ENCODER_PIN_B)) & 0x03];
	  //if encoder value updated
	  if (encoder->EncoderLastState != EncoderGrayCode){
		  int EncoderDeltaValue;
		  EncoderDeltaValue = EncoderGrayCode-encoder->EncoderLastState;
		  if (EncoderDeltaValue<0) {EncoderDeltaValue=4;}
		  if (EncoderDeltaValue ==1) {
			  encoder->direction=CCW;
			  encoder->EncoderValue++;
		  }
		  else if (EncoderDeltaValue ==3){
			  encoder->direction=CCW;
			  encoder->EncoderValue--;
		  }
		  encoder->EncoderLastState=EncoderGrayCode;
	  }
}
