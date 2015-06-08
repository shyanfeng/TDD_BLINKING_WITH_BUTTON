#include "unity.h"
#include "LEDSM.h"
#include "Message.h"

void setUp(void){}

void tearDown(void){}

void test_led_init(void){
  LedData ledData;
  
  ledInitData(&ledData);
  
  TEST_ASSERT_EQUAL(ledData.state, LED_OFF);
}

void test_led_do_nothing(void){
  LedData ledData;
  
  ledInitData(&ledData);
  msg = DO_NOTHING;
  ledSM(&ledData);
  
  TEST_ASSERT_EQUAL(ledData.state, LED_OFF);
}

void test_led_change_mode(void){
  LedData ledData;
  
  ledInitData(&ledData);
  msg = CHANGE_MODE;
  ledSM(&ledData);
  
  TEST_ASSERT_EQUAL(ledData.state, LED_BLINKING_ON);
}

void test_led_at_blinking_on_do_nothing(void){
  LedData ledData;
  
  ledInitData(&ledData);
  msg = CHANGE_MODE;
  ledSM(&ledData);
  
  TEST_ASSERT_EQUAL(ledData.state, LED_BLINKING_ON);
  
  msg = DO_NOTHING;
  ledSM(&ledData);
  
  TEST_ASSERT_EQUAL(ledData.state, LED_BLINKING_OFF);
  
  msg = DO_NOTHING;
  ledSM(&ledData);
  
  TEST_ASSERT_EQUAL(ledData.state, LED_BLINKING_ON);
  
  msg = DO_NOTHING;
  ledSM(&ledData);
  
  TEST_ASSERT_EQUAL(ledData.state, LED_BLINKING_OFF);
}

void test_led_at_blinking_on_change_mode(void){
  LedData ledData;
  
  ledInitData(&ledData);
  msg = CHANGE_MODE;
  ledSM(&ledData);
  
  TEST_ASSERT_EQUAL(ledData.state, LED_BLINKING_ON);
  
  msg = CHANGE_MODE;
  ledSM(&ledData);
  
  TEST_ASSERT_EQUAL(ledData.state, LED_ON);
  
}

void test_led_at_blinking_off_change_mode(void){
  LedData ledData;
  
  ledInitData(&ledData);
  msg = CHANGE_MODE;
  ledSM(&ledData);
  
  TEST_ASSERT_EQUAL(ledData.state, LED_BLINKING_ON);
  
  msg = DO_NOTHING;
  ledSM(&ledData);
  
  TEST_ASSERT_EQUAL(ledData.state, LED_BLINKING_OFF);
  
  msg = CHANGE_MODE;
  ledSM(&ledData);
  
  TEST_ASSERT_EQUAL(ledData.state, LED_ON);
  
}
