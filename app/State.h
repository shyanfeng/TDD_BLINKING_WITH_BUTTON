#ifndef State_H
#define State_H

typedef enum {
  INITIAL,
  PRESS,
  RELEASE,
  LED_ON,
  LED_OFF,
  LED_BLINKING_ON,
  LED_BLINKING_OFF,
} State;

#endif // State_H
