/* Decompiled C draft; module arm9; ROM address 020fec30. No matching claim. */
#include "types.h"
#include "deps/020fec30_func_020fec30.h"

void func_020fec30(void)

{
  uint uVar1;
  byte bVar2;
  undefined1 uVar3;
  byte *pbVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  
  uVar8 = uRam020fecd8;
  iVar7 = iRam020fecd4;
  iVar6 = iRam020fecd0;
  puVar5 = puRam020feccc;
  pbVar4 = pbRam020fecc8;
  uVar13 = (uint)*pbRam020fecc8;
  if (uVar13 == 0xff) {
    return;
  }
  while( true ) {
    uVar1 = uVar8 & 3;
    uVar9 = *(uint *)(uVar8 & 0xfffffffc);
    bVar2 = *(byte *)(iVar6 + uVar13 * 2);
    if (*(ushort *)((uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20) + 0x724) <
        (ushort)*(byte *)(iVar6 + uVar13 * 2 + 1)) {
      return;
    }
    iVar10 = func_0205ad44();
    if (iVar10 == 0) break;
    uVar3 = *puVar5;
    *pbVar4 = bVar2;
    *(undefined1 *)(iVar6 + uVar13 * 2) = uVar3;
    *puVar5 = (char)uVar13;
    iVar10 = iVar7 + uVar13 * 0x20;
    uVar1 = iVar10 + 0x14U & 3;
    uVar11 = *(uint *)(iVar10 + 0x14U & 0xfffffffc);
    uVar9 = iVar10 + 0x18U & 3;
    uVar12 = *(uint *)(iVar10 + 0x18U & 0xfffffffc);
    func_0205a858(uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20,
                  uVar12 >> uVar9 * 8 | uVar12 << uVar9 * -8 + 0x20,iVar10,
                  *(undefined1 *)(iVar6 + uVar13 * 2 + 1));
    uVar13 = (uint)bVar2;
    if (bVar2 == 0xff) {
      return;
    }
  }
  return;
}

