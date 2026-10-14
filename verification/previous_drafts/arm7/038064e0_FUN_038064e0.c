/* Decompiled C draft; module arm7; ROM address 038064e0. No matching claim. */
#include "types.h"
#include "deps/038064e0_FUN_038064e0.h"

void FUN_038064e0(void)

{
  int iVar1;
  
  FUN_0380675c();
  FUN_03806798(*(uint *)(DAT_03806534 & 0xfffffffc) >> (DAT_03806534 & 3) * 8 |
               *(uint *)(DAT_03806534 & 0xfffffffc) << (DAT_03806534 & 3) * -8 + 0x20);
  do {
    iVar1 = FUN_037fb5f4(0xf,0x10000,0);
  } while (iVar1 < 0);
  FUN_037faf70();
  *DAT_03806538 = 3;
  FUN_037f92a4();
  return;
}

