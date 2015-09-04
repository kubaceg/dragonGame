#ifndef PROJECT_LOOP_H
#define PROJECT_LOOP_H

#include "SDL.h"

class Loop {
 protected:
  void FPS_Initial(void);

  void FPS_Fn(void);

  virtual void handleEvent() = 0;

  int NextTick, interval, aTick = 0;
  const int FPS = 60;
};

#endif
