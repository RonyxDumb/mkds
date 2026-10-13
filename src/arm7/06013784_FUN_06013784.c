/* Decompiled C draft; module arm7; ROM address 06013784. No matching claim. */
#include "types.h"
#include "deps/06013784_FUN_06013784.h"

int FUN_06013784(undefined4 param_1)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  uVar2 = *(uint *)(DAT_0601384c & 0xfffffffc) >> (DAT_0601384c & 3) * 8 |
          *(uint *)(DAT_0601384c & 0xfffffffc) << (DAT_0601384c & 3) * -8 + 0x20;
  iVar3 = FUN_06009138(uVar2 + 0x188,*(ushort *)(uVar2 + 0x3e4) + 0x78);
  if (iVar3 == 0) {
    FUN_06009360(2);
    iVar7 = 0;
  }
  else {
    *(short *)(iVar3 + 0xc) = (short)DAT_06013850;
    iVar7 = iVar3 + 0x10;
    FUN_0601359c(iVar7,param_1);
    *(undefined2 *)(iVar3 + 0x44) = *(undefined2 *)(uVar2 + 0x3b2);
    *(undefined2 *)(iVar3 + 0x46) = *(undefined2 *)(uVar2 + 0x3c0);
    iVar4 = FUN_060134b4(iVar3 + 0x48);
    iVar5 = FUN_060133fc(iVar3 + 0x48 + iVar4);
    iVar6 = FUN_060133b4(iVar3 + 0x48 + iVar4 + iVar5);
    iVar6 = iVar4 + iVar5 + iVar6;
    sVar1 = FUN_06013290(iVar3 + 0x48 + iVar6);
    *(short *)(iVar3 + 0x16) = (short)iVar6 + sVar1 + 0xc;
    *(short *)(iVar3 + 0x22) = *(short *)(iVar3 + 0x16) + 0x1c;
    *(undefined2 *)(iVar3 + 0x24) = 0x50;
  }
  return iVar7;
}

