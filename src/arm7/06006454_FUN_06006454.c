/* Decompiled C draft; module arm7; ROM address 06006454. No matching claim. */
#include "types.h"
#include "deps/06006454_FUN_06006454.h"

void FUN_06006454(void)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = FUN_06000680();
  uVar5 = iVar2 + 0x154cU & 3;
  uVar4 = *(uint *)(iVar2 + 0x154cU & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar1 = *DAT_060064ec;
  if (((0xcf < uVar1) && (uVar1 < 0xd4)) &&
     (uVar4 = (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
              *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0xd4, uVar3 = uVar4 & 3,
     uVar4 = *(uint *)(uVar4 & 0xfffffffc), uVar4 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20,
     0x7e < uVar4)) {
    for (iVar2 = 1; (iVar2 < 7 && (iVar2 * 0x3f + 0x7fU <= uVar4)); iVar2 = iVar2 + 1) {
    }
    *DAT_060064ec = uVar1 + (1 - (short)iVar2);
    uVar3 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
            *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
    uVar5 = uVar3 + 0xd4;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(uVar3 + 0xd4) = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + iVar2 * -0x3f;
  }
  return;
}

