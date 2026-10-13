/* Decompiled C draft; module arm9_ov000; ROM address 021a3fc8. No matching claim. */
#include "types.h"
#include "deps/021a3fc8_FUN_021a3fc8.h"

void FUN_021a3fc8(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int local_1b4;
  int local_1b0;
  int local_1ac;
  byte *local_1a8;
  int local_1a0;
  undefined1 auStack_19c [128];
  byte local_11c [256];
  int local_1c;
  
  local_1c = 0;
  if (param_3 - 1U < 2) {
    local_1b4 = (**(code **)(param_1 + 0x98))(param_3,*(undefined4 *)(param_1 + DAT_021a4114));
  }
  else {
    local_1b4 = 1;
  }
  (**(code **)(param_1 + 0x94))(param_3,local_11c,*(undefined4 *)(param_1 + DAT_021a4114));
  local_1b0 = 0;
  if (0 < local_1c) {
    local_1a8 = local_11c;
    local_1a0 = 0;
    do {
      local_1ac = *(int *)(DAT_021a4118 + (uint)*local_1a8 * 4);
      if (local_1ac == 0) {
        local_1ac = DAT_021a411c;
      }
      if (param_3 == 0) {
        FUN_021a471c(param_2,local_1ac);
        *(undefined1 *)(param_2 + *(int *)(param_2 + DAT_021a4120) + -1) = 0x5c;
        iVar2 = *(int *)(param_2 + DAT_021a4120);
        (**(code **)(param_1 + 0x88))(*local_1a8,param_2,*(undefined4 *)(param_1 + DAT_021a4114));
        if (iVar2 == *(int *)(param_2 + DAT_021a4120)) {
          FUN_021a471c(param_2,DAT_021a4124);
        }
        *(undefined1 *)(param_2 + *(int *)(param_2 + DAT_021a4120) + -1) = 0x5c;
      }
      else {
        iVar2 = local_1a0;
        if (0 < local_1b4) {
          do {
            func_0x02135014((undefined4)(uintptr_t)(auStack_19c),DAT_021a4128,local_1ac,iVar2);
            FUN_021a471c(param_2,(undefined4)(uintptr_t)(auStack_19c));
            *(undefined1 *)(param_2 + *(int *)(param_2 + DAT_021a4120) + -1) = 0x5c;
            iVar1 = *(int *)(param_2 + DAT_021a4120);
            if (param_3 == 1) {
              (**(code **)(param_1 + 0x8c))
                        (*local_1a8,iVar2,param_2,*(undefined4 *)(param_1 + DAT_021a4114));
            }
            else if (param_3 == 2) {
              (**(code **)(param_1 + 0x90))
                        (*local_1a8,iVar2,param_2,*(undefined4 *)(param_1 + DAT_021a4114));
            }
            if (iVar1 == *(int *)(param_2 + DAT_021a4120)) {
              FUN_021a471c(param_2,DAT_021a4124);
            }
            *(undefined1 *)(param_2 + *(int *)(param_2 + DAT_021a4120) + -1) = 0x5c;
            iVar2 = iVar2 + 1;
          } while (iVar2 < local_1b4);
        }
      }
      local_1a8 = local_1a8 + 1;
      local_1b0 = local_1b0 + 1;
    } while (local_1b0 < local_1c);
  }
  return;
}

