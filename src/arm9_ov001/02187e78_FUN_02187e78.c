/* Decompiled C draft; module arm9_ov001; ROM address 02187e78. No matching claim. */
#include "types.h"
#include "deps/02187e78_FUN_02187e78.h"

void FUN_02187e78(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + DAT_02187ea8) < (int)(uint)*(ushort *)(*DAT_02187ea4 + 0xc)) {
    iVar1 = *(int *)(param_1 + DAT_02187eac) + 1;
    if ((int)(uint)*(ushort *)
                    (*(int *)(*DAT_02187ea4 + 8) +
                     ((uint)(*(int *)(param_1 + DAT_02187ea8) << 0x10) >> 0xe) + 2) <= iVar1) {
      iVar1 = 0;
    }
    *(int *)(param_1 + DAT_02187eac) = iVar1;
  }
  return;
}

