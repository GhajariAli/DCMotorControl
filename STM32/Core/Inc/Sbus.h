#include "stdint.h"

#define UART_MAX_CHAR 300
#define SBUS_LEN 25
#define SBUS_CHANNELS 18

typedef struct{
	uint8_t ReceivedData[SBUS_LEN];
	uint16_t ch[SBUS_CHANNELS];
}tsbus;

void ParseSBUS(tsbus* sbus);

