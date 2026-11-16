#pragma once

#include "types.h"

// Object behind result_sState, 0x80c bytes (result_init allocates it).
typedef struct ResultScene {
    /* 000 */ u8 mMainOam[0x404];
    /* 404 */ u8 mSubOam[0x404];
    /* 808 */ s32 mMode;
} ResultScene;

void result_vblank(void);
void result_finalize(void);
void result_update(u32 sceneNumbers);
void result_init(void *heap);
