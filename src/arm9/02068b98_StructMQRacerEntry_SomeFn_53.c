/* Decompiled C draft; module arm9; ROM address 02068b98. No matching claim. */
#include "types.h"
#include "deps/02068b98_StructMQRacerEntry_SomeFn_53.h"

void StructMQRacerEntry_SomeFn_53(int param_1)

{
  short sVar1;
  longlong lVar2;
  bool bVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined2 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  uint uVar13;
  uint *puVar14;
  int iVar15;
  uint uVar9;
  
  iVar7 = iRam02068ea4;
  uVar9 = param_1 + 0x7cU & 3;
  uVar8 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  uVar9 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
  if ((uVar9 & 0x40) != 0) {
    if ((uVar9 & 0x40000) == 0) {
      return;
    }
    if ((uVar9 & 0x800000) != 0) {
      return;
    }
  }
  if ((*(short *)(param_1 + 0x3c8) < 0x19) && ((uVar9 & 4) == 0)) {
    iVar15 = 0x18 - *(short *)(param_1 + 0x3c8);
    uVar9 = iRam02068ea0 + iVar15 * 4;
    uVar8 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    *(uint *)(param_1 + 0x41c) = uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20;
    iVar5 = iRam02068ea8;
    uVar9 = iVar7 + iVar15 * 4;
    uVar8 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    *(uint *)(param_1 + 0x420) = uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20;
    uVar9 = iVar5 + iVar15 * 4;
    uVar8 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    *(uint *)(param_1 + 0x424) = uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20;
    uVar9 = param_1 + 0x428U & 3;
    uVar13 = *(uint *)(param_1 + 0x428U & 0xfffffffc);
    uVar8 = param_1 + 0x41cU & 3;
    uVar10 = *(uint *)(param_1 + 0x41cU & 0xfffffffc);
    lVar2 = (longlong)(int)(uVar13 >> uVar9 * 8 | uVar13 << uVar9 * -8 + 0x20) *
            (longlong)(int)(uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20);
    *(uint *)(param_1 + 0xbc) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
    uVar9 = param_1 + 0x42cU & 3;
    uVar13 = *(uint *)(param_1 + 0x42cU & 0xfffffffc);
    uVar8 = param_1 + 0x420U & 3;
    uVar10 = *(uint *)(param_1 + 0x420U & 0xfffffffc);
    lVar2 = (longlong)(int)(uVar13 >> uVar9 * 8 | uVar13 << uVar9 * -8 + 0x20) *
            (longlong)(int)(uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20);
    *(uint *)(param_1 + 0xc0) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
    uVar9 = param_1 + 0x430U & 3;
    uVar13 = *(uint *)(param_1 + 0x430U & 0xfffffffc);
    uVar8 = param_1 + 0x424U & 3;
    uVar10 = *(uint *)(param_1 + 0x424U & 0xfffffffc);
    lVar2 = (longlong)(int)(uVar13 >> uVar9 * 8 | uVar13 << uVar9 * -8 + 0x20) *
            (longlong)(int)(uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20);
    *(uint *)(param_1 + 0xc4) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
    uVar9 = param_1 + 0x434U & 3;
    uVar13 = *(uint *)(param_1 + 0x434U & 0xfffffffc);
    uVar8 = param_1 + 0xc0U & 3;
    uVar10 = *(uint *)(param_1 + 0xc0U & 0xfffffffc);
    lVar2 = (longlong)(int)(uVar13 >> uVar9 * 8 | uVar13 << uVar9 * -8 + 0x20) *
            (longlong)(int)(uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20);
    *(uint *)(param_1 + 0xc0) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
    *(short *)(param_1 + 0x3c8) = *(short *)(param_1 + 0x3c8) + 1;
    return;
  }
  bVar3 = false;
  uVar9 = (*(uint *)(uRam02068e90 & 0xfffffffc) >> (uRam02068e90 & 3) * 8 |
          *(uint *)(uRam02068e90 & 0xfffffffc) << (uRam02068e90 & 3) * -8 + 0x20) + 8;
  uVar8 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  if (((uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) == 2) &&
     (iVar7 = func_020a128c(), iVar7 != 0)) {
    bVar3 = true;
  }
  uVar8 = uRam02068e94;
  uVar9 = param_1 + 0x7cU & 3;
  uVar10 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  *(uint *)(param_1 + 0x7c) = uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20 | 0x40;
  uVar9 = param_1 + 0x7cU & 3;
  uVar10 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  uVar9 = uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20;
  puVar14 = (uint *)(param_1 + 0x7c);
  if ((((uVar9 & uVar8) == 0) && (!bVar3)) && ((uVar9 & 0x40000) != 0)) {
    sVar1 = *(short *)(param_1 + 0x3c8);
    if (sVar1 < 0xb9) {
      if ((uVar9 & 1) != 0) {
        if (sVar1 == 0x70) {
          func_02055a94();
        }
        else if (sVar1 == 0x73) {
          func_02055c18(0x3c);
          func_0210fb54();
        }
      }
      *(short *)(param_1 + 0x3c8) = *(short *)(param_1 + 0x3c8) + 1;
      return;
    }
    *puVar14 = *(uint *)((uint)puVar14 & 0xfffffffc) >> ((uint)puVar14 & 3) * 8 |
               *(uint *)((uint)puVar14 & 0xfffffffc) << ((uint)puVar14 & 3) * -8 + 0x20 | 0x80000;
    func_02063ad0(param_1);
    uVar9 = (*(uint *)(uRam02068e90 & 0xfffffffc) >> (uRam02068e90 & 3) * 8 |
            *(uint *)(uRam02068e90 & 0xfffffffc) << (uRam02068e90 & 3) * -8 + 0x20) + 8;
    uVar8 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    if ((uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) == 5) {
      iVar7 = param_1 + 0x1d8;
    }
    else {
      iVar7 = param_1 + 0x1b8;
    }
    if (*(short *)(param_1 + 0x2c8) == -1) {
      uVar9 = param_1 + 0x2ccU & 3;
      uVar8 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
      uVar8 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
      uVar9 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      uVar6 = FindComputeSomeCollisionEntryId
                        (iVar7,(uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) + 0xd000,0x8000,
                         param_1);
      *(undefined2 *)(param_1 + 0x2c8) = uVar6;
    }
    if (*(short *)(param_1 + 0x2ca) == -1) {
      uVar9 = param_1 + 0x2ccU & 3;
      uVar8 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
      uVar8 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
      uVar9 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      uVar9 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
      uVar6 = FindComputeSomeCollisionEntryId
                        (param_1 + 0x1f0,(uVar9 << 0xf) >> 0xc | (uVar9 >> 0x11) << 0x14,0x800,
                         param_1);
      *(undefined2 *)(param_1 + 0x2ca) = uVar6;
    }
    uVar9 = param_1 + 0x7cU & 3;
    uVar8 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    puVar14 = (uint *)(param_1 + 0x7c);
    *(uint *)(param_1 + 0x7c) = (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) & uRam02068e98;
    uVar9 = param_1 + 0x7cU & 3;
    uVar8 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    *(uint *)(param_1 + 0x7c) = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20 | 0x400000;
    uVar9 = param_1 + 0x7cU & 3;
    uVar8 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) & 1) == 0) {
      *puVar14 = *(uint *)((uint)puVar14 & 0xfffffffc) >> ((uint)puVar14 & 3) * 8 |
                 *(uint *)((uint)puVar14 & 0xfffffffc) << ((uint)puVar14 & 3) * -8 + 0x20 |
                 0x1000000;
    }
    uVar9 = param_1 + 0x7cU & 3;
    uVar8 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) & 1) == 0) {
      uVar9 = param_1 + 0x7cU & 3;
      uVar8 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
      *(uint *)(param_1 + 0x7c) = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20 | 0x8000;
    }
    else {
      uVar9 = param_1 + 0x7cU & 3;
      uVar8 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
      *(uint *)(param_1 + 0x7c) = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20 | 0x4000;
    }
    func_02104f84(*(undefined2 *)(param_1 + 0x74));
    uVar9 = param_1 + 0x7cU & 3;
    uVar8 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) & 1) != 0) {
      func_0210fb10();
    }
    DriverContext_UpdateSfxStartFn(param_1);
    return;
  }
  *(undefined4 *)(param_1 + 0x80) = 0x1000000;
  *(undefined4 *)(param_1 + 0x84) = 0xff000000;
  puVar4 = puRam02068e9c;
  *(undefined4 *)(param_1 + 0x88) = 0x1000000;
  uVar11 = puVar4[1];
  uVar12 = puVar4[2];
  *(undefined4 *)(param_1 + 0xbc) = *puVar4;
  *(undefined4 *)(param_1 + 0xc0) = uVar11;
  *(undefined4 *)(param_1 + 0xc4) = uVar12;
  return;
}

