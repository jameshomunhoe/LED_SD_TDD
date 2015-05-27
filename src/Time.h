#ifndef Time_H
#define Time_H
#include "unity.h"

extern int currentTime;

uint32_t getCurrentTime();
int delay(uint32_t delayCycle, uint32_t previousTime);

#endif // Time_H