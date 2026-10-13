/* Decompiled C draft; module arm9; ROM address 020bdb34. No matching claim. */
#include "types.h"
#include "deps/020bdb34_func_020bdb34.h"

void func_020bdb34(int param_1)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  short sVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar14;
  int unaff_r9;
  int iStack_74;
  int iStack_6c;
  int iStack_5c;
  uint uVar13;
  
  uVar5 = uRam020bdf04;
  uVar4 = uRam020bdf00;
  uVar14 = 0;
  if (*(char *)((*(uint *)(uRam020bdf00 & 0xfffffffc) >> (uRam020bdf00 & 3) * 8 |
                *(uint *)(uRam020bdf00 & 0xfffffffc) << (uRam020bdf00 & 3) * -8 + 0x20) + 0x3d0) ==
      '\0') {
    return;
  }
  iStack_6c = 0x6d;
  iStack_74 = 0;
  iStack_5c = 3;
  do {
    uVar9 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
            *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
    uVar12 = uVar9 + uVar14 * 4 + 0xa0;
    uVar1 = uVar12 & 3;
    uVar12 = *(uint *)(uVar12 & 0xfffffffc);
    uVar13 = uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20;
    uVar12 = uVar9 + uVar13 * 8 + 4;
    uVar1 = uVar12 & 3;
    uVar12 = *(uint *)(uVar12 & 0xfffffffc);
    iVar7 = func_020be15c(uVar13 & 0xffff);
    if (iVar7 != 0xc9) {
      uVar8 = GetB3C4_Cell_RaceS();
      sVar6 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                               0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar8);
      *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar6;
    }
    uVar10 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
             *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
    iVar7 = uVar10 + uVar13 * 4;
    uVar9 = iVar7 + 0x80;
    uVar2 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    uVar11 = uVar9 >> uVar2 * 8 | uVar9 << uVar2 * -8 + 0x20;
    uVar9 = iVar7 + 0x60;
    uVar2 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    uVar9 = uVar9 >> uVar2 * 8 | uVar9 << uVar2 * -8 + 0x20;
    if ((int)uVar11 < (int)uVar9) {
      unaff_r9 = uVar10 + 0xe8;
    }
    iVar7 = unaff_r9;
    if ((int)uVar9 <= (int)uVar11) {
      iVar7 = iStack_74;
    }
    uVar8 = GetB3C4_Cell_RaceS(uVar13 + 8);
    unaff_r9 = (uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20) << 0xc;
    sVar6 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar8,iVar7);
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar6;
    uVar12 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
             *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 8;
    uVar1 = uVar12 & 3;
    uVar12 = *(uint *)(uVar12 & 0xfffffffc);
    if (((uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20) == 2) &&
       (iVar7 = func_020a1084(uVar13 & 0xffff), iVar7 != 0)) {
      bVar3 = true;
    }
    else {
      uVar12 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
               *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 8;
      uVar1 = uVar12 & 3;
      uVar12 = *(uint *)(uVar12 & 0xfffffffc);
      bVar3 = false;
      if (((uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20) != 2) &&
         ((iVar7 = func_020b1cf4(uVar13 & 0xffff), iVar7 != 0 ||
          (iVar7 = IsDriverKilledOrBeingKilled(uVar13 & 0xffff), bVar3 = false, iVar7 != 0)))) {
        bVar3 = true;
      }
    }
    iVar7 = iStack_6c;
    if (!bVar3) {
      iVar7 = 0x65;
    }
    uVar8 = GetB3C4_Cell_RaceS(iVar7 + uVar13);
    sVar6 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar8);
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar6;
    uVar12 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
             *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 8;
    uVar1 = uVar12 & 3;
    uVar12 = *(uint *)(uVar12 & 0xfffffffc);
    if (((uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20) == 2) &&
       (iVar7 = func_020a1084(uVar13 & 0xffff), iVar7 != 0)) {
      bVar3 = true;
    }
    else {
      uVar12 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
               *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 8;
      uVar1 = uVar12 & 3;
      uVar12 = *(uint *)(uVar12 & 0xfffffffc);
      bVar3 = false;
      if (((uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20) != 2) &&
         ((iVar7 = func_020b1cf4(uVar13 & 0xffff), iVar7 != 0 ||
          (iVar7 = IsDriverKilledOrBeingKilled(uVar13 & 0xffff), bVar3 = false, iVar7 != 0)))) {
        bVar3 = true;
      }
    }
    iVar7 = iStack_5c;
    if (!bVar3) {
      uVar12 = GetCurrentPlayerRacerId();
      if ((uVar13 & 0xffff) == uVar12) {
        iVar7 = 0;
      }
      else {
        uVar12 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                 *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
        if ((*(char *)(uVar12 + 0x58) == '\0') ||
           (uVar12 = (uVar13 & 0xffff) * 0x30 + uVar12 + 0x74, uVar1 = uVar12 & 3,
           uVar12 = *(uint *)(uVar12 & 0xfffffffc),
           (uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20) != 1)) {
          iVar7 = 1;
        }
        else {
          iVar7 = 2;
        }
      }
    }
    uVar8 = GetB3C4_Cell_RaceS(iVar7 + 0x79);
    sVar6 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar8);
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar6;
    uVar14 = uVar14 + 1 & 0xffff;
  } while (uVar14 < *(byte *)((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                              *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x3d0));
  return;
}

