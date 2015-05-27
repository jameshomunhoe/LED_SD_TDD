#include "unity.h"
#include "SD3.h"
#include "Time.h"
#include "Button.h"

int delay120ms = 120;
int delay500ms = 500;


void SD3(State *state, uint32_t previousTime, int counter){


	switch(*state){
	case INITIAL:
		counter = 0;
		// turnOffLED3();
		if(pushButton() == 1){
			*state = LEDON;
			previousTime = getCurrentTime();
		}
		break;

	case LEDON:
		// turnOnLED3();
		if(delay(100, previousTime)){
			*state = LEDOFF;
			previousTime = getCurrentTime();
			counter++;
		}

		break;

	case LEDOFF:
		// turnOffLED3();
		if(delay(100, previousTime)){
			*state = LEDON;
			previousTime = getCurrentTime();
		}
		if(counter > 5)
			*state = INITIAL;
		break;
	}
}
