/* Decompiled C draft; module arm7; ROM address 0600e32c. No matching claim. */
#include "types.h"
#include "deps/0600e32c_FUN_0600e32c.h"

void FUN_0600e32c(void)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  undefined2 *puVar4;
  uint uVar5;
  
  uVar3 = *(uint *)(DAT_0600e3b8 & 0xfffffffc) >> (DAT_0600e3b8 & 3) * 8 |
          *(uint *)(DAT_0600e3b8 & 0xfffffffc) << (DAT_0600e3b8 & 3) * -8 + 0x20;
  uVar1 = uVar3 + 0x31c & 3;
  uVar5 = *(uint *)(uVar3 + 0x31c & 0xfffffffc);
  puVar4 = (undefined2 *)(uVar3 + DAT_0600e3bc);
  uVar2 = *(ushort *)(uVar3 + 0x322);
  for (uVar3 = 1; uVar3 < uVar2; uVar3 = uVar3 + 1) {
    thunk_FUN_037fb218(0,uVar3 * 0x1c + (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20),0x1a);
  }
  *puVar4 = 1;
  puVar4[1] = 0;
  puVar4[2] = 1;
  puVar4[3] = (short)DAT_0600e3c0;
  puVar4[6] = 0;
  puVar4[4] = 0;
  puVar4[7] = 1;
  return;
}

