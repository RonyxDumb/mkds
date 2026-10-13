/* Decompiled C draft; module arm9; ROM address 020b6b54. No matching claim. */
#include "types.h"
#include "deps/020b6b54_func_020b6b54.h"

void func_020b6b54(undefined4 param_1,undefined4 param_2)

{
  short sVar1;
  short sVar2;
  int iVar3;
  short *psVar4;
  short *psVar5;
  short asStack_1c8 [222];
  short *psVar6;
  
  psVar4 = asStack_1c8;
  iVar3 = 0x6e;
  psVar5 = psRam020b6bd0;
  do {
    psVar6 = psVar5 + 1;
    sVar1 = *psVar5;
    psVar5 = psVar5 + 2;
    sVar2 = *psVar6;
    iVar3 = iVar3 + -1;
    psVar6 = psVar4 + 1;
    *psVar4 = sVar1;
    psVar4 = psVar4 + 2;
    *psVar6 = sVar2;
  } while (iVar3 != 0);
  iVar3 = GetCurrentInternalCourseId_0();
  func_020b6bd4((int *)(uintptr_t)(param_1),(int *)(uintptr_t)(param_2),(int)asStack_1c8[iVar3 * 4],(int)asStack_1c8[iVar3 * 4 + 1],
                (int)asStack_1c8[iVar3 * 4 + 2],(int)asStack_1c8[iVar3 * 4 + 3]);
  return;
}

