#pragma once

#include "types.h"
#include "Main/Menu/second_menu_scene.h" // StateCallbacks
#include "Main/Unknown/code_020d6dc0.h" // Quaternion
#include "Main/Unknown/code_0210b000.h" // SoundStartParams
#include "Main/Unknown/code_020dc474.h" // Wanwan

typedef struct CourseMapRow CourseMapRow;

extern SoundStartParams data_0216bedc;
extern Quaternion data_0216beec;
extern StateCallbacks gWanwanStateTable[];

void UpdateWanwanState5(Wanwan *wanwan);
void InitWanwanOnChain(Wanwan *wanwan, CourseMapRow *row);
void InitWanwanOnPath(Wanwan *wanwan, CourseMapRow *row);
void ResetWanwan(Wanwan *wanwan);
void CreateWanwanAndRockShadow(void);
