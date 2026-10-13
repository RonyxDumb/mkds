/* Decompiled C draft; module arm9; ROM address 0212e04c. No matching claim. */
#include "types.h"
#include "deps/0212e04c_Sound_DisposeFile.h"

void Sound_DisposeFile(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_2 != 0) {
    uVar1 = Os_DisableIrq();
    uVar2 = Sound_MaybeSetActiveSdat(param_2);
    iVar3 = Sound_MaybeGetRawFilePointer(param_3);
    if (param_1 == iVar3) {
      Sound_SetFileFatDynamicOffsetField(param_3,0);
    }
    Sound_MaybeSetActiveSdat(uVar2);
    Os_RestoreIrq(uVar1);
    return;
  }
  return;
}

