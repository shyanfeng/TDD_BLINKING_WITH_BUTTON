#include "unity.h"
#include "Message.h"
#include "ButtonSM.h"
#include "LEDSM.h"
#include "mock_pushButton1.h"

void setUp(void){}

void tearDown(void){}

void test_message_passing_given_send_a_message_LedState_should_change_to_LED_ON(void){
  LedData ledData;
  ButtonData buttonData;
  
  ledInitData(&ledData);
  buttonInitData(&buttonData);
  
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state, LED_OFF);
  
  isButtonPressed_ExpectAndReturn(true);
  buttonSM(&buttonData);
  
  TEST_ASSERT_EQUAL(buttonData.state, PRESS);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(ledData.state, LED_ON);
  
}
