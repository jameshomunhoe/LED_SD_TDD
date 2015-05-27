#ifndef SD2_H
#define SD2_H

typedef enum{
	INITIAL,
	LEDOFF,
	LEDON
}State;

void SD2(State *state, uint32_t previousTime);

#endif // SD2_H