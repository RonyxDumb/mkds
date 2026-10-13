/* Decompiled C draft; module arm7; ROM address 03801774. No matching claim. */
#include "types.h"
#include "deps/03801774_FUN_03801774.h"

void FUN_03801774(uint param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 local_10;
  
  iVar2 = FUN_03801320(0,0x10,1,param_1);
  if (iVar2 == 0) {
    uVar1 = local_10 & 0xf9ffffff;
    MKDS_SLICE_2(local_10,2) = (ushort)(uVar1 >> 0x10) | 0x600;
    MKDS_SLICE_2(local_10,0) = (undefined2)uVar1;
    *DAT_038017e4 = (undefined2)local_10;
    *DAT_038017e8 = MKDS_SLICE_2(local_10,2);
    FUN_0380146c(0x10,param_1 & 0xff);
  }
  return;
}

