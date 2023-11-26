#include "encoder.h"
#include "main.h"

void GetEncoderValue(encoder_data *encoder){
	  int EncoderGrayCode = 0;
	  int GrayCodeConvert[]={0,1,3,2};
	  //reading encoder value as gray code
#ifdef ENCODER_GPIO_MODE
	  EncoderGrayCode = GrayCodeConvert[(HAL_GPIO_ReadPin(Encoder_A_GPIO_Port, Encoder_A_Pin) <<1 | HAL_GPIO_ReadPin(Encoder_B_GPIO_Port, Encoder_B_Pin)) & 0x03];
#endif
#ifdef ENCODER_INTERRUPT_MODE
	  EncoderGrayCode = GrayCodeConvert[(encoder->IT_EncoderChA <<1 | encoder->IT_EncoderChB) & 0x03];
#endif

#ifndef ENCODER_TIMER_MODE //the value will be written in main.c in timer interrupt function
	  //if encoder value updated
	  if (encoder->PreviusGrayCode != EncoderGrayCode){
		  int EncoderDeltaValue;
		  EncoderDeltaValue = EncoderGrayCode-encoder->PreviusGrayCode;
		  if (EncoderDeltaValue<0) {EncoderDeltaValue+=4;}
		  if (EncoderDeltaValue ==1) {
			  encoder->direction=CW;
			  encoder->EncoderValue++;
		  }
		  else if (EncoderDeltaValue ==3){
			  encoder->direction=CCW;
			  encoder->EncoderValue--;
		  }
		  encoder->PreviusGrayCode=EncoderGrayCode;
	 }
#else
	  if (encoder->EncoderValue >=0){ encoder->direction = CW;}
	  else {encoder->direction = CCW;}
#endif
}
