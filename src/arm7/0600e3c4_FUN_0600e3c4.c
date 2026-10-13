/* Decompiled C draft; module arm7; ROM address 0600e3c4. No matching claim. */
#include "types.h"
#include "deps/0600e3c4_FUN_0600e3c4.h"

void FUN_0600e3c4(void)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = *(uint *)(DAT_0600e46c & 0xfffffffc) >> (DAT_0600e46c & 3) * 8 |
          *(uint *)(DAT_0600e46c & 0xfffffffc) << (DAT_0600e46c & 3) * -8 + 0x20;
  uVar4 = uVar2 + 0x31c;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  uVar3 = (uint)*(ushort *)(uVar2 + 0x322);
  thunk_FUN_037fb218(0,uVar5,uVar3 * 0x1c);
  thunk_FUN_037fb218(0,(*(uint *)(DAT_0600e46c & 0xfffffffc) >> (DAT_0600e46c & 3) * 8 |
                       *(uint *)(DAT_0600e46c & 0xfffffffc) << (DAT_0600e46c & 3) * -8 + 0x20) +
                       DAT_0600e470,0x10);
  uVar1 = (undefined2)DAT_0600e474;
  *(undefined2 *)(uVar5 + 0x1a) = uVar1;
  for (uVar4 = 1; uVar4 < uVar3; uVar4 = uVar4 + 1) {
    *(undefined2 *)(uVar4 * 0x1c + uVar5 + 0x1a) = uVar1;
  }
  FUN_0600e248(0,DAT_0600e478);
  FUN_0600ebbc(0,0x40);
  return;
}

