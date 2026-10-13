/* Decompiled C draft; module arm9; ROM address 020b41e8. No matching claim. */
#include "types.h"
#include "deps/020b41e8_MaybeSomePlayerTilePaletteCopy.h"

void MaybeSomePlayerTilePaletteCopy(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  uVar8 = *(uint *)(uRam020b4420 & 0xfffffffc) >> (uRam020b4420 & 3) * 8 |
          *(uint *)(uRam020b4420 & 0xfffffffc) << (uRam020b4420 & 3) * -8 + 0x20;
  uVar2 = uVar8 + 0xc & 3;
  uVar1 = *(uint *)(uVar8 + 0xc & 0xfffffffc);
  if ((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) == 1) {
    uVar2 = (uint)*(byte *)(uVar8 + 99);
  }
  else {
    uVar2 = (uint)*(char *)(uVar8 + 0x62);
  }
  uVar2 = (uVar2 & 0xffff) * 0x30 + uVar8 + 0x68;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  if (uVar2 == 0xc) {
    iVar3 = GetPortraitShyGuyPalette_from_thumb(1);
  }
  else {
    iVar3 = GetPortraitPalette_from_thumb(1);
  }
  iVar4 = GetPortraitNceNcgr_from_thumb(1);
  uVar1 = iVar3 + 0xcU & 3;
  uVar5 = *(uint *)(iVar3 + 0xcU & 0xfffffffc);
  uVar8 = uVar2;
  if (uVar2 == 0xc) {
    uVar7 = *(uint *)(uRam020b4420 & 0xfffffffc) >> (uRam020b4420 & 3) * 8 |
            *(uint *)(uRam020b4420 & 0xfffffffc) << (uRam020b4420 & 3) * -8 + 0x20;
    uVar8 = uVar7 + 0xc & 3;
    uVar6 = *(uint *)(uVar7 + 0xc & 0xfffffffc);
    if ((uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) == 1) {
      uVar8 = (uint)*(byte *)(uVar7 + 99);
    }
    else {
      uVar8 = (uint)*(char *)(uVar7 + 0x62);
    }
    uVar8 = (*(uint *)(uRam020b4424 & 0xfffffffc) >> (uRam020b4424 & 3) * 8 |
            *(uint *)(uRam020b4424 & 0xfffffffc) << (uRam020b4424 & 3) * -8 + 0x20) +
            ((uVar8 << 0x10) >> 0xe) + 0x10c;
    uVar6 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    uVar8 = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
  }
  iVar3 = uVar8 << 4;
  param_2 = param_2 << 4;
  iVar9 = 0;
  do {
    iVar9 = iVar9 + 1;
    *(undefined2 *)(param_1 + param_2 * 2) =
         *(undefined2 *)((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + iVar3 * 2);
    iVar3 = iVar3 + 1;
    param_2 = param_2 + 1;
  } while (iVar9 < 0x10);
  iVar9 = uVar2 * 0x19;
  uVar2 = iVar4 + 0x14U & 3;
  uVar1 = *(uint *)(iVar4 + 0x14U & 0xfffffffc);
  iVar10 = 0;
  iVar3 = iVar9;
  do {
    iVar11 = iVar10 >> 0x1f;
    CopyMemory16((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + iVar3 * 0x20,
                 param_3 + (param_4 + param_5 * 0x20 +
                           (((uint)(iVar10 * 0x40000000 + iVar11) >> 0x1e | iVar11 << 2) - iVar11))
                           * 0x20 + ((int)(iVar10 + ((uint)(iVar10 >> 1) >> 0x1e)) >> 2) * 0x400,
                 0x20);
    iVar10 = iVar10 + 1;
    iVar3 = iVar3 + 1;
  } while (iVar10 < 0x10);
  iVar11 = 0;
  uVar2 = iVar4 + 0x14U & 3;
  uVar1 = *(uint *)(iVar4 + 0x14U & 0xfffffffc);
  iVar10 = 0;
  iVar3 = iVar9 + 0x10;
  do {
    CopyMemory16((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + iVar3 * 0x20,
                 param_3 + (param_4 + 4 + param_5 * 0x20) * 0x20 + iVar10 * 2,0x20);
    iVar11 = iVar11 + 1;
    iVar10 = iVar10 + 0x200;
    iVar3 = iVar3 + 1;
  } while (iVar11 < 4);
  uVar2 = iVar4 + 0x14U & 3;
  uVar1 = *(uint *)(iVar4 + 0x14U & 0xfffffffc);
  iVar3 = iVar9 + 0x14;
  iVar10 = 0;
  do {
    iVar11 = iVar10 >> 0x1f;
    CopyMemory16((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + iVar3 * 0x20,
                 param_3 + (param_4 + (param_5 + 4) * 0x20 +
                           (((uint)(iVar10 * 0x40000000 + iVar11) >> 0x1e | iVar11 << 2) - iVar11))
                           * 0x20 + ((int)(iVar10 + ((uint)(iVar10 >> 1) >> 0x1e)) >> 2) * 0x400,
                 0x20);
    iVar10 = iVar10 + 1;
    iVar3 = iVar3 + 1;
  } while (iVar10 < 4);
  uVar2 = iVar4 + 0x14U & 3;
  uVar1 = *(uint *)(iVar4 + 0x14U & 0xfffffffc);
  CopyMemory16((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + (iVar9 + 0x18) * 0x20,
               param_3 + (param_4 + 4 + (param_5 + 4) * 0x20) * 0x20,0x20);
  return;
}

