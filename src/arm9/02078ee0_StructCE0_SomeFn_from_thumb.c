/* Decompiled C draft; module arm9; ROM address 02078ee0. No matching claim. */
#include "types.h"
#include "deps/02078ee0_StructCE0_SomeFn_from_thumb.h"

void StructCE0_SomeFn_from_thumb(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  *param_1 = 0xffffffff;
  param_1[1] = 0xffffffff;
  param_1[2] = uRam02078f10;
  *(short *)((int)param_1 + 0x16) = (short)uRam02078f14;
  *(undefined2 *)(param_1 + 5) = *(undefined2 *)((int)param_1 + 0x16);
  *(undefined2 *)(param_1 + 6) = 0;
  param_1[3] = 0;
  param_1[4] = 0xffffff88;
  if (param_2 != 0) {
    uVar1 = 0xffffff06;
  }
  param_1[0xb] = uVar1;
  param_1[0xc] = 0;
  return;
}

