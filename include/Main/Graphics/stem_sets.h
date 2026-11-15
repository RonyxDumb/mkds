#pragma once

#include "types.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/MapObjects/data_02155000.h"

typedef struct TimedQuad TimedQuad;

enum {
    STEM_SET_COUNT,
    STEM_SET_START,
    STEM_SET_COUNT_COPY,
    STEM_SET_GOAL,
    STEM_SET_WIN,
    STEM_SET_LOSE,
    STEM_SET_COMPLETE,
    STEM_SET_FAILED,
    STEM_SET_CURRENT,
    STEM_SET_NONE,
};

void StartTimedQuadFromTable(u32 tableIndex);

void UpdateTimedQuad(TimedQuad *timedQuad);
void WriteQuadVertex(int vertexIndex);

void StartTimedQuad(TimedQuad *timedQuad);

void SetStemSet(s32 setIndex);

void Nop(void);

extern struct StemSets *gStemSets;

extern void (*const gTimedQuadStartFunctions[1])(TimedQuad *a);
extern void (*const gTimedQuadUpdateFunctions[1])(TimedQuad *a);
extern const u16 gTimedQuadVertices[12];

extern const StemSetParams gCountStartStems[3];
