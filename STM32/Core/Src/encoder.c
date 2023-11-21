#include "encoder.h"
#include "main.h"

void GetEncoderValue(encoder_data *encoder){
	  int EncoderGrayCode = 0;
	  int GrayCodeConvert[]={0,1,3,2};
	  //reading encoder value as gray code
	  EncoderGrayCode = GrayCodeConvert[(HAL_GPIO_ReadPin(encoder_A_GPIO_Port, encoder_A_Pin) <<1 | HAL_GPIO_ReadPin(encoder_B_GPIO_Port, encoder_B_Pin)) & 0x03];
	  //if encoder value updated
	  if (encoder->PreviusGrayCode != EncoderGrayCode){
		  int EncoderDeltaValue;
		  EncoderDeltaValue = EncoderGrayCode-encoder->PreviusGrayCode;
		  if (EncoderDeltaValue<0) {EncoderDeltaValue+=4;}
		  if (EncoderDeltaValue ==1) {
			  encoder->direction=CCW;
			  encoder->EncoderValue++;
		  }
		  else if (EncoderDeltaValue ==3){
			  encoder->direction=CCW;
			  encoder->EncoderValue--;
		  }
		  encoder->PreviusGrayCode=EncoderGrayCode;
	  }
}
