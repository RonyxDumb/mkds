/* Decompiled C draft; module arm7; ROM address 03800988. No matching claim. */
#include "types.h"
#include "deps/03800988_FUN_03800988.h"

uint FUN_03800988(void)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  
  FUN_03800ae4(0xb8000000,0);
  puVar2 = DAT_038009e4;
  *DAT_038009e4 =
       (*(uint *)(DAT_038009e0 & 0xfffffffc) >> (DAT_038009e0 & 3) * 8 |
       *(uint *)(DAT_038009e0 & 0xfffffffc) << (DAT_038009e0 & 3) * -8 + 0x20) & 0xf8ffe000 |
       0xa7000000;
  do {
    uVar1 = (uint)puVar2 & 3;
    uVar3 = *(uint *)((uint)puVar2 & 0xfffffffc);
  } while (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x800000) == 0);
  return *(uint *)(DAT_038009e8 & 0xfffffffc) >> (DAT_038009e8 & 3) * 8 |
         *(uint *)(DAT_038009e8 & 0xfffffffc) << (DAT_038009e8 & 3) * -8 + 0x20;
}

