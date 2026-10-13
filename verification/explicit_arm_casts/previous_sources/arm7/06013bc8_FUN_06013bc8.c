/* Decompiled C draft; module arm7; ROM address 06013bc8. No matching claim. */
#include "types.h"
#include "deps/06013bc8_FUN_06013bc8.h"

int FUN_06013bc8(undefined4 param_1)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = *(uint *)(DAT_06013c78 & 0xfffffffc) >> (DAT_06013c78 & 3) * 8 |
          *(uint *)(DAT_06013c78 & 0xfffffffc) << (DAT_06013c78 & 3) * -8 + 0x20;
  iVar3 = FUN_06009138(uVar2 + 0x188,100);
  if (iVar3 == 0) {
    FUN_06009360(2);
    iVar5 = 0;
  }
  else {
    *(short *)(iVar3 + 0xc) = (short)DAT_06013c7c;
    iVar5 = iVar3 + 0x10;
    FUN_0601359c(iVar5,param_1);
    *(undefined2 *)(iVar3 + 0x3c) = *(undefined2 *)(uVar2 + 0x3c0);
    *(undefined2 *)(iVar3 + 0x3e) = *(undefined2 *)(uVar2 + 0x3b4);
    FUN_0600a954(iVar3 + 0x40,uVar2 + 0x3c6);
    iVar4 = FUN_060134b4(iVar3 + 0x46);
    sVar1 = FUN_060133fc(iVar3 + 0x46 + iVar4);
    *(short *)(iVar3 + 0x16) = (short)iVar4 + sVar1 + 10;
    *(short *)(iVar3 + 0x22) = *(short *)(iVar3 + 0x16) + 0x1c;
    *(undefined2 *)(iVar3 + 0x24) = 0x20;
  }
  return iVar5;
}

