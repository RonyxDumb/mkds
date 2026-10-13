/* Decompiled C draft; module arm9_ov000; ROM address 021abca0. No matching claim. */
#include "types.h"
#include "deps/021abca0_FUN_021abca0.h"

void FUN_021abca0(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint local_18;
  
  local_18 = *(uint *)(param_1 + 0x18) >> 3 & 0x3f;
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) + param_3 * 8;
  if (*(uint *)(param_1 + 0x18) < param_3 * 8) {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  }
  *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + (param_3 >> 0x1d);
  uVar1 = -local_18;
  uVar2 = uVar1 + 0x40;
  if (param_3 < uVar2) {
    uVar3 = 0;
  }
  else {
    func_0x0214d1fc((ushort *)(uintptr_t)(param_2),(uint *)(uintptr_t)(param_1 + 0x1c + local_18),uVar2);
    local_18 = 0;
    FUN_021abd68((uint *)(uintptr_t)(param_1),param_1 + 0x1c);
    while (uVar3 = uVar2, uVar1 + 0x7f < param_3) {
      FUN_021abd68((uint *)(uintptr_t)(param_1),param_2 + uVar3);
      uVar2 = uVar3 + 0x40;
      uVar1 = uVar3;
    }
  }
  func_0x0214d1fc((ushort *)(uintptr_t)(param_2 + uVar3),(uint *)(uintptr_t)(param_1 + 0x1c + local_18),param_3 - uVar3);
  return;
}

