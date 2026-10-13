/* Decompiled C draft; module arm7; ROM address 0600b9c8. No matching claim. */
#include "types.h"
#include "deps/0600b9c8_FUN_0600b9c8.h"

undefined4 FUN_0600b9c8(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_0600b9fc;
  if (param_1 < 0x100) {
    *(undefined2 *)
     ((*(uint *)(DAT_0600b9fc & 0xfffffffc) >> (DAT_0600b9fc & 3) * 8 |
      *(uint *)(DAT_0600b9fc & 0xfffffffc) << (DAT_0600b9fc & 3) * -8 + 0x20) + 0x3c4) = 0;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    *(short *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x3c2) = (short)param_1;
    return 0;
  }
  return 5;
}

