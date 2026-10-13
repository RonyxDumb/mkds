/* Decompiled C draft; module arm7; ROM address 060066dc. No matching claim. */
#include "types.h"
#include "deps/060066dc_FUN_060066dc.h"

void FUN_060066dc(void)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = FUN_06000680();
  uVar4 = iVar2 + 0x154cU & 3;
  uVar5 = *(uint *)(iVar2 + 0x154cU & 0xfffffffc);
  uVar5 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  uVar4 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
          *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
  sVar1 = *(short *)(uVar4 + 0xe2);
  if (sVar1 == 1) {
    uVar4 = uVar5 + 0xd0 & 3;
    uVar3 = *(uint *)(uVar5 + 0xd0 & 0xfffffffc);
    if (uVar3 >> uVar4 * 8 != 0 || uVar3 << uVar4 * -8 + 0x20 != 0) {
      thunk_FUN_037fabc0(uVar5 + 0xd0);
    }
    thunk_FUN_037fad34(uVar5 + 0xd0,0xd1,DAT_06006784,DAT_06006788,0xd1);
  }
  else if (sVar1 == 2) {
    *(undefined4 *)(uVar4 + 0x1c) = 0;
    uVar4 = uVar5 + 0xd0 & 3;
    uVar3 = *(uint *)(uVar5 + 0xd0 & 0xfffffffc);
    if (uVar3 >> uVar4 * 8 != 0 || uVar3 << uVar4 * -8 + 0x20 != 0) {
      thunk_FUN_037fabc0(uVar5 + 0xd0);
    }
    thunk_FUN_037fad34(uVar5 + 0xd0,200,DAT_06006784,DAT_06006788,200);
    *(undefined4 *)
     ((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
      *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0xd4) = 0;
  }
  return;
}

