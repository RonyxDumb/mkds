/* Decompiled C draft; module arm9; ROM address 020c2570. No matching claim. */
#include "types.h"
#include "deps/020c2570_func_020c2570.h"

void func_020c2570(int param_1,int param_2)

{
  longlong lVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  
  uVar10 = (*(uint *)(uRam020c28c8 & 0xfffffffc) >> (uRam020c28c8 & 3) * 8 |
           *(uint *)(uRam020c28c8 & 0xfffffffc) << (uRam020c28c8 & 3) * -8 + 0x20) + param_2 * 4 +
           0x20;
  uVar5 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  uVar10 = uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20;
  iVar4 = -((int)uVar10 >> 0x1f);
  iVar7 = iVar4 + (int)((longlong)iRam020c28cc * (longlong)(int)uVar10 >> 0x22);
  iVar9 = iVar4 + (int)((longlong)iRam020c28d0 * (longlong)(int)uVar10 >> 0x25);
  iVar7 = iVar7 - iRam020c28d4 *
                  ((int)((longlong)iRam020c28cc * (longlong)iVar7 >> 0x22) - (iVar7 >> 0x1f));
  lVar1 = (longlong)iRam020c28d4 *
          (longlong)(iVar4 + (int)((longlong)iRam020c28cc * (longlong)(int)uVar10 >> 0x22));
  iVar8 = (int)lVar1;
  uVar3 = GetB3C4_Cell_RaceGoalTeamS(param_2,iVar8,iRam020c28d4,(int)((ulonglong)lVar1 >> 0x20));
  sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  uVar3 = GetB3C4_Cell_RaceGoalTeamS(param_2 + 0x20);
  sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  iVar4 = GetCurrentPlayerRacerId();
  if (param_2 == iVar4) {
    uVar5 = param_2 * 0x30 +
            (*(uint *)(uRam020c28d8 & 0xfffffffc) >> (uRam020c28d8 & 3) * 8 |
            *(uint *)(uRam020c28d8 & 0xfffffffc) << (uRam020c28d8 & 3) * -8 + 0x20) + 0x74;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    if (uVar5 >> uVar6 * 8 == 0 && uVar5 << uVar6 * -8 + 0x20 == 0) {
      uVar3 = 0x1e;
    }
    else {
      uVar3 = 0x1f;
    }
  }
  else {
    uVar5 = param_2 * 0x30 +
            (*(uint *)(uRam020c28d8 & 0xfffffffc) >> (uRam020c28d8 & 3) * 8 |
            *(uint *)(uRam020c28d8 & 0xfffffffc) << (uRam020c28d8 & 3) * -8 + 0x20) + 0x74;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    if (uVar5 >> uVar6 * 8 == 0 && uVar5 << uVar6 * -8 + 0x20 == 0) {
      uVar3 = 0x1c;
    }
    else {
      uVar3 = 0x1d;
    }
  }
  uVar3 = GetB3C4_Cell_RaceGoalTeamS(uVar3);
  sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3);
  uVar6 = uRam020c28d8;
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar5 = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 8;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if ((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) == 2) {
    return;
  }
  iVar4 = uVar10 - iVar8;
  if (9 < iVar9) {
    iVar7 = 9;
    iVar4 = iVar7;
    iVar9 = iVar7;
  }
  if (iVar9 == 0) {
    if (iVar7 == 0) goto LAB_020c285c;
  }
  else {
    uVar3 = GetB3C4_Cell_RaceGoalTeamS(iVar9 + 8);
    sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3);
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  }
  uVar3 = GetB3C4_Cell_RaceGoalTeamS(iVar7 + 8);
  sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
LAB_020c285c:
  uVar3 = GetB3C4_Cell_RaceGoalTeamS(iVar4 + 8);
  sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  return;
}

