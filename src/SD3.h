#ifndef SD3_H
#define SD3_H

typedef enum{
	INITIAL,
	LEDOFF,
	LEDON
}State;

void SD3(State *state, uint32_t previousTime, int counter);

#endif // SD3_H