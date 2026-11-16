#pragma once

#include "types.h"

typedef struct SceneNumbers SceneNumbers;

// The results scene: its main and sub OAM buffers and the mode.
typedef struct ResultScene {
    /* 000 */ u8 mMainOam[0x404];
    /* 404 */ u8 mSubOam[0x404];
    /* 808 */ s32 mMode;
} ResultScene;

void WriteResultsByMode(void);
void ReleaseResultsByMode(void);
void AdvanceResultsByMode(SceneNumbers *sceneNumbers);
void InitResultsByMode(void *heap);

// Objects whose layout isn't known yet.
extern struct ResultScene *gResultScene;
