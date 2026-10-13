/* Decompiled C draft; module arm7; ROM address 037f8ab4. No matching claim. */
#include "types.h"
#include "deps/037f8ab4_FUN_037f8ab4.h"

void FUN_037f8ab4(int param_1)

{
  uint *puVar1;
  uint uVar2;
  
  if (param_1 + -0xa0 < 0) {
    uVar2 = param_1 - 0x80;
    puVar1 = DAT_037f8ae0;
  }
  else {
    uVar2 = param_1 - 0xa0;
    puVar1 = DAT_037f8ae0 + 1;
  }
  *puVar1 = *(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
            *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20 |
            0x80000000U >> (uVar2 & 0xff);
  return;
}

