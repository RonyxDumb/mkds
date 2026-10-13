/* Decompiled C draft; module arm9_ov003; ROM address 021d254c. No matching claim. */
#include "types.h"
#include "deps/021d254c_FUN_021d254c.h"

void FUN_021d254c(int param_1,undefined4 param_2,int param_3,int param_4)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  
  uVar1 = (ushort)DAT_021d264c;
  uVar2 = (ushort)DAT_021d2648;
  uVar3 = (ushort)param_3;
  switch(param_2) {
  case 0:
    break;
  case 1:
    if (param_1 != 1) {
      uVar3 = *DAT_021d2644 & uVar2 | (ushort)(param_3 << 8);
      if (param_4 != 0) {
        uVar3 = uVar3 | uVar1;
      }
      *DAT_021d2644 = uVar3;
      return;
    }
    uVar3 = *DAT_021d2640 & uVar2 | (ushort)(param_3 << 8);
    if (param_4 != 0) {
      uVar3 = uVar3 | uVar1;
    }
    *DAT_021d2640 = uVar3;
    return;
  case 2:
    if (param_1 != 1) {
      uVar3 = *DAT_021d2654 & uVar2 | (ushort)(param_3 << 8);
      if (param_4 != 0) {
        uVar3 = uVar3 | uVar1;
      }
      *DAT_021d2654 = uVar3;
      return;
    }
    uVar3 = *DAT_021d2650 & uVar2 | (ushort)(param_3 << 8);
    if (param_4 != 0) {
      uVar3 = uVar3 | uVar1;
    }
    *DAT_021d2650 = uVar3;
    return;
  case 3:
    if (param_1 == 1) {
      uVar3 = *DAT_021d2650 & 0xffc0 | uVar3;
      if (param_4 != 0) {
        uVar3 = uVar3 | 0x20;
      }
      *DAT_021d2650 = uVar3;
      return;
    }
    uVar3 = *DAT_021d2654 & 0xffc0 | uVar3;
    if (param_4 != 0) {
      uVar3 = uVar3 | 0x20;
    }
    *DAT_021d2654 = uVar3;
  default:
    return;
  }
  if (param_1 != 1) {
    uVar3 = *DAT_021d2644 & 0xffc0 | uVar3;
    if (param_4 != 0) {
      uVar3 = uVar3 | 0x20;
    }
    *DAT_021d2644 = uVar3;
    return;
  }
  uVar3 = *DAT_021d2640 & 0xffc0 | uVar3;
  if (param_4 != 0) {
    uVar3 = uVar3 | 0x20;
  }
  *DAT_021d2640 = uVar3;
  return;
}

