#include <stdio.h>
#include "unity.h"
#include "cmock.h"
#include "SD.h"
#include "mock_Time.h"
#include "mock_Button.h"


void setUp(void){}
void tearDown(void){}

void test_SD_should_remain_INITIAL__without_enough_delay(){

State state = INITIAL;
uint32_t previousTime = 0;

delay_ExpectAndReturn(120, 0, 0);

SD(&state, previousTime);

TEST_ASSERT_EQUAL(INITIAL, state);

}

void test_SD_should_go_to_LEDON_after_exceeding_delay(){

State state = INITIAL;
uint32_t previousTime = 0;

delay_ExpectAndReturn(120, 0, 1);
getCurrentTime_IgnoreAndReturn(118);
SD(&state, previousTime);

TEST_ASSERT_EQUAL(LEDON, state);

}

void test_SD_should_go_to_LEDOFF_after_240ms(){

State state = INITIAL;
uint32_t previousTime = 0;

delay_ExpectAndReturn(120, 0, 1);
getCurrentTime_IgnoreAndReturn(120);
SD(&state, previousTime);

delay_ExpectAndReturn(120, 120, 1);
getCurrentTime_IgnoreAndReturn(240);
SD(&state, 120);

TEST_ASSERT_EQUAL(LEDOFF, state);

}

void test_SD_should_go_to_LEDON_after_360ms(){

State state = INITIAL;
uint32_t previousTime = 0;

delay_ExpectAndReturn(120, 0, 1);
getCurrentTime_IgnoreAndReturn(120);
SD(&state, previousTime);

delay_ExpectAndReturn(120, 120, 1);
getCurrentTime_IgnoreAndReturn(240);
SD(&state, 120);

delay_ExpectAndReturn(120, 240, 1);
getCurrentTime_IgnoreAndReturn(360);
SD(&state, 240);

TEST_ASSERT_EQUAL(LEDON, state);

}