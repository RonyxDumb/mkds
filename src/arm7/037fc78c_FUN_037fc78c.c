/* Decompiled C draft; module arm7; ROM address 037fc78c. No matching claim. */
#include "types.h"
#include "deps/037fc78c_FUN_037fc78c.h"

void FUN_037fc78c(int param_1)

{
  uint uVar1;
  
  if (*(ushort *)(param_1 + 4) <= *(ushort *)(param_1 + 6)) {
    for (uVar1 = (uint)*(ushort *)(param_1 + 8) + (uint)*(byte *)(param_1 + 1) * 0x40 >> 8;
        0x7f < uVar1; uVar1 = uVar1 - 0x80) {
    }
    *(ushort *)(param_1 + 8) = *(short *)(param_1 + 8) + (ushort)*(byte *)(param_1 + 1) * 0x40;
    *(ushort *)(param_1 + 8) = *(ushort *)(param_1 + 8) & 0xff;
    *(ushort *)(param_1 + 8) = *(ushort *)(param_1 + 8) | (ushort)(uVar1 << 8);
    return;
  }
  *(ushort *)(param_1 + 6) = *(ushort *)(param_1 + 6) + 1;
  return;
}

