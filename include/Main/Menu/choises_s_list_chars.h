#pragma once

#include "types.h"

u32 ComputeSomeMESize_from_thumb(int valueCount);

void StartChoisesSSelectedValueSeq(void);

typedef struct Ncgr Ncgr;
typedef struct Nclr Nclr;

unsigned int IsChoisesSPickLocked(void);
void *GetChoisesSListScreenMapData(void);
Ncgr *GetSomeBgTileData_from_thumb(void);
Nclr *GetChoises_s_b_Pallette_from_thumb(void);
