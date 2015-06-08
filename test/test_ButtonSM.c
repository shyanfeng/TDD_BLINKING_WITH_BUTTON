#include "unity.h"
#include "ButtonSM.h"
#include "Message.h"
#include "LEDSM.h"
#include "mock_pushButton1.h"

void setUp(void){}

void tearDown(void){}

void test_button_init(void){
  ButtonData buttonData;
  
  buttonInitData(&buttonData);
  
  TEST_ASSERT_EQUAL(buttonData.state, RELEASE);
}

void test_button_PRESS(void){
  ButtonData buttonData;
  
  buttonInitData(&buttonData);
  
  isButtonPressed_ExpectAndReturn(true);
  buttonSM(&buttonData);
  
  TEST_ASSERT_EQUAL(buttonData.state, PRESS);
}

void test_button_RELEASE(void){
  ButtonData buttonData;
  
  buttonInitData(&buttonData);
  
  isButtonPressed_ExpectAndReturn(true);
  buttonSM(&buttonData);
  isButtonPressed_ExpectAndReturn(false);
  buttonSM(&buttonData);
  
  TEST_ASSERT_EQUAL(buttonData.state, RELEASE);
}

void test_button_stay_PRESS(void){
  ButtonData buttonData;
  
  buttonInitData(&buttonData);
  
  isButtonPressed_ExpectAndReturn(true);
  buttonSM(&buttonData);
  isButtonPressed_ExpectAndReturn(true);
  buttonSM(&buttonData);
  
  TEST_ASSERT_EQUAL(buttonData.state, PRESS);
}
