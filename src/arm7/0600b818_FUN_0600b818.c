/* Decompiled C draft; module arm7; ROM address 0600b818. No matching claim. */
#include "types.h"
#include "deps/0600b818_FUN_0600b818.h"

undefined4 FUN_0600b818(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *(uint *)(DAT_0600b8d0 & 0xfffffffc) >> (DAT_0600b8d0 & 3) * 8 |
          *(uint *)(DAT_0600b8d0 & 0xfffffffc) << (DAT_0600b8d0 & 3) * -8 + 0x20;
  if (param_1 < 2) {
    *(ushort *)(uVar3 + 0x33a) = *(ushort *)(uVar3 + 0x33a) & 0xfffb | (ushort)((param_1 & 1) << 2);
    if (param_1 == 0) {
      *(ushort *)(uVar3 + 0x3c0) = *(ushort *)(uVar3 + 0x3c0) & 0xffdf;
    }
    else {
      *(ushort *)(uVar3 + 0x3c0) = *(ushort *)(uVar3 + 0x3c0) | 0x20;
    }
    if ((*(short *)(uVar3 + 0x34c) == 0x40) &&
       (uVar4 = *(uint *)(DAT_0600b8d0 & 0xfffffffc) >> (DAT_0600b8d0 & 3) * 8 |
                *(uint *)(DAT_0600b8d0 & 0xfffffffc) << (DAT_0600b8d0 & 3) * -8 + 0x20,
       *(short *)(uVar4 + 0x32e) == 1)) {
      uVar4 = uVar4 + 0x4ac;
      uVar1 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      *(undefined2 *)((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + 0x2e) =
           *(undefined2 *)(uVar3 + 0x3c0);
    }
    if (param_1 == 0) {
      *DAT_0600b8d4 = *DAT_0600b8d4 & 0xfff9;
    }
    else {
      *DAT_0600b8d4 = *DAT_0600b8d4 | 6;
    }
    FUN_0600aea0();
    uVar2 = 0;
  }
  else {
    uVar2 = 5;
  }
  return uVar2;
}

