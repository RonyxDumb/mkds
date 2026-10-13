/* Decompiled C draft; module arm9; ROM address 02101d90. No matching claim. */
#include "types.h"
#include "deps/02101d90_func_02101d90.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_02101d90(int param_1,uint param_2)

{
  longlong lVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  uint uVar11;
  uint uVar13;
  uint uVar14;
  uint uVar16;
  uint uVar17;
  uint uVar12;
  uint uVar15;
  
  uVar5 = *(uint *)(uRam02101f60 & 0xfffffffc) >> (uRam02101f60 & 3) * 8 |
          *(uint *)(uRam02101f60 & 0xfffffffc) << (uRam02101f60 & 3) * -8 + 0x20;
  iVar7 = uVar5 + iRam02101f64;
  uVar17 = uVar5 + 0x47c & 3;
  uVar11 = *(uint *)(uVar5 + 0x47c & 0xfffffffc);
  uVar12 = uVar11 >> uVar17 * 8 | uVar11 << uVar17 * -8 + 0x20;
  uVar17 = iVar7 + 8U & 3;
  uVar11 = *(uint *)(iVar7 + 8U & 0xfffffffc);
  uVar13 = uVar11 >> uVar17 * 8 | uVar11 << uVar17 * -8 + 0x20;
  uVar17 = iVar7 + 4U & 3;
  uVar8 = *(uint *)(iVar7 + 4U & 0xfffffffc);
  lVar1 = (ulonglong)uVar12 * (ulonglong)uVar13;
  uVar16 = (uint)lVar1;
  uVar11 = iVar7 + 0xcU & 3;
  uVar9 = *(uint *)(iVar7 + 0xcU & 0xfffffffc);
  uVar6 = iVar7 + 0x10U & 3;
  uVar14 = *(uint *)(iVar7 + 0x10U & 0xfffffffc);
  uVar15 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
  uVar6 = iVar7 + 0x14U & 3;
  uVar14 = *(uint *)(iVar7 + 0x14U & 0xfffffffc);
  *(uint *)(uVar5 + 0x47c) = uVar15 + uVar16;
  *(uint *)(iVar7 + 4) =
       (uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20) +
       (uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) * uVar12 +
       uVar13 * (uVar8 >> uVar17 * 8 | uVar8 << uVar17 * -8 + 0x20) +
       (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar15,uVar16);
  uVar11 = *(uint *)(uRam02101f68 & 0xfffffffc) >> (uRam02101f68 & 3) * 8 |
           *(uint *)(uRam02101f68 & 0xfffffffc) << (uRam02101f68 & 3) * -8 + 0x20;
  uVar17 = iVar7 + 4U & 3;
  uVar6 = *(uint *)(iVar7 + 4U & 0xfffffffc);
  uVar17 = (uVar6 >> uVar17 * 8 | uVar6 << uVar17 * -8 + 0x20) >> 0x1d;
  uVar6 = uVar17 + 8;
  if ((*(ushort *)(param_1 + 0x78) & 0x8000) == 0) {
    uVar5 = *(ushort *)(param_1 + 0x78) & 0xffff00ff;
  }
  else {
    uVar5 = 8;
  }
  if (uVar6 <= uVar17) {
    return;
  }
  pbVar10 = (byte *)(iRam02101f70 + uVar17);
  bVar3 = true;
  do {
    uVar8 = (uint)*pbVar10;
    if ((uVar8 < *(byte *)(uVar11 + 0x3d0)) && (uVar8 != uVar5)) {
      iVar7 = uVar8 * 0x210 +
              (*(uint *)(uRam02101f6c & 0xfffffffc) >> (uRam02101f6c & 3) * 8 |
              *(uint *)(uRam02101f6c & 0xfffffffc) << (uRam02101f6c & 3) * -8 + 0x20);
      uVar9 = iVar7 + 0x1fcU & 3;
      uVar14 = *(uint *)(iVar7 + 0x1fcU & 0xfffffffc);
      uVar12 = uVar14 >> uVar9 * 8 | uVar14 << uVar9 * -8 + 0x20;
      uVar9 = uVar12 + 0x180 & 3;
      uVar14 = *(uint *)(uVar12 + 0x180 & 0xfffffffc);
      bVar2 = bVar3;
      if (((int)(uVar14 >> uVar9 * 8 | uVar14 << uVar9 * -8 + 0x20) < 4) &&
         (uVar9 = uVar12 + 0x7c & 3, uVar14 = *(uint *)(uVar12 + 0x7c & 0xfffffffc),
         ((uVar14 >> uVar9 * 8 | uVar14 << uVar9 * -8 + 0x20) & uRam02101f74) == 0)) {
        bVar2 = false;
      }
      bVar4 = bVar3;
      if ((!bVar2) &&
         (uVar9 = uVar12 + 0x4c & 3, uVar14 = *(uint *)(uVar12 + 0x4c & 0xfffffffc),
         ((uVar14 >> uVar9 * 8 | uVar14 << uVar9 * -8 + 0x20) & uRam02101f78) == 0)) {
        bVar4 = false;
      }
      uVar9 = uVar12 + 0x4c & 3;
      uVar14 = *(uint *)(uVar12 + 0x4c & 0xfffffffc);
      if (bVar4 || ((uVar14 >> uVar9 * 8 | uVar14 << uVar9 * -8 + 0x20) & 0x40) != 0) {
        bVar2 = false;
      }
      else if ((param_2 == 0xffffffff) ||
              (uVar9 = uVar8 * 0x30 + uVar11 + 0x74, uVar14 = uVar9 & 3,
              uVar9 = *(uint *)(uVar9 & 0xfffffffc),
              param_2 != (uVar9 >> uVar14 * 8 | uVar9 << uVar14 * -8 + 0x20))) {
        bVar2 = false;
        uVar9 = iVar7 + 0x30U & 3;
        uVar14 = *(uint *)(iVar7 + 0x30U & 0xfffffffc);
        uVar9 = uVar14 >> uVar9 * 8 | uVar14 << uVar9 * -8 + 0x20;
        if ((uVar9 != 0x13) &&
           ((uVar14 = iVar7 + 0x50U & 3, uVar12 = *(uint *)(iVar7 + 0x50U & 0xfffffffc),
            uVar12 >> uVar14 * 8 == 0 && uVar12 << uVar14 * -8 + 0x20 == 0 && (uVar9 != 0x10)))) {
          bVar2 = bVar3;
        }
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        *(uint *)(param_1 + 0x140) = uVar8;
        return;
      }
    }
    uVar17 = uVar17 + 1;
    pbVar10 = pbVar10 + 1;
    if ((int)uVar6 <= (int)uVar17) {
      return;
    }
  } while( true );
}

