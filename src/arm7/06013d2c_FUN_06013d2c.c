/* Decompiled C draft; module arm7; ROM address 06013d2c. No matching claim. */
#include "types.h"
#include "deps/06013d2c_FUN_06013d2c.h"

int FUN_06013d2c(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_06009138((*(uint *)(DAT_06013da8 & 0xfffffffc) >> (DAT_06013da8 & 3) * 8 |
                       *(uint *)(DAT_06013da8 & 0xfffffffc) << (DAT_06013da8 & 3) * -8 + 0x20) +
                       0x188,0x36);
  if (iVar1 == 0) {
    FUN_06009360(2);
    iVar2 = 0;
  }
  else {
    *(short *)(iVar1 + 0xc) = (short)DAT_06013dac;
    iVar2 = iVar1 + 0x10;
    FUN_0601359c(iVar2,param_1);
    *(undefined2 *)(iVar1 + 0x3c) = param_2;
    *(undefined2 *)(iVar1 + 0x16) = 2;
    *(short *)(iVar1 + 0x22) = *(short *)(iVar1 + 0x16) + 0x1c;
    *(undefined2 *)(iVar1 + 0x24) = 0xa0;
  }
  return iVar2;
}

