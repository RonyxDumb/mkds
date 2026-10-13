/* Decompiled C draft; module arm7; ROM address 037f91a8. No matching claim. */
#include "types.h"
#include "deps/037f91a8_FUN_037f91a8.h"

void FUN_037f91a8(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(DAT_037f91f0 & 0xfffffffc) >> (DAT_037f91f0 & 3) * 8 |
          *(uint *)(DAT_037f91f0 & 0xfffffffc) << (DAT_037f91f0 & 3) * -8 + 0x20;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  FUN_037f8d78();
  FUN_037f9960(uVar2);
  FUN_037f94d4(uVar2);
  *(undefined4 *)(uVar2 + 0x48) = 2;
  FUN_037f9088(uVar2 + 0x80);
  FUN_037f8d40();
  FUN_037f8f48();
  FUN_037fb000();
  return;
}

