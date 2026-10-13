/* Decompiled C draft; module arm9; ROM address 02061704. No matching claim. */
#include "types.h"
#include "deps/02061704_func_02061704.h"

undefined4 func_02061704(int param_1,ushort *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 + 8U & 3;
  uVar1 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if ((int)(uVar2 << 0x1f) < 0) {
    *(byte *)(param_2 + 1) = (byte)((uVar2 << 0x11) >> 0x19);
    uVar2 = param_1 + 8U & 3;
    uVar1 = *(uint *)(param_1 + 8U & 0xfffffffc);
    *(byte *)((int)param_2 + 3) =
         (byte)(((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) << 10) >> 0x19);
    uVar2 = param_1 + 8U & 3;
    uVar1 = *(uint *)(param_1 + 8U & 0xfffffffc);
    *param_2 = (ushort)((ushort)((uVar1 >> uVar2 * 8) >> 0x10) |
                       (ushort)((uVar1 << uVar2 * -8 + 0x20) >> 0x10)) >> 6;
    return 1;
  }
  return 0;
}

