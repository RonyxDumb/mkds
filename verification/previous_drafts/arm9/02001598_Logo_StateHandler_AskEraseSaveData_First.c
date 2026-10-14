/* Decompiled C draft; module arm9; ROM address 02001598. No matching claim. */
#include "types.h"
#include "deps/02001598_Logo_StateHandler_AskEraseSaveData_First.h"

void Logo_StateHandler_AskEraseSaveData_First(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam020015ec);
  uVar2 = Bmg_GetRawStringPointer_from_thumb(uVar1,0x7c);
  uVar3 = Bmg_GetRawStringPointer_from_thumb(uVar1,0);
  uVar1 = Bmg_GetRawStringPointer_from_thumb(uVar1,1);
  TextSystem_DisplayDoubleButtonDialog_Simple_from_thumb(uVar2,uVar3,uVar1,1);
  return;
}

