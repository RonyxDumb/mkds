/* Decompiled C draft; module arm9_ov001; ROM address 02199374. No matching claim. */
#include "types.h"
#include "deps/02199374_FUN_02199374.h"

void FUN_02199374(void)

{
  uint uVar1;
  
  uVar1 = ((uint)*(byte *)(*(int *)*DAT_021993b0 + 0x31) << 0x1d) >> 0x1e;
  if (uVar1 == 0) {
    *(undefined4 *)(*DAT_021993b4 + 0xc) = 0;
    return;
  }
  if (uVar1 != 1) {
    if (uVar1 != 2) {
      return;
    }
    *(undefined4 *)(*DAT_021993b4 + 0xc) = 2;
    return;
  }
  *(undefined4 *)(*DAT_021993b4 + 0xc) = 1;
  return;
}

