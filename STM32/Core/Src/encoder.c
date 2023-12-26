#include "encoder.h"
#include "main.h"

void GetEncoderValue(encoder_data *encoder){
	  int EncoderGrayConvert[8] ={0,0,0,0,0,0,0,0};
	  int GrayCode=0;
	  int GrayMSBDetected = 0;
	  //reading encoder value as gray code
#ifdef ENCODER_GPIO_MODE
	  //EncoderGrayCode = GrayCodeConvert[(HAL_GPIO_ReadPin(Encoder_A_GPIO_Port, Encoder_A_Pin) <<1 | HAL_GPIO_ReadPin(Encoder_B_GPIO_Port, Encoder_B_Pin)) & 0x03];
	  int b[8];
	  b[0]=!HAL_GPIO_ReadPin(Encoder_0_GPIO_Port, Encoder_0_Pin);
	  b[1]=!HAL_GPIO_ReadPin(Encoder_1_GPIO_Port, Encoder_1_Pin);
	  b[2]=!HAL_GPIO_ReadPin(Encoder_2_GPIO_Port, Encoder_2_Pin);
	  b[3]=!HAL_GPIO_ReadPin(Encoder_3_GPIO_Port, Encoder_3_Pin);
	  b[4]=!HAL_GPIO_ReadPin(Encoder_4_GPIO_Port, Encoder_4_Pin);
	  b[5]=!HAL_GPIO_ReadPin(Encoder_5_GPIO_Port, Encoder_5_Pin);
	  b[6]=!HAL_GPIO_ReadPin(Encoder_6_GPIO_Port, Encoder_6_Pin);
	  b[7]=!HAL_GPIO_ReadPin(Encoder_7_GPIO_Port, Encoder_7_Pin);
	  encoder->EncoderRawValue =(b[7] <<7 | b[6] <<6 | b[5] <<5 | b[4] <<4 | b[3] <<3 | b[2] <<2 | b[1] <<1 | b[0]) & 0b11111111;
	  //To convert Gray to Binary write the most significant bit MSB then compare the next bit with that if similar put 0 if different put 1
	  for (int index = 7 ; index >= 0 ; index--){
	          if ((b[index]==1) & ! (GrayMSBDetected)) {
	        	  EncoderGrayConvert[index]=b[index];
	              GrayMSBDetected=index;
	          }
	          if(GrayMSBDetected){
	              if (EncoderGrayConvert[index+1]==b[index]) EncoderGrayConvert[index]=0;
	              else EncoderGrayConvert[index]=1;
	          }
	  }
	  encoder->GrayCode  = GrayCode =((   EncoderGrayConvert[7] <<7 |
										  EncoderGrayConvert[6] <<6 |
										  EncoderGrayConvert[5] <<5 |
										  EncoderGrayConvert[4] <<4 |
										  EncoderGrayConvert[3] <<3 |
										  EncoderGrayConvert[2] <<2 |
										  EncoderGrayConvert[1] <<1 |
										  EncoderGrayConvert[0]) & 0b11111111);
#endif
#ifdef ENCODER_INTERRUPT_MODE
	  EncoderGrayCode = GrayCodeConvert[(encoder->IT_EncoderChA <<1 | encoder->IT_EncoderChB) & 0x03];
#endif

#ifndef ENCODER_TIMER_MODE //the value will be written in main.c in timer interrupt function
	  //if encoder value updated
	  if (encoder->PreviusGrayCode != GrayCode){
		  int EncoderDeltaValue;
		  EncoderDeltaValue = GrayCode-encoder->PreviusGrayCode;
		  if (EncoderDeltaValue<0) {EncoderDeltaValue+=4;}
		  if (EncoderDeltaValue ==1) {
			  encoder->direction=CW;
			  encoder->EncoderValue++;
		  }
		  else if (EncoderDeltaValue ==3){
			  encoder->direction=CCW;
			  encoder->EncoderValue--;
		  }
		  encoder->PreviusGrayCode=GrayCode;
	 }
#else
	  if (encoder->EncoderValue >=0){ encoder->direction = CW;}
	  else {encoder->direction = CCW;}
#endif
}
