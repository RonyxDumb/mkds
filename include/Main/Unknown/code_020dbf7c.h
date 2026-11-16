#pragma once

#include "types.h"
#include "Main/Unknown/code_020d6dc0.h" // Quaternion
#include "Main/Unknown/code_0210b000.h" // Unk0210b7a8
#include "Main/Unknown/code_020dc474.h" // Wanwan

typedef struct CourseMapRow CourseMapRow;

extern Unk0210b7a8 data_0216bedc;
extern Quaternion data_0216beec;
extern UnkFunc *wanwan_sStates[];

void wanwan_state5Update(Wanwan *wanwan);
void wanwan_initFixed(Wanwan *wanwan, CourseMapRow *row);
void wanwan_initMoving(Wanwan *wanwan, CourseMapRow *row);
void wanwan_20DBF7C(Wanwan *wanwan);
void wanwan_loadModels(void);
