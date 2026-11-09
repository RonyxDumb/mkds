#pragma once

#include "types.h"
#include "Main/Unknown/code_020467d0.h" // StateCallbacks
#include "Main/Unknown/code_020d6dc0.h" // Quaternion
#include "Main/Unknown/code_0210b000.h" // SoundStartParams
#include "Main/Unknown/code_020dc474.h" // Wanwan

typedef struct CourseMapRow CourseMapRow;

extern SoundStartParams data_0216bedc;
extern Quaternion data_0216beec;
extern StateCallbacks data_0216befc[];

void UpdateWanwanState5(Wanwan *wanwan);
void func_020dc1d8(Wanwan *wanwan, CourseMapRow *row);
void func_020dc11c(Wanwan *wanwan, CourseMapRow *row);
void ResetWanwan(Wanwan *wanwan);
void CreateWanwanAndRockShadow(void);
