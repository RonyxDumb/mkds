/* Decompiled C draft; module arm9; ROM address 020c5df0. No matching claim. */
#include "types.h"
#include "deps/020c5df0_StructE8_SomeFnHandle6.h"

void StructE8_SomeFnHandle6(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = uRam020c5e28;
  uVar4 = *(uint *)(uRam020c5e28 & 0xfffffffc) >> (uRam020c5e28 & 3) * 8 |
          *(uint *)(uRam020c5e28 & 0xfffffffc) << (uRam020c5e28 & 3) * -8 + 0x20;
  uVar3 = uVar4 + 4;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  *(uint *)(uVar4 + 4) = uVar3 + 1;
  if ((int)uVar3 < 0x3c) {
    return;
  }
  *(undefined4 *)
   (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
   *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) = uRam020c5e2c;
  *(undefined4 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 4) = 0;
  return;
}

