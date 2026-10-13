/* Decompiled C draft; module arm9_ov001; ROM address 02187eb0. No matching claim. */
#include "types.h"
#include "deps/02187eb0_FUN_02187eb0.h"

void FUN_02187eb0(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + DAT_02187ee0) < (int)(uint)*(ushort *)(*DAT_02187edc + 0xc)) {
    iVar1 = *(int *)(param_1 + DAT_02187ee4) + -1;
    if (iVar1 < 1) {
      iVar1 = *(ushort *)
               (*(int *)(*DAT_02187edc + 8) +
                ((uint)(*(int *)(param_1 + DAT_02187ee0) << 0x10) >> 0xe) + 2) - 1;
    }
    *(int *)(param_1 + DAT_02187ee4) = iVar1;
  }
  return;
}

