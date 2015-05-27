#include <stdio.h>
#include "unity.h"
#include "cmock.h"
#include "SD2.h"
#include "mock_Time.h"
#include "mock_Button.h"

void setUp(void){}
void tearDown(void){}

void test_SD2_should_remain_INITIAL_without_enough_delay_switch_0(){

State state = INITIAL;
uint32_t previousTime = 0;

pushButton_IgnoreAndReturn(0);
delay_ExpectAndReturn(500, 0, 0);

SD2(&state, previousTime);

TEST_ASSERT_EQUAL(INITIAL, state);

}

void test_SD2_should_go_to_LEDON_after_exceeding_delay(){

State state = INITIAL;
uint32_t previousTime = 0;

pushButton_IgnoreAndReturn(0);
delay_ExpectAndReturn(500, 0, 1);
getCurrentTime_IgnoreAndReturn(500);
SD2(&state, previousTime);

TEST_ASSERT_EQUAL(LEDON, state);

}

void test_SD2_should_go_to_LEDOFF_after_1000ms(){

State state = INITIAL;
uint32_t previousTime = 0;

pushButton_IgnoreAndReturn(0);
delay_ExpectAndReturn(500, 0, 1);
getCurrentTime_IgnoreAndReturn(500);
SD2(&state, previousTime);

pushButton_IgnoreAndReturn(0);
delay_ExpectAndReturn(500, 500, 1);
getCurrentTime_IgnoreAndReturn(1000);
SD2(&state, 500);

TEST_ASSERT_EQUAL(LEDOFF, state);

}

void test_SD2_should_go_to_LEDON_after_1500ms(){

State state = INITIAL;
uint32_t previousTime = 0;

pushButton_IgnoreAndReturn(0);
delay_ExpectAndReturn(500, 0, 1);
getCurrentTime_IgnoreAndReturn(500);
SD2(&state, previousTime);

pushButton_IgnoreAndReturn(0);
delay_ExpectAndReturn(500, 500, 1);
getCurrentTime_IgnoreAndReturn(1000);
SD2(&state, 500);

pushButton_IgnoreAndReturn(0);
delay_ExpectAndReturn(500, 1000, 1);
getCurrentTime_IgnoreAndReturn(1500);
SD2(&state, 1000);

TEST_ASSERT_EQUAL(LEDON, state);

}

void test_SD2_delay_should_become_100_when_switch_pushed(){

State state = INITIAL;
uint32_t previousTime = 0;

pushButton_IgnoreAndReturn(1);
delay_ExpectAndReturn(100, 0, 1);
getCurrentTime_IgnoreAndReturn(100);
SD2(&state, previousTime);

TEST_ASSERT_EQUAL(LEDON, state);
}

void test_SD2_delay_should_become_100_when_switch_pushed_500_when_off(){

State state = INITIAL;
uint32_t previousTime = 0;

pushButton_IgnoreAndReturn(1);
delay_ExpectAndReturn(100, 0, 1);
getCurrentTime_IgnoreAndReturn(100);
SD2(&state, previousTime);

pushButton_IgnoreAndReturn(0);
delay_ExpectAndReturn(500, 100, 1);
getCurrentTime_IgnoreAndReturn(600);
SD2(&state, 100);

TEST_ASSERT_EQUAL(LEDOFF, state);
}