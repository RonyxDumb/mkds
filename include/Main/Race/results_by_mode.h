#pragma once

#include "types.h"

typedef struct SceneNumbers SceneNumbers;

// The results scene: its NtrMain and sub OAM buffers and the mode.
typedef struct ResultScene {
    /* 000 */ u8 mMainOam[0x404];
    /* 404 */ u8 mSubOam[0x404];
    /* 808 */ s32 mMode;
} ResultScene;

void Scene_Result_VBlankImpl_from_thumb(void);
void Scene_Result_FinalizeImpl_from_thumb(void);
void Scene_Result_UpdateImpl_from_thumb(SceneNumbers *sceneNumbers);
void InstanceStructN_from_thumb(void *heap);

extern struct ResultScene *g_GlobalN;
