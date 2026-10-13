/* Decompiled C draft; module arm9; ROM address 020bd178. No matching claim. */
#include "types.h"
#include "deps/020bd178_func_020bd178.h"

void func_020bd178(int param_1)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  bool bVar4;
  uint uVar5;
  short sVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iStack_bc;
  int iStack_b4;
  int iStack_88;
  
  uVar5 = uRam020bd7e8;
  uVar13 = 0;
  if (*(char *)((*(uint *)(uRam020bd7e8 & 0xfffffffc) >> (uRam020bd7e8 & 3) * 8 |
                *(uint *)(uRam020bd7e8 & 0xfffffffc) << (uRam020bd7e8 & 3) * -8 + 0x20) + 0x3d0) ==
      '\0') {
    return;
  }
  iStack_b4 = 0x6d;
  iStack_bc = 0;
  iStack_88 = 3;
  do {
    uVar12 = (*(uint *)(uRam020bd7ec & 0xfffffffc) >> (uRam020bd7ec & 3) * 8 |
             *(uint *)(uRam020bd7ec & 0xfffffffc) << (uRam020bd7ec & 3) * -8 + 0x20) + uVar13 * 4 +
             0xa0;
    uVar9 = uVar12 & 3;
    uVar12 = *(uint *)(uVar12 & 0xfffffffc);
    uVar12 = uVar12 >> uVar9 * 8 | uVar12 << uVar9 * -8 + 0x20;
    iVar7 = func_020be15c(uVar12 & 0xffff);
    if (iVar7 != 0xc9) {
      uVar8 = GetB3C4_Cell_RaceS();
      sVar6 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                               0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar8);
      *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar6;
    }
    uVar10 = *(uint *)(uRam020bd7ec & 0xfffffffc) >> (uRam020bd7ec & 3) * 8 |
             *(uint *)(uRam020bd7ec & 0xfffffffc) << (uRam020bd7ec & 3) * -8 + 0x20;
    iVar7 = uVar10 + uVar12 * 4;
    uVar9 = iVar7 + 0x80;
    uVar1 = uVar9 & 3;
    uVar11 = *(uint *)(uVar9 & 0xfffffffc);
    uVar9 = iVar7 + 0x60;
    uVar2 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    iVar7 = iStack_bc;
    if ((int)(uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20) <
        (int)(uVar9 >> uVar2 * 8 | uVar9 << uVar2 * -8 + 0x20)) {
      iVar7 = uVar10 + 0xe8;
    }
    uVar8 = GetB3C4_Cell_RaceS(uVar12 + 8);
    sVar6 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar8,iVar7);
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar6;
    uVar9 = (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
            *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 8;
    uVar1 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    if (((uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20) == 2) &&
       (iVar7 = func_020a1084(uVar12 & 0xffff), iVar7 != 0)) {
      bVar4 = true;
    }
    else {
      uVar9 = (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
              *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 8;
      uVar1 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      bVar4 = false;
      if (((uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20) != 2) &&
         ((iVar7 = func_020b1cf4(uVar12 & 0xffff), iVar7 != 0 ||
          (iVar7 = IsDriverKilledOrBeingKilled(uVar12 & 0xffff), bVar4 = false, iVar7 != 0)))) {
        bVar4 = true;
      }
    }
    iVar7 = iStack_b4;
    if (!bVar4) {
      iVar7 = 0x65;
    }
    uVar8 = GetB3C4_Cell_RaceS(iVar7 + uVar12);
    sVar6 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar8);
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar6;
    uVar9 = (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
            *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x18;
    uVar1 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    if (uVar9 >> uVar1 * 8 == 0 && uVar9 << uVar1 * -8 + 0x20 == 0) {
      uVar9 = (*(uint *)(uRam020bd7ec & 0xfffffffc) >> (uRam020bd7ec & 3) * 8 |
              *(uint *)(uRam020bd7ec & 0xfffffffc) << (uRam020bd7ec & 3) * -8 + 0x20) + uVar12 * 4 +
              0xc0;
      uVar1 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      uVar8 = GetB3C4_Cell_RaceS(0xc3);
      sVar6 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                               0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar8);
      *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar6;
      uVar8 = GetB3C4_Cell_RaceS((uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20) + 0xb9);
      sVar6 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                               0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar8);
      *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar6;
    }
    else {
      uVar9 = (*(uint *)(uRam020bd7ec & 0xfffffffc) >> (uRam020bd7ec & 3) * 8 |
              *(uint *)(uRam020bd7ec & 0xfffffffc) << (uRam020bd7ec & 3) * -8 + 0x20) + uVar12 * 4 +
              0xc0;
      uVar1 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      uVar9 = uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20;
      uVar8 = GetB3C4_Cell_RaceS(0xc4);
      sVar6 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                               0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar8);
      lVar3 = (longlong)iRam020bd7f0;
      *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar6;
      uVar8 = GetB3C4_Cell_RaceS(((int)(lVar3 * (int)uVar9 >> 0x22) - ((int)uVar9 >> 0x1f)) + 0xb9);
      sVar6 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                               0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar8);
      lVar3 = (longlong)iRam020bd7f0;
      *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar6;
      lVar3 = (longlong)iRam020bd7f4 *
              (longlong)((int)(lVar3 * (int)uVar9 >> 0x22) - ((int)uVar9 >> 0x1f));
      iVar7 = (int)lVar3;
      uVar8 = GetB3C4_Cell_RaceS((uVar9 - iVar7) + 0xb9,iVar7,(int)((ulonglong)lVar3 >> 0x20));
      sVar6 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                               0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar8);
      *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar6;
    }
    uVar9 = (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
            *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 8;
    uVar1 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    if (((uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20) == 2) &&
       (iVar7 = func_020a1084(uVar12 & 0xffff), iVar7 != 0)) {
      bVar4 = true;
    }
    else {
      uVar9 = (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
              *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 8;
      uVar1 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      bVar4 = false;
      if (((uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20) != 2) &&
         ((iVar7 = func_020b1cf4(uVar12 & 0xffff), iVar7 != 0 ||
          (iVar7 = IsDriverKilledOrBeingKilled(uVar12 & 0xffff), bVar4 = false, iVar7 != 0)))) {
        bVar4 = true;
      }
    }
    iVar7 = iStack_88;
    if (!bVar4) {
      uVar9 = GetCurrentPlayerRacerId();
      if ((uVar12 & 0xffff) == uVar9) {
        iVar7 = 0;
      }
      else {
        uVar9 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
        if ((*(char *)(uVar9 + 0x58) == '\0') ||
           (uVar12 = (uVar12 & 0xffff) * 0x30 + uVar9 + 0x74, uVar9 = uVar12 & 3,
           uVar12 = *(uint *)(uVar12 & 0xfffffffc),
           (uVar12 >> uVar9 * 8 | uVar12 << uVar9 * -8 + 0x20) != 1)) {
          iVar7 = 1;
        }
        else {
          iVar7 = 2;
        }
      }
    }
    uVar8 = GetB3C4_Cell_RaceS(iVar7 + 0x81);
    sVar6 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar8);
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar6;
    uVar13 = uVar13 + 1 & 0xffff;
  } while (uVar13 < *(byte *)((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                              *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x3d0));
  return;
}

