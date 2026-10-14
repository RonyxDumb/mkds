/* Decompiled C draft; module arm7; ROM address 0601429c. No matching claim. */
#include "types.h"
#include "deps/0601429c_FUN_0601429c.h"

void FUN_0601429c(void)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  undefined2 *puVar4;
  
  uVar3 = *(uint *)(DAT_06014328 & 0xfffffffc) >> (DAT_06014328 & 3) * 8 |
          *(uint *)(DAT_06014328 & 0xfffffffc) << (DAT_06014328 & 3) * -8 + 0x20;
  puVar4 = (undefined2 *)(uVar3 + DAT_0601432c);
  puVar4[1] = puVar4[1] + 1;
  if (*(short *)(uVar3 + 0x454) == 0) {
    *puVar4 = 1;
    uVar3 = (uint)(puVar4 + 4) & 3;
    uVar2 = *(uint *)((uint)(puVar4 + 4) & 0xfffffffc);
    *(undefined2 *)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) = 0;
    uVar3 = (uint)(puVar4 + 4) & 3;
    uVar2 = *(uint *)((uint)(puVar4 + 4) & 0xfffffffc);
    *(undefined2 *)((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 4) = 0;
    uVar1 = FUN_0600a450();
    uVar3 = (uint)(puVar4 + 4) & 3;
    uVar2 = *(uint *)((uint)(puVar4 + 4) & 0xfffffffc);
    *(undefined2 *)((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 8) = uVar1;
    uVar3 = (uint)(puVar4 + 4) & 3;
    uVar2 = *(uint *)((uint)(puVar4 + 4) & 0xfffffffc);
    *DAT_06014334 =
         (ushort)((((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & DAT_06014330) << 0xf) >>
                 0x10) | 0x8000;
  }
  else {
    uVar3 = (uint)(puVar4 + 4) & 3;
    uVar2 = *(uint *)((uint)(puVar4 + 4) & 0xfffffffc);
    *(undefined2 *)((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 4) = 0;
  }
  return;
}

