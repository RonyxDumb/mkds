/* Decompiled C draft; module arm7; ROM address 06013c80. No matching claim. */
#include "types.h"
#include "deps/06013c80_FUN_06013c80.h"

int FUN_06013c80(undefined4 param_1)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = *(uint *)(DAT_06013d24 & 0xfffffffc) >> (DAT_06013d24 & 3) * 8 |
          *(uint *)(DAT_06013d24 & 0xfffffffc) << (DAT_06013d24 & 3) * -8 + 0x20;
  iVar3 = FUN_06009138(uVar2 + 0x188,0x5e);
  if (iVar3 == 0) {
    FUN_06009360(2);
    iVar5 = 0;
  }
  else {
    *(short *)(iVar3 + 0xc) = (short)DAT_06013d28;
    iVar5 = iVar3 + 0x10;
    FUN_0601359c(iVar5,param_1);
    *(undefined2 *)(iVar3 + 0x3c) = *(undefined2 *)(uVar2 + 0x3c0);
    *(undefined2 *)(iVar3 + 0x3e) = *(undefined2 *)(uVar2 + 0x3b4);
    iVar4 = FUN_060134b4(iVar3 + 0x40);
    sVar1 = FUN_060133fc(iVar3 + 0x40 + iVar4);
    *(short *)(iVar3 + 0x16) = (short)iVar4 + sVar1 + 4;
    *(short *)(iVar3 + 0x22) = *(short *)(iVar3 + 0x16) + 0x1c;
    *(undefined2 *)(iVar3 + 0x24) = 0;
  }
  return iVar5;
}

