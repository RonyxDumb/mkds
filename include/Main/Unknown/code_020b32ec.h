#pragma once

#include "types.h"

typedef struct Ncgr Ncgr;
typedef struct Nclr Nclr;

unsigned int rchoi_getIsExittingRace(void);
void *rchoi_getMapData(void);
Ncgr *rchoi_getCharData(void);
Nclr *rchoi_getPalData(void);
