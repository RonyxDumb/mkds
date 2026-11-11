#pragma once

#include "types.h"

typedef struct SbServer SbServer;
typedef struct SBQueryEngine SBQueryEngine;

typedef struct BasicGoaQuery {
    /* 00 */ u8 mUnk_00[13];
} BasicGoaQuery;

typedef struct FullGoaQuery {
    /* 0 */ u8 mUnk_00[8];
} FullGoaQuery;

typedef struct Unk0218ad44 {
    /* 0 */ u8 mUnk_00[4];
} Unk0218ad44;

extern BasicGoaQuery gBasicGoaQuery;
extern FullGoaQuery gFullGoaQuery;

void SBQueryEngineInit(SBQueryEngine *engine, s32 updateLimit, u32 queryVersion, s32 lanBrowse, UnkFunc *callback,
                       void *instance);
void QEStartQuery(SBQueryEngine *engine, SbServer *server);
