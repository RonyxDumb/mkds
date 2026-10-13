/* Decompiled C draft; module arm7; ROM address 037f86ac. No matching claim. */
#include "types.h"
#include "deps/037f86ac_FUN_037f86ac.h"

void FUN_037f86ac(void)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  
  uVar1 = DAT_037f86f8 + 0x60U & 3;
  uVar2 = *(uint *)(DAT_037f86f8 + 0x60U & 0xfffffffc);
  pcVar3 = (code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  *DAT_037f86fc =
       (*(uint *)((uint)DAT_037f86fc & 0xfffffffc) >> ((uint)DAT_037f86fc & 3) * 8 |
       *(uint *)((uint)DAT_037f86fc & 0xfffffffc) << ((uint)DAT_037f86fc & 3) * -8 + 0x20) + 1;
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)();
  }
  *DAT_037f8700 =
       *(uint *)((uint)DAT_037f8700 & 0xfffffffc) >> ((uint)DAT_037f8700 & 3) * 8 |
       *(uint *)((uint)DAT_037f8700 & 0xfffffffc) << ((uint)DAT_037f8700 & 3) * -8 + 0x20 | 1;
  return;
}

