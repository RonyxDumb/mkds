#pragma once

#include "types.h"
#include "Main/MapObjects/data_0217b000.h"

typedef struct TimedQuad TimedQuad;

void StartTimedQuadFromTable(u32 tableIndex);

void UpdateTimedQuad(TimedQuad *timedQuad);
void WriteQuadVertex(int vertexIndex);

void StartTimedQuad(TimedQuad *timedQuad);

void SetStemSet(s32 setIndex);

unsigned int ReturnArgument(unsigned int value);

extern struct StemSets *gStemSets;

extern void (*const gTimedQuadStartFunctions[1])(TimedQuad *a);
extern void (*const gTimedQuadUpdateFunctions[1])(TimedQuad *a);
extern const u16 gTimedQuadVertices[12];
