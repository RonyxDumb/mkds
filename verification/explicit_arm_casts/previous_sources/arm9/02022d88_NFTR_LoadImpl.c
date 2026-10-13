/* Decompiled C draft; module arm9; ROM address 02022d88. No matching claim. */
#include "types.h"
#include "deps/02022d88_NFTR_LoadImpl.h"

void NFTR_LoadImpl(uint param_1,undefined4 param_2)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  short sVar4;
  uint uVar5;
  undefined2 uVar6;
  
  sVar4 = NFTR_Process(param_2,param_1);
  bVar2 = *(byte *)((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                    *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 7);
  *(short *)(param_1 + 8) = sVar4 + -1;
  iVar3 = iRam02022dd4;
  if (*(short *)(param_1 + 8) == 0) {
    uVar6 = 3;
  }
  else {
    uVar6 = 2;
  }
  *(undefined2 *)(param_1 + 10) = uVar6;
  uVar5 = iVar3 + (uint)bVar2 * 4;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *(uint *)(param_1 + 4) = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
  return;
}

