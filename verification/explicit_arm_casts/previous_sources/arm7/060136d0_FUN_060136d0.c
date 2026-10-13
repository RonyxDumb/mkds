/* Decompiled C draft; module arm7; ROM address 060136d0. No matching claim. */
#include "types.h"
#include "deps/060136d0_FUN_060136d0.h"

int FUN_060136d0(undefined4 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_06009138((*(uint *)(DAT_06013778 & 0xfffffffc) >> (DAT_06013778 & 3) * 8 |
                       *(uint *)(DAT_06013778 & 0xfffffffc) << (DAT_06013778 & 3) * -8 + 0x20) +
                       0x188,param_2 + DAT_0601377c);
  if (iVar1 == 0) {
    FUN_06009360(2);
    iVar2 = 0;
  }
  else {
    *(short *)(iVar1 + 0xc) = (short)DAT_06013780;
    iVar2 = iVar1 + 0x10;
    FUN_0601359c(iVar2,param_1);
    if (param_2 != 0) {
      FUN_060096e4(iVar1 + 0x42,0x10);
      FUN_060096e4(iVar1 + 0x43,param_2 & 0xff);
      param_2 = param_2 + 2 & 0xffff;
    }
    *(short *)(iVar1 + 0x16) = (short)param_2 + 6;
    *(short *)(iVar1 + 0x22) = *(short *)(iVar1 + 0x16) + 0x1c;
    *(undefined2 *)(iVar1 + 0x24) = 0xb0;
  }
  return iVar2;
}

