#ifndef Mutex_H
#define Mutex_H

#include <stdint.h>
#include "TaskControl.h"

void initMutex();
void acquireMutex();
void releaseMutex();

typedef struct {
  Tcb *owner;
  // List *queue;
} Mutex;

#endif // Mutex_H
