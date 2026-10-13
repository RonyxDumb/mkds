/* Decompiled C draft; module arm9; ROM address 020b9dfc. No matching claim. */
#include "types.h"
#include "deps/020b9dfc_func_020b9dfc.h"

void func_020b9dfc(int param_1)

{
  ushort uVar1;
  longlong lVar2;
  short sVar3;
  int iVar4;
  ushort *puVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  uint *puVar12;
  
  uVar11 = *(uint *)(uRam020ba3cc & 0xfffffffc) >> (uRam020ba3cc & 3) * 8 |
           *(uint *)(uRam020ba3cc & 0xfffffffc) << (uRam020ba3cc & 3) * -8 + 0x20;
  uVar10 = uVar11 + 0xc;
  uVar8 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  uVar10 = uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20;
  if (uVar10 == 4) {
    return;
  }
  if (uVar10 == 1) {
    return;
  }
  uVar11 = uVar11 + 8;
  uVar10 = uVar11 & 3;
  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
  uVar10 = uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20;
  if (uVar10 == 1) {
    uVar10 = iRam020ba3e4 + 0x3cU & 3;
    uVar11 = *(uint *)(iRam020ba3e4 + 0x3cU & 0xfffffffc);
    if ((uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20) != 2) {
      return;
    }
    iVar4 = func_0204a650(uRam020ba3e8);
    if (iVar4 == 0) {
      return;
    }
    *(undefined4 *)
     ((*(uint *)(uRam020ba3d0 & 0xfffffffc) >> (uRam020ba3d0 & 3) * 8 |
      *(uint *)(uRam020ba3d0 & 0xfffffffc) << (uRam020ba3d0 & 3) * -8 + 0x20) + 8) = 0;
    uVar9 = GetB3C4_Cell_RaceTaM(0xd);
    uVar10 = (uint)*(ushort *)(param_1 + 0x400);
    puVar12 = (uint *)(param_1 + uVar10 * 8);
    sVar3 = MaybeMakeOamSlot(puVar12,0x80 - uVar10 & 0xffff,uVar9);
    puVar5 = (ushort *)(param_1 + 0x400);
    *puVar5 = *puVar5 + sVar3;
    if (uVar10 < *puVar5) {
      do {
        uVar10 = uVar10 + 1;
        *puVar12 = (*(uint *)((uint)puVar12 & 0xfffffffc) >> ((uint)puVar12 & 3) * 8 |
                   *(uint *)((uint)puVar12 & 0xfffffffc) << ((uint)puVar12 & 3) * -8 + 0x20) &
                   0xfffff3ff | 0x800;
        uVar11 = (uint)(puVar12 + 1) & 3;
        uVar8 = *(uint *)((uint)(puVar12 + 1) & 0xfffffffc);
        puVar12[1] = (uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) & 0xfffff3ff | 0x400;
        puVar12 = puVar12 + 2;
      } while ((int)uVar10 < (int)(uint)*puVar5);
    }
    uVar9 = GetB3C4_Cell_RaceTaM(0xd);
    sVar3 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar9);
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar3;
    return;
  }
  if (uVar10 != 2) {
    if (uVar10 == 4) {
      func_020b9994();
      return;
    }
    uVar11 = *(uint *)(uRam020ba3d0 & 0xfffffffc) >> (uRam020ba3d0 & 3) * 8 |
             *(uint *)(uRam020ba3d0 & 0xfffffffc) << (uRam020ba3d0 & 3) * -8 + 0x20;
    uVar10 = uVar11 & 3;
    uVar11 = *(uint *)(uVar11 & 0xfffffffc);
    uVar9 = GetB3C4_Cell_RaceM(uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20);
    sVar3 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar9);
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar3;
    return;
  }
  GetCurrentPlayerRacerId();
  iVar4 = IsRacerFinishedRace();
  if (iVar4 != 0) {
    iVar4 = GetCurrentPlayerRacerId();
    uVar10 = iVar4 * 0x8c +
             (*(uint *)(uRam020ba3dc & 0xfffffffc) >> (uRam020ba3dc & 3) * 8 |
             *(uint *)(uRam020ba3dc & 0xfffffffc) << (uRam020ba3dc & 3) * -8 + 0x20) + 0x14;
    uVar11 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    if ((uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20) != 2) {
      return;
    }
    GetCurrentPlayerRacerId();
    iVar4 = GetDriverEntry();
    uVar10 = iVar4 + 0x7cU & 3;
    uVar11 = *(uint *)(iVar4 + 0x7cU & 0xfffffffc);
    if (((uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20) & uRam020ba3e0) == 0) {
      return;
    }
    uVar9 = GetB3C4_Cell_RaceBattleM(0xc);
    sVar3 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar9);
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar3;
    return;
  }
  uVar10 = (*(uint *)(uRam020ba3cc & 0xfffffffc) >> (uRam020ba3cc & 3) * 8 |
           *(uint *)(uRam020ba3cc & 0xfffffffc) << (uRam020ba3cc & 3) * -8 + 0x20) + 0x18;
  uVar11 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  if (uVar10 >> uVar11 * 8 != 0 || uVar10 << uVar11 * -8 + 0x20 != 0) {
    iVar6 = GetRaceStartCountdown();
    iVar4 = iVar6 >> 0x1f;
    GetCurrentPlayerRacerId();
    iVar7 = func_020a1048();
    if ((iVar7 != 0) &&
       (9 < (int)(((uint)(iVar6 * 0x10000000 + iVar4) >> 0x1c | iVar4 << 4) - iVar4))) {
      return;
    }
    uVar10 = (uint)*(ushort *)
                    (*(uint *)(uRam020ba3d0 & 0xfffffffc) >> (uRam020ba3d0 & 3) * 8 |
                    *(uint *)(uRam020ba3d0 & 0xfffffffc) << (uRam020ba3d0 & 3) * -8 + 0x20);
    uVar9 = GetB3C4_Cell_RaceBattleM(0xb);
    sVar3 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar9);
    iVar4 = iRam020ba3d4;
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar3;
    uVar9 = GetB3C4_Cell_RaceBattleM
                      ((int)((longlong)iVar4 * (longlong)(int)uVar10 >> 0x22),
                       (int)((longlong)iVar4 * (longlong)(int)uVar10));
    sVar3 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar9);
    iVar4 = iRam020ba3d4;
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar3;
    lVar2 = (longlong)iRam020ba3d8 *
            (longlong)(int)((longlong)iVar4 * (longlong)(int)uVar10 >> 0x22);
    uVar9 = GetB3C4_Cell_RaceBattleM(uVar10 - (int)lVar2,(int)((ulonglong)lVar2 >> 0x20));
    sVar3 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar9);
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar3;
    return;
  }
  iVar4 = 0;
  puVar5 = (ushort *)
           (*(uint *)(uRam020ba3d0 & 0xfffffffc) >> (uRam020ba3d0 & 3) * 8 |
           *(uint *)(uRam020ba3d0 & 0xfffffffc) << (uRam020ba3d0 & 3) * -8 + 0x20);
  uVar10 = (uint)puVar5[1];
  uVar1 = *puVar5;
  if (uVar10 != 0) {
    do {
      uVar9 = GetB3C4_Cell_RaceBattleM(10);
      sVar3 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                               0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar9,0);
      iVar4 = iVar4 + 1;
      *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar3;
    } while (iVar4 < (int)uVar10);
  }
  if (uVar1 == 0) {
    return;
  }
  if (5 < uVar1) {
    return;
  }
  uVar9 = GetB3C4_Cell_RaceBattleM(10);
  sVar3 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar9);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar3;
  return;
}

