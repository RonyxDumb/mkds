#pragma once

#include "types.h"
#include "Main/MapObjects/data_0217b000.h"

typedef struct TimedQuad TimedQuad;

extern void (*data_02155ec8[])(TimedQuad *a);
extern void (*data_02155ecc[])(TimedQuad *a);

void StartTimedQuadFromTable(u32 tableIndex);

void UpdateTimedQuad(TimedQuad *timedQuad);
void WriteQuadVertex(int vertexIndex);

void StartTimedQuad(TimedQuad *timedQuad);

void SetStemSet(s32 setIndex);

unsigned int ReturnArgument(unsigned int value);

extern struct StemSets *gStemSets;
