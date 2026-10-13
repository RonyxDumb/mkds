/* Decompiled C draft; module arm9_ov003; ROM address 021d29e8. No matching claim. */
#include "types.h"
#include "deps/021d29e8_FUN_021d29e8.h"

undefined4 FUN_021d29e8(ushort *param_1)

{
  int iVar1;
  
  iVar1 = *DAT_021d2a30;
  if (-1 < (int)((uint)*(byte *)(iVar1 + 0x38) << 0x1d)) {
    return 0;
  }
  if (*(ushort *)(iVar1 + 0x28) < *param_1) {
    return 0;
  }
  if (param_1[2] < *(ushort *)(iVar1 + 0x28)) {
    return 0;
  }
  if (*(ushort *)(iVar1 + 0x2a) < param_1[1]) {
    return 0;
  }
  if (*(ushort *)(iVar1 + 0x2a) <= param_1[3]) {
    return 1;
  }
  return 0;
}

