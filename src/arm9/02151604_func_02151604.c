/* Decompiled C draft; module arm9; ROM address 02151604. No matching claim. */
#include "types.h"
#include "deps/02151604_func_02151604.h"

undefined8 func_02151604(undefined4 param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  int unaff_r5;
  
  *(short *)(unaff_r5 + 0x16) = (short)param_3;
  bVar1 = *(byte *)((uint)(param_3 << 0x12) >> 0x1e);
  if (bVar1 == 0x7f) {
    return 0;
  }
  if (bVar1 == 0) {
    return 0;
  }
  if (bVar1 < 0xe0) {
    return 1;
  }
  return 0;
}

