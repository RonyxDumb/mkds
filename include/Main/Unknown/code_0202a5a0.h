#pragma once

#include "types.h"

typedef struct Unk0203a0dc Unk0203a0dc;

// Object behind gResultScene, 0x80c bytes (InitResultsByMode allocates it).
typedef struct ResultScene {
    /* 000 */ u8 mMainOam[0x404];
    /* 404 */ u8 mSubOam[0x404];
    /* 808 */ s32 mMode;
} ResultScene;

void func_0202a5a0(void);
void func_0202a5d8(void);
void AdvanceResultsByMode(Unk0203a0dc *sceneNumbers);
void InitResultsByMode(void *heap);
