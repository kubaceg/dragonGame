#ifndef PROJECT_LOOP_H
#define PROJECT_LOOP_H

#include "SDL.h"

class Loop {
 protected:
  void FPS_Initial(void);

  void FPS_Fn(void);

  void handleEvent();

  int NextTick, interval, aTick = 0;
  int FPS = 60;
  bool running;
};

#endif
