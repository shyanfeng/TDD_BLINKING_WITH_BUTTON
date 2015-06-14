#include "unity.h"
#include "LEDSM.h"
#include "ButtonSM.h"
#include "Message.h"
#include "mock_pushButton1.h"

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

void test_led_on_do_nothing(void){
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
  
  msg = DO_NOTHING;
  ledSM(&ledData);
  
  TEST_ASSERT_EQUAL(ledData.state, LED_ON);
  
  msg = DO_NOTHING;
  ledSM(&ledData);
  
  TEST_ASSERT_EQUAL(ledData.state, LED_ON);
  
}

void test_led_on_change_mode(void){
  LedData ledData;
  
  ledInitData(&ledData);
  msg = CHANGE_MODE;
  ledSM(&ledData);
  
  TEST_ASSERT_EQUAL(ledData.state, LED_BLINKING_ON);
  
  msg = CHANGE_MODE;
  ledSM(&ledData);
  
  TEST_ASSERT_EQUAL(ledData.state, LED_ON);
  
  msg = CHANGE_MODE;
  ledSM(&ledData);
  
  TEST_ASSERT_EQUAL(ledData.state, LED_OFF);
  
}

void test_led_with_button(void){
  ButtonData buttonData;
  LedData ledData;
  
  buttonInitData(&buttonData);
  ledInitData(&ledData);
  TEST_ASSERT_EQUAL(buttonData.state, RELEASE);
  TEST_ASSERT_EQUAL(ledData.state, LED_OFF);
  
  isButtonPressed_ExpectAndReturn(true);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state, PRESS);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state, LED_BLINKING_ON);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state, LED_BLINKING_OFF);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state, LED_BLINKING_ON);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state, LED_BLINKING_OFF);
  isButtonPressed_ExpectAndReturn(false);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state, RELEASE);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state, LED_BLINKING_ON);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state, LED_BLINKING_OFF);
  isButtonPressed_ExpectAndReturn(true);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state, PRESS);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state, LED_ON);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state, LED_ON);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state, LED_ON);
  isButtonPressed_ExpectAndReturn(false);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state, RELEASE);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state, LED_ON);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state, LED_ON);
  isButtonPressed_ExpectAndReturn(true);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state, PRESS);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state, LED_OFF);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state, LED_OFF);
  isButtonPressed_ExpectAndReturn(false);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state, RELEASE);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state, LED_OFF);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state, LED_OFF);
  
  //second time
  isButtonPressed_ExpectAndReturn(true);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state, PRESS);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state, LED_BLINKING_ON);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state, LED_BLINKING_OFF);
  isButtonPressed_ExpectAndReturn(false);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state, RELEASE);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state, LED_BLINKING_ON);
  isButtonPressed_ExpectAndReturn(true);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state, PRESS);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state, LED_ON);
  isButtonPressed_ExpectAndReturn(false);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state, RELEASE);
  isButtonPressed_ExpectAndReturn(true);
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(buttonData.state, PRESS);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state, LED_OFF);

}