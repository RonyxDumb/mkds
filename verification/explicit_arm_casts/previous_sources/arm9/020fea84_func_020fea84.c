/* Decompiled C draft; module arm9; ROM address 020fea84. No matching claim. */
#include "types.h"
#include "deps/020fea84_func_020fea84.h"

void func_020fea84(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  bVar1 = *pbRam020feb30;
  uVar6 = (uint)bVar1;
  if (uVar6 == 0xff) {
    return;
  }
  iVar5 = iRam020feb34 + uVar6 * 0x20;
  *(undefined4 *)(iVar5 + 0x14) = param_1;
  *(undefined4 *)(iVar5 + 0x18) = param_2;
  Mem_CpuCopy8(param_3,iVar5,param_4);
  pbVar4 = pbRam020feb3c;
  iVar5 = iRam020feb38;
  uVar7 = (uint)*pbRam020feb3c;
  *pbRam020feb30 = *(byte *)(iRam020feb38 + uVar6 * 2);
  if (uVar7 == 0xff) {
    *pbVar4 = bVar1;
  }
  else {
    bVar2 = *(byte *)(iVar5 + uVar7 * 2);
    while (uVar3 = (uint)bVar2, uVar3 != 0xff) {
      uVar7 = uVar3;
      bVar2 = *(byte *)(iVar5 + uVar3 * 2);
    }
    *(byte *)(iRam020feb38 + uVar7 * 2) = bVar1;
  }
  iVar5 = iRam020feb40;
  *(undefined1 *)(iRam020feb38 + uVar6 * 2) = 0xff;
  *(char *)(iVar5 + uVar6 * 2) = (char)param_4;
  return;
}

