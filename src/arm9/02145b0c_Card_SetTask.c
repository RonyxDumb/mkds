/* Decompiled C draft; module arm9; ROM address 02145b0c. No matching claim. */
#include "types.h"
#include "deps/02145b0c_Card_SetTask.h"

void Card_SetTask(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = iRam02145b50;
  uVar1 = iRam02145b50 + 0x108U & 3;
  uVar3 = *(uint *)(iRam02145b50 + 0x108U & 0xfffffffc);
  Os_Thread_SetPriority(iRam02145b50 + 0x44,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  *(int *)(iVar2 + 0x104) = iVar2 + 0x44;
  *(undefined4 *)(iVar2 + 0x40) = param_1;
  uVar1 = iVar2 + 0x114U & 3;
  uVar3 = *(uint *)(iVar2 + 0x114U & 0xfffffffc);
  *(uint *)(iVar2 + 0x114) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20 | 8;
  Os_Thread_WakeUpDirect();
  return;
}

