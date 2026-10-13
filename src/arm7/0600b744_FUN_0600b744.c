/* Decompiled C draft; module arm7; ROM address 0600b744. No matching claim. */
#include "types.h"
#include "deps/0600b744_FUN_0600b744.h"

undefined4 FUN_0600b744(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = DAT_0600b7a4;
  if (param_1 < 2) {
    uVar2 = *(uint *)(DAT_0600b7a4 & 0xfffffffc) >> (DAT_0600b7a4 & 3) * 8 |
            *(uint *)(DAT_0600b7a4 & 0xfffffffc) << (DAT_0600b7a4 & 3) * -8 + 0x20;
    *(ushort *)(uVar2 + 0x33a) = *(ushort *)(uVar2 + 0x33a) & 0xfff7 | (ushort)((param_1 & 1) << 3);
    uVar2 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    uVar1 = (uint)*(ushort *)((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0x33a);
    *DAT_0600b7a8 =
         (ushort)((ushort)((uVar1 << 0x1a) >> 0x10) ^ (ushort)((uVar1 << 0x1c) >> 0x10)) >> 0xf;
    return 0;
  }
  return 5;
}

