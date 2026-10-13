/* Decompiled C draft; module arm9; ROM address 021031f4. No matching claim. */
#include "types.h"
#include "deps/021031f4_func_021031f4.h"

void func_021031f4(int param_1)

{
  byte bVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar17;
  uint uVar18;
  uint uVar16;
  
  if ((*(ushort *)(param_1 + 0x78) & 0x8000) == 0) {
    uVar3 = *(ushort *)(param_1 + 0x78) & 0xffff00ff;
  }
  else {
    uVar3 = 8;
  }
  uVar10 = *(uint *)(uRam021033f8 & 0xfffffffc) >> (uRam021033f8 & 3) * 8 |
           *(uint *)(uRam021033f8 & 0xfffffffc) << (uRam021033f8 & 3) * -8 + 0x20;
  iVar4 = (int)*(char *)(uVar10 + 0x62);
  uVar13 = uVar10 + 8 & 3;
  uVar8 = *(uint *)(uVar10 + 8 & 0xfffffffc);
  if ((uVar8 >> uVar13 * 8 | uVar8 << uVar13 * -8 + 0x20) == 2) {
    bVar1 = *(byte *)(uVar10 + 0x3d0);
    uVar13 = 0;
    if (bVar1 != 0) {
      do {
        if (((uVar13 != uVar3) &&
            (iVar5 = GetDriverEntry(uVar13), uVar8 = iVar5 + 0x7cU & 3,
            uVar10 = *(uint *)(iVar5 + 0x7cU & 0xfffffffc),
            ((uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) & uRam021033fc) == 0)) &&
           ((uVar8 = iVar5 + 0x4cU & 3, uVar10 = *(uint *)(iVar5 + 0x4cU & 0xfffffffc),
            ((uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) & uRam02103400) == 0 &&
            (uVar8 = iVar5 + 0x48U & 3, uVar10 = *(uint *)(iVar5 + 0x48U & 0xfffffffc),
            ((uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) & 0x10000) == 0)))) {
          uVar17 = *(uint *)(uRam02103404 & 0xfffffffc) >> (uRam02103404 & 3) * 8 |
                   *(uint *)(uRam02103404 & 0xfffffffc) << (uRam02103404 & 3) * -8 + 0x20;
          uVar8 = uVar17 + 0x498 & 3;
          uVar10 = *(uint *)(uVar17 + 0x498 & 0xfffffffc);
          uVar11 = uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20;
          iVar5 = uVar17 + iRam02103408;
          uVar8 = iVar5 + 8U & 3;
          uVar10 = *(uint *)(iVar5 + 8U & 0xfffffffc);
          uVar18 = uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20;
          uVar8 = iVar5 + 4U & 3;
          uVar9 = *(uint *)(iVar5 + 4U & 0xfffffffc);
          lVar2 = (ulonglong)uVar11 * (ulonglong)uVar18;
          uVar14 = (uint)lVar2;
          uVar10 = iVar5 + 0xcU & 3;
          uVar12 = *(uint *)(iVar5 + 0xcU & 0xfffffffc);
          uVar6 = iVar5 + 0x10U & 3;
          uVar15 = *(uint *)(iVar5 + 0x10U & 0xfffffffc);
          uVar16 = uVar15 >> uVar6 * 8 | uVar15 << uVar6 * -8 + 0x20;
          uVar6 = iVar5 + 0x14U & 3;
          uVar15 = *(uint *)(iVar5 + 0x14U & 0xfffffffc);
          *(uint *)(uVar17 + 0x498) = uVar16 + uVar14;
          *(uint *)(iVar5 + 4) =
               (uVar15 >> uVar6 * 8 | uVar15 << uVar6 * -8 + 0x20) +
               (uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20) * uVar11 +
               uVar18 * (uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) +
               (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar16,uVar14);
          uVar8 = iVar5 + 4U & 3;
          uVar10 = *(uint *)(iVar5 + 4U & 0xfffffffc);
          *(byte *)(param_1 + uVar13 + 0x130) =
               ((byte)((byte)((uVar10 >> uVar8 * 8) >> 0x18) |
                      (byte)((uVar10 << uVar8 * -8 + 0x20) >> 0x18)) >> 6) + 1;
        }
        uVar13 = uVar13 + 1;
      } while ((int)uVar13 < (int)(uint)bVar1);
    }
  }
  else {
    uVar13 = 1;
    uVar6 = GetDriverPlace(uVar3);
    uVar10 = uRam02103404;
    uVar8 = uRam02103400;
    uVar3 = uRam021033fc;
    do {
      uVar9 = uVar10 & 3;
      uVar11 = *(uint *)(uVar10 & 0xfffffffc);
      uVar9 = (int)*(char *)((uVar11 >> uVar9 * 8 | uVar11 << uVar9 * -8 + 0x20) + (uVar13 & 0xff) +
                            0x473) & 0xffff;
      iVar5 = GetDriverEntry(uVar9);
      uVar11 = iVar5 + 0x7cU & 3;
      uVar12 = *(uint *)(iVar5 + 0x7cU & 0xfffffffc);
      if (((((uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20) & uVar3) == 0) &&
          (uVar11 = iVar5 + 0x4cU & 3, uVar12 = *(uint *)(iVar5 + 0x4cU & 0xfffffffc),
          ((uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20) & uVar8) == 0)) &&
         (uVar11 = iVar5 + 0x48U & 3, uVar12 = *(uint *)(iVar5 + 0x48U & 0xfffffffc),
         ((uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20) & 0x10000) == 0)) {
        *(char *)(param_1 + uVar9 + 0x130) = '\x04' - (char)((int)(uVar13 - 1) >> 1);
      }
      uVar13 = uVar13 + 1 & 0xffff;
    } while (uVar13 < uVar6);
  }
  if ((-1 < iVar4) && (*(char *)(param_1 + iVar4 + 0x130) != '\0')) {
    *(undefined4 *)(param_1 + 0x198) = 1;
    uVar7 = GetDriverEntry(iVar4);
    *(undefined4 *)(param_1 + 300) = uVar7;
    uVar3 = param_1 + 300U & 3;
    uVar13 = *(uint *)(param_1 + 300U & 0xfffffffc);
    func_020f8e3c(uVar13 >> uVar3 * 8 | uVar13 << uVar3 * -8 + 0x20,0xf3);
    return;
  }
  *(undefined4 *)(param_1 + 0x198) = 0;
  return;
}

