/* Decompiled C draft; module arm9; ROM address 02131694. No matching claim. */
#include "types.h"
#include "deps/02131694_func_02131694.h"

uint func_02131694(uint param_1,uint param_2)

{
  uint uVar1;
  uint *puVar2;
  undefined4 in_lr;
  
  if (param_1 << 1 < 0xff000001) {
    if (param_2 << 1 < 0xff000001) {
      if ((int)param_1 < 0) {
        param_1 = -(param_1 & 0x7fffffff);
      }
      if ((int)param_2 < 0) {
        param_2 = -(param_2 & 0x7fffffff);
      }
      uVar1 = param_1;
      if (param_1 == param_2) {
        uVar1 = 0;
      }
      if ((int)param_1 < (int)param_2) {
        uVar1 = 1;
      }
      if ((int)param_2 < (int)param_1) {
        uVar1 = 2;
      }
      return uVar1;
    }
  }
  else {
    if ((param_1 & 0x400000) == 0) goto LAB_02131950;
    if (param_2 << 1 < 0xff000001) {
      return 3;
    }
  }
  if ((param_2 & 0x400000) != 0) {
    return 3;
  }
LAB_02131950:
  puVar2 = (uint *)GetAlphaFlagsRef();
  uVar1 = *(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
          *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20;
  if ((uVar1 & 0x100) != 0) {
    uVar1 = func_021340d4(param_1,param_2,DAT_021321f8,uVar1,in_lr);
    return uVar1;
  }
  *puVar2 = uVar1 | 1;
  return 3;
}

