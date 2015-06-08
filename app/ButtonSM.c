#include <stdio.h>
#include "ButtonSM.h"
#include "Message.h"
#include "pushButton1.h"

void buttonInitData(ButtonData *data){
  data->state = RELEASE;
}

void buttonSM(ButtonData *data){
  switch(data->state){
    case RELEASE:
      if(isButtonPressed() == 1){
        msg = CHANGE_MODE;
        data->state = PRESS;
      }
      break;
    
    case PRESS:
      if(isButtonPressed() == 0){
        msg = DO_NOTHING;
        data->state = RELEASE;
      }
      msg = DO_NOTHING;
      
      break;
    
    default:
      printf("Error: Unknown state encountered in buttonSM: %d\n", data->state);
      break;
  }

}