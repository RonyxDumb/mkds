/* Decompiled C draft; module arm9; ROM address 020d06b8. No matching claim. */
#include "types.h"
#include "deps/020d06b8_func_020d06b8.h"

void func_020d06b8(int param_1)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined4 auStack_3c [6];
  
  iVar3 = GetB3F0_Beb1();
  uVar7 = *(uint *)(uRam020d0a10 & 0xfffffffc) >> (uRam020d0a10 & 3) * 8 |
          *(uint *)(uRam020d0a10 & 0xfffffffc) << (uRam020d0a10 & 3) * -8 + 0x20;
  uVar4 = uVar7 + 8;
  uVar8 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20;
  if ((uVar4 != 0) && (uVar4 != 1)) {
    return;
  }
  uVar7 = uVar7 + 0xc;
  uVar4 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar4 = uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20;
  if (uVar4 == 4) {
    return;
  }
  if (uVar4 == 1) {
    return;
  }
  iVar5 = IsSavingTimeTrialRecord();
  if (iVar5 != 0) {
    uVar6 = GetB3C4_Cell_RaceGoalM(0x43);
    sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar6);
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  }
  if (iVar3 < 1) {
    return;
  }
  uVar4 = 0;
  do {
    uVar6 = ComputeValueInterpolation_from_thumb(1,0x80,0,iVar3 + uVar4 * -4);
    auStack_3c[uVar4] = uVar6;
    uVar4 = uVar4 + 1 & 0xffff;
  } while (uVar4 < 6);
  iVar3 = func_020c7148();
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (*(uint *)(uRam020d0a14 & 0xfffffffc) >> (uRam020d0a14 & 3) * 8 |
            *(uint *)(uRam020d0a14 & 0xfffffffc) << (uRam020d0a14 & 3) * -8 + 0x20) + 0xac;
    uVar7 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar4 = uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20;
  }
  uVar6 = GetB3C4_Cell_RaceGoalM(uVar4 + 0x15);
  sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar6);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  func_020c7148();
  func_020d029c(param_1,auStack_3c[0],0x10,
                *(uint *)(uRam020d0a14 & 0xfffffffc) >> (uRam020d0a14 & 3) * 8 |
                *(uint *)(uRam020d0a14 & 0xfffffffc) << (uRam020d0a14 & 3) * -8 + 0x20);
  iVar3 = GetLastTimeTrialWasRecord();
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (*(uint *)(uRam020d0a14 & 0xfffffffc) >> (uRam020d0a14 & 3) * 8 |
            *(uint *)(uRam020d0a14 & 0xfffffffc) << (uRam020d0a14 & 3) * -8 + 0x20) + 0xac;
    uVar7 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar4 = uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20;
  }
  uVar6 = GetB3C4_Cell_RaceGoalM(uVar4 + 0x16);
  sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar6);
  uVar8 = 0;
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  iVar3 = GetCurrentLapCount();
  uVar7 = uRam020d0a14;
  uVar4 = uVar8;
  if (iVar3 == 0) {
    return;
  }
  do {
    iVar3 = GetLastTimeTrialWasRecord();
    uVar10 = uVar8;
    if ((iVar3 != 0) && (iVar3 = GetLeastTimeLapId(), uVar4 + 1 == iVar3)) {
      uVar10 = (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
               *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0xac;
      uVar1 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      uVar10 = uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20;
    }
    uVar6 = GetB3C4_Cell_RaceGoalM(uVar4 + 0x18 + uVar10);
    uVar9 = auStack_3c[uVar4 + 1];
    sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar6,0);
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
    func_020d029c(param_1,uVar9,uVar4 * 0x10 + 0x28,
                  uVar4 * 0x1c +
                  (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                  *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x1c);
    uVar4 = uVar4 + 1 & 0xffff;
    uVar10 = GetCurrentLapCount();
  } while (uVar4 < uVar10);
  return;
}

