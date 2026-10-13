/* Decompiled C draft; module arm9_ov000; ROM address 021a1ae0. No matching claim. */
#include "types.h"
#include "deps/021a1ae0_FUN_021a1ae0.h"

void FUN_021a1ae0(undefined4 param_1,undefined4 param_2,undefined1 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 auStack_a8 [16];
  undefined4 local_98 [33];
  
  iVar4 = 0;
  puVar3 = local_98;
  do {
    iVar1 = FUN_021a0958((int)(uintptr_t)(auStack_a8),(int)(uintptr_t)(param_3 + 1),iVar4);
    if (iVar1 == -1) break;
    uVar2 = func_0x0213c074((int)(uintptr_t)(auStack_a8),0,10);
    *puVar3 = uVar2;
    puVar3 = puVar3 + 1;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x80);
  FUN_021a01dc(*param_3,param_2,0,0,local_98,iVar4);
  return;
}

