/* Decompiled C draft; module arm9; ROM address 020871a4. No matching claim. */
#include "types.h"
#include "deps/020871a4_StructAERSubSub_Fn1_Sub3_from_thumb.h"

void StructAERSubSub_Fn1_Sub3_from_thumb(int param_1,undefined4 param_2)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x10);
  uVar1 = GetVsRacerIndicatorColor_from_thumb(param_2);
  *(undefined2 *)(iVar2 + 2) = uVar1;
  Arm_FlushRange(iVar2,8);
  return;
}

