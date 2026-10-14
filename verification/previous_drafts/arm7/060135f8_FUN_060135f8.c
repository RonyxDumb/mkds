/* Decompiled C draft; module arm7; ROM address 060135f8. No matching claim. */
#include "types.h"
#include "deps/060135f8_FUN_060135f8.h"

void FUN_060135f8(ushort param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined2 *puVar4;
  
  uVar1 = DAT_06013644;
  uVar3 = (*(uint *)(DAT_06013644 & 0xfffffffc) >> (DAT_06013644 & 3) * 8 |
          *(uint *)(DAT_06013644 & 0xfffffffc) << (DAT_06013644 & 3) * -8 + 0x20) + 0x45c;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  puVar4 = (undefined2 *)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  *puVar4 = 0;
  puVar4[1] = 0;
  puVar4[2] = 0;
  puVar4[5] = 0x14;
  puVar4[6] = 0xa4;
  puVar4[7] = param_1 | 0xc000;
  uVar3 = uVar1 & 3;
  uVar2 = *(uint *)(uVar1 & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
                    /* WARNING: Could not recover jumptable at 0x06013640. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_06013648)(puVar4 + 8,uVar3 + 0x3a8,uVar3 + 0x324);
  return;
}

