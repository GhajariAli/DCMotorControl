#include "Sbus.h"

void ParseSBUS(tsbus* sbus){
	sbus->ch[0]  = ( (sbus->ReceivedData[1]		| sbus->ReceivedData[2]<<8) 								& 0x07FF );
	sbus->ch[1]  = ( (sbus->ReceivedData[2]>>3	| sbus->ReceivedData[3]<<5) 								& 0x07FF );
	sbus->ch[2]  = ( (sbus->ReceivedData[3]>>6	| sbus->ReceivedData[4]<<2 	| sbus->ReceivedData[5]<<10 ) 	& 0x07FF );
	sbus->ch[3]  = ( (sbus->ReceivedData[5]>>1	| sbus->ReceivedData[6]<<7) 								& 0x07FF );
	sbus->ch[4]  = ( (sbus->ReceivedData[6]>>4	| sbus->ReceivedData[7]<<4) 								& 0x07FF );
	sbus->ch[5]  = ( (sbus->ReceivedData[7]>>7	| sbus->ReceivedData[8]<<1	| sbus->ReceivedData[9]<<9 ) 	& 0x07FF );
	sbus->ch[6]  = ( (sbus->ReceivedData[9]>>2 	| sbus->ReceivedData[10]<<6) 								& 0x07FF );
	sbus->ch[7]  = ( (sbus->ReceivedData[10]>>5 | sbus->ReceivedData[11]<<3) 								& 0x07FF );
	sbus->ch[8]  = ( (sbus->ReceivedData[12]	| sbus->ReceivedData[13]<<8) 								& 0x07FF );
	sbus->ch[9]  = ( (sbus->ReceivedData[13]>>3 | sbus->ReceivedData[14]<<5) 								& 0x07FF );
	sbus->ch[10] = ( (sbus->ReceivedData[14]>>6 | sbus->ReceivedData[15]<<2 | sbus->ReceivedData[16]<<10) 	& 0x07FF );
	sbus->ch[11] = ( (sbus->ReceivedData[16]>>1 | sbus->ReceivedData[17]<<7)								& 0x07FF );
	sbus->ch[12] = ( (sbus->ReceivedData[17]>>4 | sbus->ReceivedData[18]<<4)								& 0x07FF );
	sbus->ch[13] = ( (sbus->ReceivedData[18]>>7 | sbus->ReceivedData[19]<<1 | sbus->ReceivedData[20]<<9) 	& 0x07FF );
	sbus->ch[14] = ( (sbus->ReceivedData[20]>>2 | sbus->ReceivedData[21]<<6) 								& 0x07FF );
	sbus->ch[15] = ( (sbus->ReceivedData[21]>>5 | sbus->ReceivedData[22]<<3) 								& 0x07FF );
	sbus->ch[16] = (  sbus->ReceivedData[23] 	& 0x0001 ) ? 2047: 0;
	sbus->ch[17] = (  sbus->ReceivedData[23]>>1 & 0x0001 ) ? 2047: 0;
}
