/* Decompiled C draft; module arm7; ROM address 037f91f4. No matching claim. */
#include "types.h"
#include "deps/037f91f4_FUN_037f91f4.h"

void FUN_037f91f4(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar4;
  code *pcVar3;
  
  uVar1 = *(uint *)(DAT_037f9238 & 0xfffffffc) >> (DAT_037f9238 & 3) * 8 |
          *(uint *)(DAT_037f9238 & 0xfffffffc) << (DAT_037f9238 & 3) * -8 + 0x20;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar4 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  uVar2 = uVar4 + 0x98;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  pcVar3 = (code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  if (pcVar3 != (code *)0x0) {
    *(undefined4 *)(uVar4 + 0x98) = 0;
    (*pcVar3)();
    FUN_037faf70();
  }
  FUN_037f91a8();
  return;
}

