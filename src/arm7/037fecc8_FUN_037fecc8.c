/* Decompiled C draft; module arm7; ROM address 037fecc8. No matching claim. */
#include "types.h"
#include "deps/037fecc8_FUN_037fecc8.h"

void FUN_037fecc8(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if ((int)((uint)*(byte *)(DAT_037fed1c + param_1 * 0x24) << 0x1f) < 0) {
    FUN_037fe230((byte *)(uintptr_t)(DAT_037fed1c + param_1 * 0x24));
    uVar3 = *(uint *)(DAT_037fed20 & 0xfffffffc) >> (DAT_037fed20 & 3) * 8 |
            *(uint *)(DAT_037fed20 & 0xfffffffc) << (DAT_037fed20 & 3) * -8 + 0x20;
    if (uVar3 != 0) {
      uVar1 = uVar3 + 4 & 3;
      uVar2 = *(uint *)(uVar3 + 4 & 0xfffffffc);
      *(uint *)(uVar3 + 4) =
           (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & ~(1 << (param_1 & 0xff));
    }
  }
  return;
}

