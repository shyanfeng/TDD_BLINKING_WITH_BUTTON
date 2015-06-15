#ifndef Task_Block_H
#define Task_Block_H

#include "stdint.h"


typedef enum {
  RUNNING,
  READY,
  SPAWNED,
  TERMINATED,
  BLOCKING,
  SLEEPING
} TaskState;

typedef struct {
  TaskState state;
  uint32_t stack;
} Tcb;

#endif // Task_Block_H
