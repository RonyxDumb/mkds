/* Decompiled C draft; module arm9; ROM address 0203cd14. No matching claim. */
#include "types.h"
#include "deps/0203cd14_func_0203cd14.h"

void func_0203cd14(void)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  bool bVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  undefined4 uVar13;
  
  uVar2 = uRam0203cfb0;
  uVar8 = uRam0203cfac;
  bVar5 = false;
  uVar10 = *(uint *)(uRam0203cfac & 0xfffffffc) >> (uRam0203cfac & 3) * 8 |
           *(uint *)(uRam0203cfac & 0xfffffffc) << (uRam0203cfac & 3) * -8 + 0x20;
  uVar13 = 2;
  uVar12 = (uint)*(char *)(uVar10 + 0x62);
  if ((int)uVar12 < 0) {
    return;
  }
  iVar11 = (uVar12 & 0xffff) * 0x8c;
  uVar9 = *(uint *)(uRam0203cfb0 & 0xfffffffc) >> (uRam0203cfb0 & 3) * 8 |
          *(uint *)(uRam0203cfb0 & 0xfffffffc) << (uRam0203cfb0 & 3) * -8 + 0x20;
  uVar6 = uVar9 + 0x14 + iVar11;
  uVar1 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar6 = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
  if (((uVar6 == 1) || (uVar6 == 2)) || (bVar4 = bVar5, uVar6 == 3)) {
    bVar4 = true;
  }
  if (!bVar4) {
    if (((*(ushort *)(uVar10 + 0x44) & 2) != 0) && (iVar11 = func_0207a574(), iVar11 != 0)) {
      bVar5 = true;
    }
    if (((!bVar5) &&
        ((*(ushort *)
           ((*(uint *)(uRam0203cfac & 0xfffffffc) >> (uRam0203cfac & 3) * 8 |
            *(uint *)(uRam0203cfac & 0xfffffffc) << (uRam0203cfac & 3) * -8 + 0x20) + 0x44) & 4) !=
         0)) && (iVar11 = IsPlayerTouchingWall(), iVar11 != 0)) {
      uVar13 = 3;
      bVar5 = true;
    }
    if (((!bVar5) &&
        ((*(ushort *)
           ((*(uint *)(uRam0203cfac & 0xfffffffc) >> (uRam0203cfac & 3) * 8 |
            *(uint *)(uRam0203cfac & 0xfffffffc) << (uRam0203cfac & 3) * -8 + 0x20) + 0x44) & 8) !=
         0)) && (iVar11 = HasPlayerFlagBBit12(), iVar11 != 0)) {
      bVar5 = true;
    }
    if ((!bVar5) && (iVar11 = func_0205e1c4(), iVar11 != 0)) {
      uVar13 = 4;
      bVar5 = true;
    }
    if (bVar5) {
      func_0203e788((short)*(char *)((*(uint *)(uRam0203cfac & 0xfffffffc) >> (uRam0203cfac & 3) * 8
                                     | *(uint *)(uRam0203cfac & 0xfffffffc) <<
                                       (uRam0203cfac & 3) * -8 + 0x20) + 0x62),uVar13);
      return;
    }
    return;
  }
  uVar3 = *(ushort *)(uVar9 + 0x14 + iVar11 + 0x30);
  if ((uVar3 & 0x10) != 0) {
    *(short *)(uVar9 + 0x4fa) = *(short *)(uVar9 + 0x4fa) + 1;
    uVar10 = uVar2 & 3;
    uVar6 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    if (*(ushort *)((uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) + 0x38) <
        *(ushort *)((uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) + 0x4fa)) {
      GetDriverEntry(uVar12 & 0xffff);
      StructMQRacerEntry_SomeFn_15();
      StructMQRacerEntry_SomeFn_21_ById(uVar12 & 0xffff);
      func_020b3f64();
      MaybePlayCrowdAmbientNoise(0);
      uVar8 = (*(uint *)(uRam0203cfac & 0xfffffffc) >> (uRam0203cfac & 3) * 8 |
              *(uint *)(uRam0203cfac & 0xfffffffc) << (uRam0203cfac & 3) * -8 + 0x20) + 8;
      uVar2 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      if ((uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) == 4) {
        func_020a0dbc();
      }
      iVar11 = (*(uint *)(uRam0203cfb0 & 0xfffffffc) >> (uRam0203cfb0 & 3) * 8 |
               *(uint *)(uRam0203cfb0 & 0xfffffffc) << (uRam0203cfb0 & 3) * -8 + 0x20) + 0x14 +
               iVar11;
      *(ushort *)(iVar11 + 0x30) = *(ushort *)(iVar11 + 0x30) & 0xffef;
      return;
    }
    return;
  }
  if ((uVar3 & 0x20) != 0) {
    iVar7 = func_0207a218();
    if (iVar7 != 0) {
      uVar8 = *(uint *)(uRam0203cfb0 & 0xfffffffc) >> (uRam0203cfb0 & 3) * 8 |
              *(uint *)(uRam0203cfb0 & 0xfffffffc) << (uRam0203cfb0 & 3) * -8 + 0x20;
      *(short *)(uVar8 + 0x4fc) = *(short *)(uVar8 + 0x4fc) + 1;
    }
    if (0x3c < *(ushort *)
                ((*(uint *)(uRam0203cfb0 & 0xfffffffc) >> (uRam0203cfb0 & 3) * 8 |
                 *(uint *)(uRam0203cfb0 & 0xfffffffc) << (uRam0203cfb0 & 3) * -8 + 0x20) + 0x4fc)) {
      GetDriverEntry(uVar12);
      StructMQRacerEntry_SomeFn_15();
      StructMQRacerEntry_SomeFn_21_ById(uVar12 & 0xffff);
      MaybePlayCrowdAmbientNoise(0);
      uVar8 = (*(uint *)(uRam0203cfac & 0xfffffffc) >> (uRam0203cfac & 3) * 8 |
              *(uint *)(uRam0203cfac & 0xfffffffc) << (uRam0203cfac & 3) * -8 + 0x20) + 8;
      uVar2 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      if ((uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) == 4) {
        func_020a0dbc();
      }
      iVar11 = (*(uint *)(uRam0203cfb0 & 0xfffffffc) >> (uRam0203cfb0 & 3) * 8 |
               *(uint *)(uRam0203cfb0 & 0xfffffffc) << (uRam0203cfb0 & 3) * -8 + 0x20) + 0x14 +
               iVar11;
      *(ushort *)(iVar11 + 0x30) = *(ushort *)(iVar11 + 0x30) & 0xffdf;
      return;
    }
    return;
  }
  return;
}

