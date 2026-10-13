/* Decompiled C draft; module arm7; ROM address 060120a0. No matching claim. */
#include "types.h"
#include "deps/060120a0_FUN_060120a0.h"

undefined4 FUN_060120a0(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint local_18 [2];
  
  uVar2 = *(uint *)(DAT_060122f0 & 0xfffffffc) >> (DAT_060122f0 & 3) * 8 |
          *(uint *)(DAT_060122f0 & 0xfffffffc) << (DAT_060122f0 & 3) * -8 + 0x20;
  *(undefined2 *)(param_2 + 2) = 1;
  if ((*(ushort *)(uVar2 + 0x34c) & 0xf0) != 0x10) {
    return 1;
  }
  if (1 < *(ushort *)(param_1 + 0x10)) {
    return 5;
  }
  if ((*(short *)(param_1 + 0x14) != 10) && (*(short *)(param_1 + 0x14) != 0x14)) {
    return 5;
  }
  if (4 < *(ushort *)(param_1 + 0x12)) {
    return 5;
  }
  iVar3 = FUN_060188f4(0);
  if (iVar3 != 0) {
    return 0xe;
  }
  if (*(short *)(param_1 + 0x10) == 0) {
    if (*(short *)(uVar2 + 0x34c) == 0x11) {
      FUN_060099bc();
      *DAT_0601230c = 0;
      *DAT_06012304 = 1;
      *DAT_060122f8 = 0;
      local_18[0] = FUN_06009e98(2);
      local_18[0] = local_18[0] & 0xffffffcf;
      FUN_06009e58(2);
    }
    else {
      if (*(short *)(uVar2 + 0x34c) != 0x12) {
        return 1;
      }
      *(undefined2 *)(uVar2 + 0x35c) = 0;
      do {
      } while (*DAT_06012310 != 0);
      FUN_06009e58(6,*(undefined2 *)(uVar2 + 0x3f0));
    }
    *(undefined2 *)(uVar2 + 0x34c) = 0x10;
    return 0;
  }
  if (*(short *)(param_1 + 0x10) != 1) {
    return 0;
  }
  if (*(short *)(uVar2 + 0x34c) != 0x10) {
    return 1;
  }
  local_18[0] = 0;
  FUN_060187f4(0x65,1,local_18);
  uVar1 = local_18[0];
  uVar4 = FUN_06009e98(1);
  if (uVar1 != uVar4) {
    FUN_06009e58(1,uVar1);
    FUN_06009a68(DAT_060122f4);
  }
  switch(*(undefined2 *)(param_1 + 0x12)) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    goto LAB_06012244;
  case 4:
LAB_06012244:
    FUN_06011f50(param_1);
  default:
    goto switchD_06012188_default;
  }
  *(undefined2 *)(uVar2 + 0x34c) = 0x11;
  FUN_0600af7c(*(undefined2 *)(param_1 + 0x16),1);
  *DAT_060122f8 = 0x8000;
  FUN_06009a68(DAT_060122fc);
  *(undefined2 *)(uVar2 + 0x35a) = *(undefined2 *)(param_1 + 0x14);
  local_18[0] = FUN_06009e98(2);
  if (*(ushort *)(param_1 + 0x12) < 2) {
    local_18[0] = local_18[0] | 0x10;
  }
  *DAT_06012300 = *(undefined2 *)(param_1 + 0x14);
  if (*(short *)(param_1 + 0x12) == 1) {
    local_18[0] = local_18[0] | 0x20;
    *DAT_06012304 = 3;
  }
  else {
    *DAT_06012304 = *(short *)(param_1 + 0x12);
  }
  FUN_06009e58(2,local_18[0]);
  *DAT_0601230c = (short)DAT_06012308;
switchD_06012188_default:
  return 0;
}

