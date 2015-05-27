#ifndef SD_H
#define SD_H

typedef enum{
	INITIAL,
	LEDOFF,
	LEDON
}State;

void SD(State *state, uint32_t previousTime);

#endif // SD_H