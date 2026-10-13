/* Decompiled C draft; module arm7; ROM address 03805e74. No matching claim. */
#include "types.h"
#include "deps/03805e74_FUN_03805e74.h"

/* WARNING: Removing unreachable block (ram,0x03805f40) */

void FUN_03805e74(uint param_1)

{
  ushort local_18 [2];
  undefined1 auStack_14 [8];
  
  if (((param_1 & 1) == 1) && (FUN_03805b8c((undefined4)(uintptr_t)(local_18)), -1 < (int)((uint)local_18[0] << 0x1e))) {
    local_18[0] = local_18[0] & 0xfffd | (ushort)((param_1 & 1) << 1);
    FUN_03805b60((undefined4)(uintptr_t)(local_18));
    FUN_038057b4(0x86,0x10,(undefined4)(uintptr_t)(auStack_14),3);
    if ((param_1 & 1) == 0) {
      FUN_03805930((uint *)(void *)(auStack_14));
    }
    else {
      FUN_03805818((uint *)(void *)(auStack_14));
    }
    FUN_038057b4(6,0x10,(undefined4)(uintptr_t)(auStack_14),3);
    FUN_038057b4(0x86,0x50,(undefined4)(uintptr_t)(auStack_14),3);
    FUN_03805818((uint *)(void *)(auStack_14));
    FUN_038057b4(6,0x50,(undefined4)(uintptr_t)(auStack_14),3);
  }
  return;
}

