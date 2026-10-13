/* Decompiled C draft; module arm9_ov003; ROM address 021d2a80. No matching claim. */
#include "types.h"
#include "deps/021d2a80_FUN_021d2a80.h"

undefined4 FUN_021d2a80(ushort *param_1)

{
  int iVar1;
  
  iVar1 = *DAT_021d2ac8;
  if ((*(byte *)(iVar1 + 0x38) & 1) == 0) {
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

