#pragma once

#include "types.h"
#include "gfd_LinkedListPlttVramMan.h"
#include "mic.h" // MICAutoParam

typedef struct GxCommandBuffer GxCommandBuffer;
typedef struct NNSGfdFrmPlttVramManager NNSGfdFrmPlttVramManager;

extern u32 data_02173274;

extern BOOL NNS_G3dFlagUseFastDma;

extern NNSGfdFrmPlttVramManager data_02173214;
extern NNS_GfdLnkTexVramManager data_02173234;
extern NNSiGfdLnkVramBlock *data_02173238;
extern NNSiGfdLnkVramBlock *data_0217323c;
extern NNS_GfdLnkPlttVramManager data_02173250;
extern NNSiGfdLnkVramBlock *data_02173254;

extern vu16 data_02173278;
extern vu16 data_0217327c;
extern u32 data_02173280;
extern void (*data_02173284)(u32, s32);

extern u8 data_02173288;
extern s32 data_0217328c;
extern MICAutoParam *data_02173290;
extern s32 data_02173294;
extern s32 data_02173298;
extern s32 data_0217329c;
extern u8 data_021732a0[4];
extern s32 data_021732a4;
extern s32 data_021732a8;

extern GxCommandBuffer *NNS_G3dGeBuffer;
extern vu32 NNS_G3dFlagGXDmaAsync;

#include "gfd_LinkedListTexVramMan.h"
