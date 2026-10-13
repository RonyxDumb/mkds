/* Decompiled C draft; module arm7; ROM address 03803884. No matching claim. */
#include "types.h"
#include "deps/03803884_FUN_03803884.h"

void FUN_03803884(void)

{
  uint uVar1;
  uint uVar2;
  
  if ((*(uint *)((uint)DAT_038038c4 & 0xfffffffc) >> ((uint)DAT_038038c4 & 3) * 8 |
      *(uint *)((uint)DAT_038038c4 & 0xfffffffc) << ((uint)DAT_038038c4 & 3) * -8 + 0x20) ==
      DAT_038038c8) {
    FUN_037faf70();
    uVar1 = DAT_038038cc + 0xcU & 3;
    uVar2 = *(uint *)(DAT_038038cc + 0xcU & 0xfffffffc);
    *DAT_038038c4 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    FUN_037faf84();
  }
  return;
}

