/* Decompiled C draft; module arm9; ROM address 0200aeec. No matching claim. */
#include "types.h"
#include "deps/0200aeec_StructANN_SomeFn_from_thumb.h"

void StructANN_SomeFn_from_thumb
               (undefined4 *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  
  iVar6 = *piRam0200aff0;
  iVar1 = IsGlobalANSet_from_thumb();
  if (iVar1 == 0) {
    Os_Terminate();
  }
  if ((param_1[1] & 1) != 0) {
    Os_Terminate();
  }
  uVar2 = param_4;
  if (0x1f < param_4) {
    uVar2 = Os_Thread_GetPriority(iVar6);
    if (param_4 == 0x20) {
      if (uVar2 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 - 1;
      }
    }
    else if (param_4 == 0x21) {
      if (uVar2 < 0x1f) {
        uVar2 = uVar2 + 1;
      }
      else {
        uVar2 = 0x1f;
      }
    }
    else if (param_4 != 0x22) {
      uVar2 = 0x1f;
    }
  }
  uVar3 = Os_DisableIrq();
  param_1[1] = param_1[1] & 0xfffffffe | 1;
  param_1[1] = param_1[1] & 1 | (uVar2 & uRam0200aff4) << 1;
  param_1[2] = param_2;
  param_1[3] = param_3;
  if (*(int *)(iVar6 + 0xc0) == 0) {
    if (param_1 == (undefined4 *)(iVar6 + 0xc4)) {
      *piRam0200aff0 = 0;
    }
    *(undefined4 **)(iVar6 + 0xc0) = param_1;
    Os_Thread_WakeUpDirect(iVar6);
  }
  else {
    piVar4 = *(int **)(iVar6 + 0xc0);
    if (param_1 == (undefined4 *)(iVar6 + 0xc4)) {
      for (piVar5 = (int *)*piVar4; piVar5 != (int *)0x0; piVar5 = (int *)*piVar5) {
        piVar4 = piVar5;
      }
      *piVar4 = (int)param_1;
      *piRam0200aff0 = 0;
    }
    else if (uVar2 < (uint)piVar4[1] >> 1) {
      *(undefined4 **)(iVar6 + 0xc0) = param_1;
      *param_1 = piVar4;
    }
    else {
      do {
        piVar5 = piVar4;
        piVar4 = (int *)*piVar5;
        if (piVar4 == (int *)0x0) break;
      } while ((uint)piVar4[1] >> 1 <= uVar2);
      *param_1 = piVar4;
      *piVar5 = (int)param_1;
    }
  }
  Os_RestoreIrq(uVar3);
  return;
}

