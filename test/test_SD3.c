#include <stdio.h>
#include "unity.h"
#include "cmock.h"
#include "SD3.h"
#include "mock_Time.h"
#include "mock_Button.h"

void setUp(void){}
void tearDown(void){}

void test_SD3_should_remain_INITIAL__without_pressing_button(){

State state = INITIAL;
uint32_t previousTime = 0;
int counter = 0;

pushButton_IgnoreAndReturn(0);

SD3(&state, previousTime, counter);

TEST_ASSERT_EQUAL(INITIAL, state);

}

void test_SD3_should_go_to_LEDON_after_pressing_button(){

State state = INITIAL;
uint32_t previousTime = 0;
int counter = 0;

pushButton_IgnoreAndReturn(1);
getCurrentTime_IgnoreAndReturn(5);
SD3(&state, previousTime, counter);

TEST_ASSERT_EQUAL(LEDON, state);

}

void test_SD3_should_go_to_LEDON_to_LEDOFF_and_LEDON_with_100ms_delay(){

State state = INITIAL;
uint32_t previousTime = 0;
int counter = 0;

pushButton_IgnoreAndReturn(1);
getCurrentTime_IgnoreAndReturn(5);
SD3(&state, previousTime, counter);

delay_ExpectAndReturn(100, 5, 1);
getCurrentTime_IgnoreAndReturn(105);
SD3(&state, 5, counter);

delay_ExpectAndReturn(100, 105, 1);
getCurrentTime_IgnoreAndReturn(205);
SD3(&state, 105, counter);

TEST_ASSERT_EQUAL(LEDON, state);

}

void test_SD3_should_go_back_to_INITIAL_after_5_blink(){

State state = INITIAL;
uint32_t previousTime = 0;

pushButton_IgnoreAndReturn(1);
getCurrentTime_IgnoreAndReturn(5);
SD3(&state, previousTime, 0);

delay_ExpectAndReturn(100, 0, 1);
getCurrentTime_IgnoreAndReturn(100);
SD3(&state, 0, 0);

delay_ExpectAndReturn(100, 100, 1);
getCurrentTime_IgnoreAndReturn(200);
SD3(&state, 100, 1);

delay_ExpectAndReturn(100, 200, 1);
getCurrentTime_IgnoreAndReturn(300);
SD3(&state, 200, 1);

delay_ExpectAndReturn(100, 300, 1);
getCurrentTime_IgnoreAndReturn(400);
SD3(&state, 300, 2);

delay_ExpectAndReturn(100, 400, 1);
getCurrentTime_IgnoreAndReturn(500);
SD3(&state, 400, 2);

delay_ExpectAndReturn(100, 500, 1);
getCurrentTime_IgnoreAndReturn(600);
SD3(&state, 500, 3);

delay_ExpectAndReturn(100, 600, 1);
getCurrentTime_IgnoreAndReturn(700);
SD3(&state, 600, 3);

delay_ExpectAndReturn(100, 700, 1);
getCurrentTime_IgnoreAndReturn(800);
SD3(&state, 700, 4);

delay_ExpectAndReturn(100, 800, 1);
getCurrentTime_IgnoreAndReturn(900);
SD3(&state, 800, 4);

delay_ExpectAndReturn(100, 900, 1);
getCurrentTime_IgnoreAndReturn(1000);
SD3(&state, 900, 5);

delay_ExpectAndReturn(100, 1000, 1);
getCurrentTime_IgnoreAndReturn(1100);
SD3(&state, 1000, 5);

delay_ExpectAndReturn(100, 1100, 1);
getCurrentTime_IgnoreAndReturn(1200);
SD3(&state, 1100, 6);

TEST_ASSERT_EQUAL(INITIAL, state);

}