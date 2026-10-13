/* Decompiled C draft; module arm7; ROM address 06013854. No matching claim. */
#include "types.h"
#include "deps/06013854_FUN_06013854.h"

int FUN_06013854(undefined4 param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = FUN_06009138((*(uint *)(DAT_060138dc & 0xfffffffc) >> (DAT_060138dc & 3) * 8 |
                       *(uint *)(DAT_060138dc & 0xfffffffc) << (DAT_060138dc & 3) * -8 + 0x20) +
                       0x188,0x5a);
  if (iVar2 == 0) {
    FUN_06009360(2);
    iVar4 = 0;
  }
  else {
    *(short *)(iVar2 + 0xc) = (short)DAT_060138e0;
    iVar4 = iVar2 + 0x10;
    FUN_0601359c(iVar4,param_1);
    iVar3 = FUN_060134b4(iVar2 + 0x3c);
    sVar1 = FUN_060133fc(iVar2 + 0x3c + iVar3);
    sVar1 = (short)iVar3 + sVar1;
    *(short *)(iVar2 + 0x16) = sVar1;
    *(short *)(iVar2 + 0x22) = sVar1 + 0x1c;
    *(undefined2 *)(iVar2 + 0x24) = 0x40;
  }
  return iVar4;
}

