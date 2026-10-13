/* Decompiled C draft; module arm9; ROM address 0207f2e4. No matching claim. */
#include "types.h"
#include "deps/0207f2e4_func_0207f2e4.h"

void func_0207f2e4(int param_1)

{
  uint uVar1;
  ushort uVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  bool bVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  
  *(undefined4 *)(param_1 + 0xb0) = 0;
  *(undefined4 *)(param_1 + 0xb4) = 0;
  uVar2 = *(ushort *)(param_1 + 4);
  uVar4 = func_02061f90();
  if (uVar2 != uVar4) {
    return;
  }
  uVar4 = (*(uint *)(uRam0207f548 & 0xfffffffc) >> (uRam0207f548 & 3) * 8 |
          *(uint *)(uRam0207f548 & 0xfffffffc) << (uRam0207f548 & 3) * -8 + 0x20) + 0x14;
  uVar13 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if ((uVar4 >> uVar13 * 8 | uVar4 << uVar13 * -8 + 0x20) != 3) {
    return;
  }
  uVar4 = GetDriverPlace((uint)uVar2);
  if (uVar4 < 2) {
    return;
  }
  uVar13 = (uint)*(char *)((*(uint *)(uRam0207f54c & 0xfffffffc) >> (uRam0207f54c & 3) * 8 |
                           *(uint *)(uRam0207f54c & 0xfffffffc) << (uRam0207f54c & 3) * -8 + 0x20) +
                           (uVar4 - 1 & 0xff) + 0x473);
  bVar3 = false;
  if (-1 < (int)uVar13) {
    bVar10 = false;
    uVar7 = *(uint *)(uRam0207f548 & 0xfffffffc) >> (uRam0207f548 & 3) * 8 |
            *(uint *)(uRam0207f548 & 0xfffffffc) << (uRam0207f548 & 3) * -8 + 0x20;
    if ((*(char *)(uVar7 + 0x58) == '\0') ||
       (uVar8 = (uVar13 & 0xffff) * 0x30 + uVar7 + 0x74, uVar1 = uVar8 & 3,
       uVar11 = *(uint *)(uVar8 & 0xfffffffc),
       uVar8 = (uint)*(ushort *)(param_1 + 4) * 0x30 + uVar7 + 0x74, uVar12 = uVar8 & 3,
       uVar8 = *(uint *)(uVar8 & 0xfffffffc),
       (uVar8 >> uVar12 * 8 | uVar8 << uVar12 * -8 + 0x20) !=
       (uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20))) {
      uVar7 = (uVar13 & 0xffff) * 0x30 + uVar7 + 0x70;
      uVar8 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      uVar7 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
      bVar9 = false;
      if ((uVar7 < 4) && ((1 << (uVar7 & 0xff) & 0xdU) != 0)) {
        bVar9 = true;
      }
      if (((bVar9) || (iVar5 = func_02085824(), iVar5 < 1)) &&
         (iVar5 = GetDriverEntry(uVar13 & 0xffff), uVar7 = iVar5 + 0x7cU & 3,
         uVar8 = *(uint *)(iVar5 + 0x7cU & 0xfffffffc),
         ((uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) & uRam0207f550) == 0)) {
        bVar10 = true;
      }
    }
    if (bVar10) {
      uVar6 = GetDriverEntry(uVar13);
      *(undefined4 *)(param_1 + 0xb0) = uVar6;
      bVar3 = true;
      *(undefined4 *)(param_1 + 0xb4) = 1;
    }
  }
  if (!bVar3) {
    uVar13 = *(uint *)(uRam0207f548 & 0xfffffffc) >> (uRam0207f548 & 3) * 8 |
             *(uint *)(uRam0207f548 & 0xfffffffc) << (uRam0207f548 & 3) * -8 + 0x20;
    if (*(byte *)(uVar13 + 0x3d0) <= uVar4) {
      return;
    }
    uVar4 = (uint)*(char *)((*(uint *)(uRam0207f54c & 0xfffffffc) >> (uRam0207f54c & 3) * 8 |
                            *(uint *)(uRam0207f54c & 0xfffffffc) << (uRam0207f54c & 3) * -8 + 0x20)
                            + (uVar4 + 1 & 0xff) + 0x473);
    if (-1 < (int)uVar4) {
      bVar3 = false;
      if ((*(char *)(uVar13 + 0x58) == '\0') ||
         (uVar7 = (uVar4 & 0xffff) * 0x30 + uVar13 + 0x74, uVar8 = uVar7 & 3,
         uVar12 = *(uint *)(uVar7 & 0xfffffffc),
         uVar7 = (uint)*(ushort *)(param_1 + 4) * 0x30 + uVar13 + 0x74, uVar1 = uVar7 & 3,
         uVar7 = *(uint *)(uVar7 & 0xfffffffc),
         (uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) !=
         (uVar12 >> uVar8 * 8 | uVar12 << uVar8 * -8 + 0x20))) {
        uVar13 = (uVar4 & 0xffff) * 0x30 + uVar13 + 0x70;
        uVar7 = uVar13 & 3;
        uVar13 = *(uint *)(uVar13 & 0xfffffffc);
        uVar13 = uVar13 >> uVar7 * 8 | uVar13 << uVar7 * -8 + 0x20;
        bVar10 = false;
        if ((uVar13 < 4) && ((1 << (uVar13 & 0xff) & 0xdU) != 0)) {
          bVar10 = true;
        }
        if (((bVar10) || (iVar5 = func_02085824(), iVar5 < 1)) &&
           (iVar5 = GetDriverEntry(uVar4 & 0xffff), uVar13 = iVar5 + 0x7cU & 3,
           uVar7 = *(uint *)(iVar5 + 0x7cU & 0xfffffffc),
           ((uVar7 >> uVar13 * 8 | uVar7 << uVar13 * -8 + 0x20) & uRam0207f550) == 0)) {
          bVar3 = true;
        }
      }
      if (bVar3) {
        uVar6 = GetDriverEntry(uVar4);
        *(undefined4 *)(param_1 + 0xb0) = uVar6;
        return;
      }
      return;
    }
    return;
  }
  return;
}

