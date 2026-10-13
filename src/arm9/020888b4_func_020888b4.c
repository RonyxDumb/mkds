/* Decompiled C draft; module arm9; ROM address 020888b4. No matching claim. */
#include "types.h"
#include "deps/020888b4_func_020888b4.h"

bool func_020888b4(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int local_30;
  
  uVar4 = func_02100138(0x6a);
  iVar5 = func_021000c8();
  iVar17 = 0;
  uVar16 = 0;
  iVar20 = 0;
  iVar19 = 0;
  iVar18 = (int)*(short *)(param_1 + 0xd4);
  if (0 < iVar5) {
    local_30 = 0;
    do {
      iVar6 = func_0210008c(uVar4);
      uVar15 = iVar6 + iVar18 * 4;
      uVar1 = uVar15 & 3;
      uVar15 = *(uint *)(uVar15 & 0xfffffffc);
      uVar15 = uVar15 >> uVar1 * 8 | uVar15 << uVar1 * -8 + 0x20;
      iVar18 = (iVar18 + 1) * 0x10000 >> 0x10;
      if (iVar5 <= iVar18) {
        iVar18 = local_30;
      }
      if ((*(ushort *)(uVar15 + 2) & 1) == 0) {
        iVar19 = (iVar19 + 1) * 0x10000 >> 0x10;
        uVar1 = uVar15 + 0xc & 3;
        uVar10 = *(uint *)(uVar15 + 0xc & 0xfffffffc);
        uVar2 = uVar15 + 4 & 3;
        uVar13 = *(uint *)(uVar15 + 4 & 0xfffffffc);
        uVar7 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
        uVar8 = uVar7 + 0x88 & 3;
        uVar12 = *(uint *)(uVar7 + 0x88 & 0xfffffffc);
        uVar11 = uVar7 + 0x80 & 3;
        uVar14 = *(uint *)(uVar7 + 0x80 & 0xfffffffc);
        iVar6 = (int)((uVar14 >> uVar11 * 8 | uVar14 << uVar11 * -8 + 0x20) -
                     (uVar13 >> uVar2 * 8 | uVar13 << uVar2 * -8 + 0x20)) >> 0xc;
        iVar9 = (int)((uVar12 >> uVar8 * 8 | uVar12 << uVar8 * -8 + 0x20) -
                     (uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20)) >> 0xc;
        iVar6 = iVar6 * iVar6 + iVar9 * iVar9;
        if ((param_2 <= iVar6) ||
           (uVar1 = uVar7 + 0x84 & 3, uVar11 = *(uint *)(uVar7 + 0x84 & 0xfffffffc),
           uVar2 = uVar15 + 8 & 3, uVar8 = *(uint *)(uVar15 + 8 & 0xfffffffc),
           iVar9 = AbsValue((uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20) -
                            (uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20)), bVar3 = true,
           param_3 <= iVar9)) {
          bVar3 = false;
        }
        if ((bVar3) && ((uVar16 == 0 || (iVar17 < iVar6)))) {
          uVar16 = uVar15;
          iVar17 = iVar6;
        }
        if (4 < iVar19) break;
      }
      iVar20 = (iVar20 + 1) * 0x10000 >> 0x10;
    } while (iVar20 < iVar5);
  }
  *(short *)(param_1 + 0xd4) = (short)iVar18;
  if (uVar16 != 0) {
    *(uint *)(param_1 + 0xd0) = uVar16;
  }
  return uVar16 != 0;
}

