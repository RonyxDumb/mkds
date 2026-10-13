/* Decompiled C draft; module arm9; ROM address 0203f544. No matching claim. */
#include "types.h"
#include "deps/0203f544_AddRCTimes.h"

void AddRCTimes(ushort *param_1,ushort *param_2,undefined2 *param_3)

{
  undefined1 uVar1;
  undefined2 uVar3;
  uint uVar5;
  uint uVar2;
  int iVar4;
  
  iVar4 = (int)(((uint)*param_1 + (uint)*param_2) * 0x10000) >> 0x10;
  uVar5 = (int)(((uint)(byte)param_1[1] + (uint)(byte)param_2[1]) * 0x10000) >> 0x10;
  uVar2 = (int)(((uint)*(byte *)((int)param_1 + 3) + (uint)*(byte *)((int)param_2 + 3)) * 0x10000)
          >> 0x10;
  if (iRam0203f5ec < iVar4) {
    iVar4 = (iVar4 + -1000) * 0x10000 >> 0x10;
    uVar2 = (int)((uVar2 + 1) * 0x10000) >> 0x10;
  }
  uVar3 = (undefined2)iVar4;
  if (0x3b < uVar2) {
    uVar2 = (int)((uVar2 - 0x3c) * 0x10000) >> 0x10;
    uVar5 = (int)((uVar5 + 1) * 0x10000) >> 0x10;
  }
  uVar1 = (undefined1)uVar2;
  if (99 < uVar5) {
    uVar5 = 99;
    uVar3 = (undefined2)iRam0203f5ec;
    uVar1 = 0x3b;
  }
  *(char *)(param_3 + 1) = (char)uVar5;
  *(undefined1 *)((int)param_3 + 3) = uVar1;
  *param_3 = uVar3;
  return;
}

