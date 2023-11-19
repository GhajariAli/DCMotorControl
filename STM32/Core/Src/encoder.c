#include "encoder.h"

void GetEncoderValue(encoder_data *encoder){
	  int EncoderAState = 0;
	  int EncoderBState = 0;
	  int EncoderGrayCode = 0;
	  //reading encoder value as gray code
	  HAL_GPIO_ReadPin(ENCODER_PORT, ENCODER_PIN_A) ? (EncoderAState=1) : (EncoderAState=0);
	  HAL_GPIO_ReadPin(ENCODER_PORT, ENCODER_PIN_B) ? (EncoderBState=1) : (EncoderBState=0);
	  EncoderGrayCode= ( EncoderAState<<1 | EncoderBState ) & 0x03;
	  //if encoder value updated
	  if (encoder->EncoderLastState != EncoderGrayCode){
		  for (int i=3;i>0;i--){
			  encoder->EncoderState[i]= encoder->EncoderState[i-1];
		  }
		  encoder->EncoderState[0]= EncoderGrayCode;
		  //check direction of rotation
		  for (int i=0; i<4 ; i++){
			  if (encoder->EncoderState[i]==3){
				  switch (i){
					  case 0:
						  if (encoder->EncoderState[1]==2) encoder->direction=CCW;
						  else if (encoder->EncoderState[3]==2) encoder->direction=CW;
					  case 3:
						  if (encoder->EncoderState[2]==2) encoder->direction=CCW;
						  else if (encoder->EncoderState[0]==2) encoder->direction=CW;
					  default:
						  if (encoder->EncoderState[i+1]==2) encoder->direction=CCW;
						  else if (encoder->EncoderState[i-1]==2) encoder->direction=CW;
				  }
			  }
			  break;
		  }
		  if (encoder->direction == CW) encoder->EncoderValue++;
		  else if (encoder->direction == CCW) encoder->EncoderValue--;
		  encoder->EncoderLastState=EncoderGrayCode;
	  }
}
