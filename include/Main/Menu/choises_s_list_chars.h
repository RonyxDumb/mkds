#pragma once

#include "types.h"

u32 GetChoisesSListCharsSize(int valueCount);

void StartChoisesSSelectedValueSeq(void);

typedef struct Ncgr Ncgr;
typedef struct Nclr Nclr;

unsigned int IsChoisesSPickLocked(void);
void *GetChoisesSListScreenMapData(void);
Ncgr *GetChoisesSBNcgrWithListChars(void);
Nclr *GetChoisesSBNclr(void);
