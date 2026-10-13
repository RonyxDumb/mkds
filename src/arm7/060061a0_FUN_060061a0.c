/* Decompiled C draft; module arm7; ROM address 060061a0. No matching claim. */
#include "types.h"
#include "deps/060061a0_FUN_060061a0.h"

void FUN_060061a0(void)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = FUN_06000680();
  uVar3 = iVar2 + 0x154cU & 3;
  uVar4 = *(uint *)(iVar2 + 0x154cU & 0xfffffffc);
  uVar4 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  uVar3 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
  uVar1 = *(ushort *)(uVar3 + 0xd8);
  if (uVar1 < 0x3c) {
    *(ushort *)(uVar3 + 0xd8) = uVar1 + 1;
  }
  else {
    uVar1 = *DAT_0600621c;
    if ((0xd0 < uVar1) && (uVar1 < 0xd4)) {
      *DAT_0600621c = uVar1;
      *(undefined2 *)
       ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
        *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0xd8) = 0;
    }
  }
  FUN_060065fc();
  thunk_FUN_037fad34(uVar4 + 0xd0,0x104,DAT_06006220,DAT_06006224,0x104);
  return;
}

