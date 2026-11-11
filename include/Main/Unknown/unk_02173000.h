#pragma once

#include "types.h"
#include "gfd_LinkedListPlttVramMan.h"
#include "mic.h" // MICAutoParam

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

extern u8 data_02173288;
extern s32 data_0217328c;
extern MICAutoParam *gMicSampleAnalysisParam;
extern s32 data_02173294;
extern s32 data_02173298;
extern s32 data_0217329c;
extern u8 gMicIntervalHistogram[4];
extern s32 data_021732a4;
extern s32 data_021732a8;

extern GxCommandBuffer *NNS_G3dGeBuffer;
extern vu32 NNS_G3dFlagGXDmaAsync;

#include "gfd_LinkedListTexVramMan.h"
