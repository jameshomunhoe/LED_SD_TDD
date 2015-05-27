#include <stdio.h>
#include "unity.h"
#include "stdint.h"
#include "Time.h"
#include "SD.h"
#include "Button.h"

int delay120ms = 120;
int delay500ms = 500;


void SD(State *state, uint32_t previousTime){
	switch(*state){

	case INITIAL:
		// turnOffLED1();
		if(delay(delay120ms, previousTime)){
			*state = LEDON;
			previousTime = getCurrentTime();
		}
		break;

	case LEDON:
		// turnOnLED1();
		if(delay(delay120ms, previousTime)){
			*state = LEDOFF;
			previousTime = getCurrentTime();
		}
		break;

	case LEDOFF:
		// turnOffLED1();
		if(delay(delay120ms, previousTime)){
			*state = LEDON;
			previousTime = getCurrentTime();
		}
		break;
	}
}