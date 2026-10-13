/* Decompiled C draft; module arm7; ROM address 0601019c. No matching claim. */
#include "types.h"
#include "deps/0601019c_FUN_0601019c.h"

void FUN_0601019c(void)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  undefined2 *puVar4;
  
  uVar3 = *(uint *)(DAT_06010234 & 0xfffffffc) >> (DAT_06010234 & 3) * 8 |
          *(uint *)(DAT_06010234 & 0xfffffffc) << (DAT_06010234 & 3) * -8 + 0x20;
  puVar4 = (undefined2 *)(uVar3 + DAT_06010238);
  sVar1 = *(short *)(uVar3 + 0x404);
  if (sVar1 == 0x20) {
    FUN_06009f84();
    puVar4[2] = 0;
    puVar4[3] = 0;
    *puVar4 = 0x21;
    uVar3 = (uint)(puVar4 + 0xc) & 3;
    uVar2 = *(uint *)((uint)(puVar4 + 0xc) & 0xfffffffc);
    FUN_060098d4(*(undefined2 *)((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x10),
                 DAT_0601023c);
  }
  else if (sVar1 == 0x25) {
    uVar3 = (uint)(puVar4 + 0xe) & 3;
    uVar2 = *(uint *)((uint)(puVar4 + 0xe) & 0xfffffffc);
    *(undefined2 *)((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 4) = puVar4[2];
    uVar3 = (uint)(puVar4 + 0xe) & 3;
    uVar2 = *(uint *)((uint)(puVar4 + 0xe) & 0xfffffffc);
    *(undefined2 *)((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 6) = puVar4[3];
    if (puVar4[2] != 0) {
      FUN_06009ecc();
    }
    *puVar4 = 0;
    FUN_0600fafc();
  }
  return;
}

