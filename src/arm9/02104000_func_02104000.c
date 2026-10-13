/* Decompiled C draft; module arm9; ROM address 02104000. No matching claim. */
#include "types.h"
#include "deps/02104000_func_02104000.h"

uint func_02104000(uint param_1,int param_2)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = 1 << (param_1 + 1 & 0xff) | 1 << (param_1 + 2 & 0xff) | 1 << (param_1 + 3 & 0xff);
  uVar6 = 0;
  uVar1 = (int)uVar5 >> 3;
  if (1 < param_2) {
    bVar2 = *(byte *)(iRam02104114 + param_2 + -2);
    uVar6 = (uint)bVar2 & uVar1 & 0xff;
    *(byte *)(iRam02104114 + param_2 + -2) = bVar2 | (byte)uVar1;
  }
  uVar5 = (int)(uVar5 | 1 << (param_1 & 0xff) | 1 << (param_1 + 4 & 0xff)) >> 3;
  bVar2 = (byte)uVar5;
  if (0 < param_2) {
    bVar3 = *(byte *)(iRam02104114 + param_2 + -1);
    uVar6 = uVar6 | (uint)bVar3 & uVar5 & 0xff;
    *(byte *)(iRam02104114 + param_2 + -1) = bVar3 | bVar2;
  }
  iVar4 = iRam02104114;
  uVar6 = uVar6 | (uint)*(byte *)(iRam02104114 + param_2) & uVar5 & 0xff;
  *(byte *)(iRam02104114 + param_2) = *(byte *)(iRam02104114 + param_2) | bVar2;
  if (param_2 < 7) {
    bVar3 = *(byte *)(iVar4 + param_2 + 1);
    uVar6 = uVar6 | (uint)bVar3 & uVar5 & 0xff;
    *(byte *)(iVar4 + param_2 + 1) = bVar3 | bVar2;
  }
  if (param_2 < 6) {
    bVar2 = *(byte *)(iRam02104114 + param_2 + 2);
    *(byte *)(iRam02104114 + param_2 + 2) = bVar2 | (byte)uVar1;
    return uVar6 | (uint)bVar2 & uVar1 & 0xff;
  }
  return uVar6;
}

