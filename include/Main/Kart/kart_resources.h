#pragma once

#include "types.h"

typedef struct Kart Kart;

void InitKartResources(Kart *kart);
void InitKartMapObjectResponses(void);

extern u32 gCoursePushStrongEnabled;
extern void *gLowestOffsetFarCheck;
extern void *gCollideKartWithMapObjectResponses[15];
extern void *gKartMapObjectSecondResponses[15];
