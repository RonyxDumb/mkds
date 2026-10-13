/* Decompiled C draft; module arm9; ROM address 020c55b0. No matching claim. */
#include "types.h"
#include "deps/020c55b0_func_020c55b0.h"

void func_020c55b0(int param_1)

{
  int iVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 local_3c;
  int local_38;
  undefined4 local_34;
  int local_30;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  int local_18;
  
  uVar7 = (*(uint *)(uRam020c5800 & 0xfffffffc) >> (uRam020c5800 & 3) * 8 |
          *(uint *)(uRam020c5800 & 0xfffffffc) << (uRam020c5800 & 3) * -8 + 0x20) + 4;
  uVar5 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  iVar3 = ComputeValueInterpolation_from_thumb
                    (1,0x40,0,uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20,0x14);
  uVar7 = (*(uint *)(uRam020c5800 & 0xfffffffc) >> (uRam020c5800 & 3) * 8 |
          *(uint *)(uRam020c5800 & 0xfffffffc) << (uRam020c5800 & 3) * -8 + 0x20) + 8;
  uVar5 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar4 = GetB3C4_Cell_RaceGoalM(uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
  local_38 = (iVar3 + 0xa8) * 0x1000;
  local_3c = 0x18000;
  sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,(ushort *)(uintptr_t)(uVar4),0,(uint)(uintptr_t)(&local_3c),0,1);
  uVar5 = uRam020c5800;
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  uVar7 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar7 = (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) + 0xc;
  uVar5 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar4 = GetB3C4_Cell_RaceGoalM((uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) + 8);
  local_34 = 0x48000;
  iVar1 = (iVar3 + 0xb0) * 0x1000;
  local_30 = iVar1;
  sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,(ushort *)(uintptr_t)(uVar4),0,(uint)(uintptr_t)(&local_34),0,1);
  uVar5 = uRam020c5800;
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  uVar7 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar7 = (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) + 0xc;
  uVar5 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  iVar6 = SomeCheckLangFrench(uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
  if (iVar6 == 0) {
    uVar4 = 0x14;
  }
  else {
    uVar4 = 0x13;
  }
  uVar4 = GetB3C4_Cell_RaceGoalM(uVar4);
  local_2c = 0x48000;
  local_28 = iVar1;
  sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,(ushort *)(uintptr_t)(uVar4),0,(uint)(uintptr_t)(&local_2c),0,1);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  uVar4 = GetB3C4_Cell_RaceGoalM(0x40);
  iVar1 = (iVar3 + 0xa6) * 0x1000;
  local_24 = 0xda000;
  local_20 = iVar1;
  sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,(ushort *)(uintptr_t)(uVar4),0,(uint)(uintptr_t)(&local_24),0,1);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  uVar4 = GetB3C4_Cell_RaceGoalM(0x41);
  local_1c = 0xda000;
  local_18 = iVar1;
  sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,(ushort *)(uintptr_t)(uVar4),0,(uint)(uintptr_t)(&local_1c),0,1);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  return;
}

