#include "unity.h"
#include "stdint.h"
#include "Time.h"
#include "SD2.h"
#include "Button.h"

int delay120ms = 120;
int delay500ms = 500;

void SD2(State *state, uint32_t previousTime){

	if(pushButton() == 1)
		delay500ms = 100;
	else
		delay500ms = 500;

	switch(*state){
	case INITIAL:
		// turnOnLED2();
		if(delay(delay500ms, previousTime)){
			*state = LEDON;
			previousTime = getCurrentTime();
		}
		break;

	case LEDON:
		// turnOnLED2();
		if(delay(delay500ms, previousTime)){
			*state = LEDOFF;
			previousTime = getCurrentTime();
		}
		break;

	case LEDOFF:
		// turnOffLED2();
		if(delay(delay500ms, previousTime)){
			*state = LEDON;
			previousTime = getCurrentTime();
		}
		break;
	}
}
