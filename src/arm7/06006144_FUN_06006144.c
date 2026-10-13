/* Decompiled C draft; module arm7; ROM address 06006144. No matching claim. */
#include "types.h"
#include "deps/06006144_FUN_06006144.h"

void FUN_06006144(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = FUN_06000680();
  uVar2 = iVar1 + 0x154cU & 3;
  uVar3 = *(uint *)(iVar1 + 0x154cU & 0xfffffffc);
  uVar4 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  uVar2 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0xc;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) == 1) {
    thunk_FUN_037fad34(uVar4 + 0xd0,0xd1,DAT_06006190,DAT_06006194,0xd1);
    FUN_0600608c();
  }
  return;
}

