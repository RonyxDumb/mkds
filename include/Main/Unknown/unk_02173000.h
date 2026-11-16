#pragma once

#include "types.h"
#include "gfd_LinkedListPlttVramMan.h"
#include "code_0201ec30.h" // Unk02173290

typedef struct Unk01ff9048 Unk01ff9048;
typedef struct NNSGfdFrmPlttVramManager NNSGfdFrmPlttVramManager;
typedef struct CallQueue CallQueue;

extern u32 gSpaRng;

extern BOOL NNS_G3dFlagUseFastDma;

extern CallQueue g_GlobalTEQ;
extern NNSGfdFrmPlttVramManager data_02173214;
extern NNS_GfdLnkTexVramManager data_02173234;
extern RangeEntry *data_02173238;
extern RangeEntry *data_0217323c;
extern NNS_GfdLnkPlttVramManager data_02173250;
extern RangeEntry *data_02173254;

extern vu16 data_02173278;
extern vu16 data_0217327c;
extern u32 data_02173280;
extern UnkFunc *data_02173284;

extern u8 data_02173288;
extern s32 data_0217328c;
extern Unk02173290 *data_02173290;
extern s32 data_02173294;
extern s32 data_02173298;
extern s32 data_0217329c;
extern u8 data_021732a0[4];
extern s32 data_021732a4;
extern s32 data_021732a8;

extern Unk01ff9048 *NNS_G3dGeBuffer;
extern vu32 NNS_G3dFlagGXDmaAsync;

#include "gfd_LinkedListTexVramMan.h"
