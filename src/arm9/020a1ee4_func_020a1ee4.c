/* Decompiled C draft; module arm9; ROM address 020a1ee4. No matching claim. */
#include "types.h"
#include "deps/020a1ee4_func_020a1ee4.h"

undefined4 func_020a1ee4(int param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  code *pcVar12;
  undefined4 uVar13;
  int iVar14;
  
  uVar10 = (*(uint *)(uRam020a21b8 & 0xfffffffc) >> (uRam020a21b8 & 3) * 8 |
           *(uint *)(uRam020a21b8 & 0xfffffffc) << (uRam020a21b8 & 3) * -8 + 0x20) + 0x3b4;
  uVar8 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  if (-1 < (int)(uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20)) {
    return 0;
  }
  iVar5 = GetDriverEntry(param_1);
  iVar6 = GetDriverEntry(param_2);
  uVar11 = *(uint *)(uRam020a21b8 & 0xfffffffc) >> (uRam020a21b8 & 3) * 8 |
           *(uint *)(uRam020a21b8 & 0xfffffffc) << (uRam020a21b8 & 3) * -8 + 0x20;
  iVar7 = param_2 * 0x70 + uVar11;
  uVar10 = iVar7 + param_1 * 4 + 0x24;
  uVar8 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  iVar14 = param_1 * 0x70 + uVar11;
  bVar3 = false;
  if ((uVar10 >> uVar8 * 8 == 0 && uVar10 << uVar8 * -8 + 0x20 == 0) &&
     (uVar10 = iVar5 + 0x48U & 3, uVar8 = *(uint *)(iVar5 + 0x48U & 0xfffffffc),
     ((uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) & 0x100000) != 0)) {
    bVar3 = true;
  }
  uVar10 = iVar14 + param_2 * 4 + 0x24;
  uVar8 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  bVar2 = false;
  if ((uVar10 >> uVar8 * 8 == 0 && uVar10 << uVar8 * -8 + 0x20 == 0) &&
     (uVar10 = iVar6 + 0x48U & 3, uVar8 = *(uint *)(iVar6 + 0x48U & 0xfffffffc),
     ((uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) & 0x100000) != 0)) {
    bVar2 = true;
  }
  uVar10 = iVar5 + 0x4cU & 3;
  uVar8 = *(uint *)(iVar5 + 0x4cU & 0xfffffffc);
  bVar1 = true;
  if ((((uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) & 0x400000) == 0) &&
     (iVar9 = GetDriverCollisionMode(param_1), iVar9 != 1)) {
    bVar1 = false;
  }
  uVar10 = iVar6 + 0x4cU & 3;
  uVar8 = *(uint *)(iVar6 + 0x4cU & 0xfffffffc);
  bVar4 = true;
  if ((((uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) & 0x400000) == 0) &&
     (iVar9 = GetDriverCollisionMode(param_2), iVar9 != 1)) {
    bVar4 = false;
  }
  if (bVar2) {
    *(undefined4 *)(iVar14 + param_2 * 4 + 0x24) = 1;
  }
  if (bVar3) {
    *(undefined4 *)(iVar7 + param_1 * 4 + 0x24) = 1;
  }
  if ((((bVar1) || (bVar4)) || (!bVar3)) || (!bVar2)) {
    if ((!bVar1) && (bVar2)) {
      uVar13 = 0;
      iVar6 = GetDriverCollisionMode(param_2);
      uVar10 = uRam020a21b8;
      if (iVar6 == 1) {
        *(undefined4 *)(iVar14 + 0x20) = 1;
        uVar8 = uVar10 & 3;
        uVar10 = *(uint *)(uVar10 & 0xfffffffc);
        uVar10 = (uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) + 0x380;
        uVar8 = uVar10 & 3;
        uVar10 = *(uint *)(uVar10 & 0xfffffffc);
        pcVar12 = (code *)(uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20);
        if ((pcVar12 != (code *)0x0) &&
           (uVar13 = (*pcVar12)(param_1,param_2), uVar10 = iVar5 + 0x4cU & 3,
           uVar8 = *(uint *)(iVar5 + 0x4cU & 0xfffffffc),
           ((uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) & 0x400000) == 0)) {
          StructMQRacerEntry_SomeFn_30(iVar5);
        }
      }
      else {
        uVar10 = (*(uint *)(uRam020a21b8 & 0xfffffffc) >> (uRam020a21b8 & 3) * 8 |
                 *(uint *)(uRam020a21b8 & 0xfffffffc) << (uRam020a21b8 & 3) * -8 + 0x20) + 0x380;
        uVar8 = uVar10 & 3;
        uVar10 = *(uint *)(uVar10 & 0xfffffffc);
        pcVar12 = (code *)(uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20);
        if ((pcVar12 != (code *)0x0) &&
           (uVar13 = (*pcVar12)(param_1,param_2), uVar10 = iVar5 + 0x4cU & 3,
           uVar8 = *(uint *)(iVar5 + 0x4cU & 0xfffffffc),
           ((uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) & 0x400000) == 0)) {
          StructMQRacerEntry_SomeFn_30(iVar5);
        }
      }
      return uVar13;
    }
    if ((!bVar4) && (bVar3)) {
      uVar13 = 0;
      iVar5 = GetDriverCollisionMode(param_1);
      uVar10 = uRam020a21b8;
      if (iVar5 == 1) {
        *(undefined4 *)(iVar7 + 0x20) = 1;
        uVar8 = uVar10 & 3;
        uVar10 = *(uint *)(uVar10 & 0xfffffffc);
        uVar10 = (uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) + 0x380;
        uVar8 = uVar10 & 3;
        uVar10 = *(uint *)(uVar10 & 0xfffffffc);
        pcVar12 = (code *)(uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20);
        if ((pcVar12 != (code *)0x0) &&
           (uVar13 = (*pcVar12)(param_2,param_1), uVar10 = iVar6 + 0x4cU & 3,
           uVar8 = *(uint *)(iVar6 + 0x4cU & 0xfffffffc),
           ((uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) & 0x400000) == 0)) {
          StructMQRacerEntry_SomeFn_30(iVar6);
        }
      }
      else {
        uVar10 = (*(uint *)(uRam020a21b8 & 0xfffffffc) >> (uRam020a21b8 & 3) * 8 |
                 *(uint *)(uRam020a21b8 & 0xfffffffc) << (uRam020a21b8 & 3) * -8 + 0x20) + 0x380;
        uVar8 = uVar10 & 3;
        uVar10 = *(uint *)(uVar10 & 0xfffffffc);
        pcVar12 = (code *)(uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20);
        if ((pcVar12 != (code *)0x0) &&
           (uVar13 = (*pcVar12)(param_2,param_1), uVar10 = iVar6 + 0x4cU & 3,
           uVar8 = *(uint *)(iVar6 + 0x4cU & 0xfffffffc),
           ((uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) & 0x400000) == 0)) {
          StructMQRacerEntry_SomeFn_30(iVar6);
        }
      }
      return uVar13;
    }
  }
  else {
    uVar10 = (*(uint *)(uRam020a21b8 & 0xfffffffc) >> (uRam020a21b8 & 3) * 8 |
             *(uint *)(uRam020a21b8 & 0xfffffffc) << (uRam020a21b8 & 3) * -8 + 0x20) + 900;
    uVar8 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    pcVar12 = (code *)(uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20);
    if (pcVar12 != (code *)0x0) {
      (*pcVar12)(param_1,param_2);
      return 1;
    }
  }
  return 0;
}

