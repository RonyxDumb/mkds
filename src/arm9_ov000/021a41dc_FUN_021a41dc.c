/* Decompiled C draft; module arm9_ov000; ROM address 021a41dc. No matching claim. */
#include "types.h"
#include "deps/021a41dc_FUN_021a41dc.h"

void FUN_021a41dc(int param_1,int param_2,int param_3,int param_4,byte *param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int local_134;
  uint local_130;
  int local_12c;
  int local_120;
  undefined1 local_11c;
  byte bStack_11b;
  byte local_118 [256];
  int local_18;
  
  local_18 = 0;
  if (param_4 == 0) {
    return;
  }
  if (param_3 - 1U < 2) {
    if ((uint)(DAT_021a4374 - *(int *)(param_2 + DAT_021a4374)) < 2) {
      return;
    }
    local_130 = (**(code **)(param_1 + 0x98))(param_3,*(undefined4 *)(param_1 + DAT_021a4378));
    bStack_11b = (byte)(local_130 & 0xffff) & (byte)((uint)DAT_021a437c >> 8);
    piVar1 = (int *)(param_2 + DAT_021a4374);
    iVar3 = *piVar1;
    local_11c = (undefined1)((local_130 & 0xffff) >> 8);
    *(undefined1 *)(param_2 + iVar3) = local_11c;
    *(byte *)(param_2 + iVar3 + 1) = bStack_11b;
    *piVar1 = *piVar1 + 2;
  }
  else {
    local_130 = 1;
  }
  local_134 = param_4;
  if (param_4 == 0xff) {
    (**(code **)(param_1 + 0x94))(param_3,local_118,*(undefined4 *)(param_1 + DAT_021a4378));
    iVar3 = 0;
    if (0 < local_18) {
      pbVar4 = local_118;
      do {
        iVar2 = *(int *)(DAT_021a4380 + (uint)*pbVar4 * 4);
        if (iVar2 == 0) {
          iVar2 = DAT_021a4384;
        }
        FUN_021a471c(param_2,iVar2);
        if ((param_3 == 0) &&
           (iVar2 = *(int *)(param_2 + DAT_021a4374),
           (**(code **)(param_1 + 0x88))(*pbVar4,param_2,*(undefined4 *)(param_1 + DAT_021a4378)),
           iVar2 == *(int *)(param_2 + DAT_021a4374))) {
          FUN_021a471c(param_2,DAT_021a4388);
        }
        pbVar4 = pbVar4 + 1;
        iVar3 = iVar3 + 1;
      } while (iVar3 < local_18);
    }
    iVar3 = *(int *)(param_2 + DAT_021a4374);
    if (DAT_021a4374 - iVar3 < 1) {
      return;
    }
    *(int *)(param_2 + DAT_021a4374) = iVar3 + 1;
    *(undefined1 *)(param_2 + iVar3) = 0;
    local_134 = local_18;
    param_5 = local_118;
    if (param_3 == 0) {
      return;
    }
  }
  local_12c = 0;
  if (0 < (int)local_130) {
    local_120 = 0;
    do {
      iVar3 = local_120;
      if (0 < local_134) {
        do {
          iVar2 = *(int *)(param_2 + DAT_021a4374);
          if (param_3 == 0) {
            (**(code **)(param_1 + 0x88))
                      (param_5[iVar3],param_2,*(undefined4 *)(param_1 + DAT_021a4378));
          }
          else if (param_3 == 1) {
            (**(code **)(param_1 + 0x8c))
                      (param_5[iVar3],local_12c,param_2,*(undefined4 *)(param_1 + DAT_021a4378));
          }
          else if (param_3 == 2) {
            (**(code **)(param_1 + 0x90))
                      (param_5[iVar3],local_12c,param_2,*(undefined4 *)(param_1 + DAT_021a4378));
          }
          if (iVar2 == *(int *)(param_2 + DAT_021a4374)) {
            FUN_021a471c(param_2,DAT_021a4388);
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < local_134);
      }
      local_12c = local_12c + 1;
    } while (local_12c < (int)local_130);
  }
  return;
}

