#pragma once

#include "types.h"
#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02114158.h"

// Five emblems of the saved data: the index of the block (emblem number / 5, -1 for none) and the saved block.
// 0xb04 bytes: a signed byte at 0x00 and, from 0x04, an EmblemBlockData.
typedef struct EmblemBlock {
    /* 00 */ s8 mBlockIndex;
    /* 01 */ u8 field1[3];
    /* 04 */ EmblemBlockData field4;
} EmblemBlock;

void area_initMissionRivalPassAreas(void *heap);
// Scene function of scproc_sSceneTable[13] (scene 'Ghost' in sSceneDefs): copies the callbacks and calls
// scene_runScene. Returns 0.
s32 ghost_run(SceneNumbers *sceneNumbers);
void ghostdef_render(u32 sceneNumbers);
void ghostdef_vblank(void);
void ghostdef_finish(void);
void ghostdef_create(void);
u8 CountEmblemEntries(void);
void StartCopyOtherEmblems(s32 useConnection);
void CopyWiFiOtherEmblemsToBlocks(void);
void CopyOtherPlayerEmblemsToBlocks(void);
void SetupEmblemBlock(EmblemBlock *emblemBlock, u8 buddyIndex);
BOOL CopyEmblemFromBlock(EmblemBlock *emblemBlock, u8 buddyIndex, EmblemData *emblemData);
EmblemBlock *CreateEmblemBlock(void *heap);
