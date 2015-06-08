#ifndef LEDSM_H
#define LEDSM_H

#include <stdint.h>
#include "State.h"

typedef struct {
  State state;
  uint32_t time;
} LedData;

void ledInitData(LedData *data);
void ledSM(LedData *data);

#endif // LEDSM_H
