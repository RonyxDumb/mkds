/* Decompiled C draft; module arm9_ov003; ROM address 021d299c. No matching claim. */
#include "types.h"
#include "deps/021d299c_FUN_021d299c.h"

undefined4 FUN_021d299c(ushort *param_1)

{
  int iVar1;
  
  iVar1 = *DAT_021d29e4;
  if (-1 < (int)((uint)*(byte *)(iVar1 + 0x38) << 0x1c)) {
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

