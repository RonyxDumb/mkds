/* Decompiled C draft; module arm7; ROM address 0600b668. No matching claim. */
#include "types.h"
#include "deps/0600b668_FUN_0600b668.h"

undefined4 FUN_0600b668(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_1 < 2) && (param_2 < 2)) {
    if (param_1 == 0) {
      uVar2 = *(uint *)(DAT_0600b73c & 0xfffffffc) >> (DAT_0600b73c & 3) * 8 |
              *(uint *)(DAT_0600b73c & 0xfffffffc) << (DAT_0600b73c & 3) * -8 + 0x20;
      *(ushort *)(uVar2 + 0x33a) =
           *(ushort *)(uVar2 + 0x33a) & 0xffdf | (ushort)((param_2 & 1) << 5);
    }
    else if (param_1 == 1) {
      uVar2 = *(uint *)(DAT_0600b73c & 0xfffffffc) >> (DAT_0600b73c & 3) * 8 |
              *(uint *)(DAT_0600b73c & 0xfffffffc) << (DAT_0600b73c & 3) * -8 + 0x20;
      if (*(short *)(uVar2 + 0x32e) != 1) {
        return 0xb;
      }
      *(ushort *)(uVar2 + 0x33a) = *(ushort *)(uVar2 + 0x33a) & 0xffdf;
    }
    uVar1 = DAT_0600b73c;
    uVar2 = *(uint *)(DAT_0600b73c & 0xfffffffc) >> (DAT_0600b73c & 3) * 8 |
            *(uint *)(DAT_0600b73c & 0xfffffffc) << (DAT_0600b73c & 3) * -8 + 0x20;
    *(ushort *)(uVar2 + 0x33a) = *(ushort *)(uVar2 + 0x33a) & 0xffef | (ushort)((param_1 & 1) << 4);
    uVar2 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    uVar2 = (uint)*(ushort *)((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0x33a);
    *DAT_0600b740 =
         (ushort)((ushort)((uVar2 << 0x1a) >> 0x10) ^ (ushort)((uVar2 << 0x1c) >> 0x10)) >> 0xf;
    return 0;
  }
  return 5;
}

