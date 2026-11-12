#pragma once
#include "types.h"
#include "gfd_LinkedListPlttVramMan.h"
#include "mic.h" // MICAutoParam
#include "gfd_LinkedListTexVramMan.h"

typedef struct GxCommandBuffer GxCommandBuffer;

typedef struct NNSGfdFrmPlttVramManager NNSGfdFrmPlttVramManager;

extern u32 gSplRandomState;

extern BOOL NNS_G3dFlagUseFastDma;

extern NNSGfdFrmPlttVramManager s_managerState_;

extern NNS_GfdLnkTexVramManager gTexVramManager;

extern NNSiGfdLnkVramBlock *data_02173238;

extern NNSiGfdLnkVramBlock *gTexVramBlockPoolList;

extern NNS_GfdLnkPlttVramManager gPlttVramManager;

extern NNSiGfdLnkVramBlock *data_02173254;

extern vu16 wvrLockId;

extern vu16 wvrVRam;

extern u32 data_02173280;

extern void (*wvrCallback)(u32, s32);

extern GxCommandBuffer *NNS_G3dGeBuffer;

extern vu32 NNS_G3dFlagGXDmaAsync;
