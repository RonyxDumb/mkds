#pragma once
#include "types.h"
#include "gfd_LinkedListPlttVramMan.h"
#include "mic.h" // MICAutoParam
#include "gfd_LinkedListTexVramMan.h"

typedef struct GxCommandBuffer GxCommandBuffer;

typedef struct NNSGfdFrmPlttVramManager NNSGfdFrmPlttVramManager;

extern u32 gSplRandomState;



extern NNS_GfdLnkTexVramManager gTexVramManager;

extern NNSiGfdLnkVramBlock *data_02173238;

extern NNSiGfdLnkVramBlock *gTexVramBlockPoolList;

extern NNS_GfdLnkPlttVramManager gPlttVramManager;

extern NNSiGfdLnkVramBlock *data_02173254;


