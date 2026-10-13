/* Decompiled C draft; module arm9; ROM address 020d18d4. No matching claim. */
#include "types.h"
#include "deps/020d18d4_func_020d18d4.h"

void func_020d18d4(int param_1)

{
  undefined2 uVar1;
  short sVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int local_34 [3];
  undefined4 local_28;
  int local_24 [3];
  int local_18;
  int local_14;
  
  local_24[2] = *piRam020d1a90;
  local_18 = piRam020d1a90[1];
  local_14 = piRam020d1a90[2];
  uVar5 = *(uint *)(uRam020d1a94 & 0xfffffffc) >> (uRam020d1a94 & 3) * 8 |
          *(uint *)(uRam020d1a94 & 0xfffffffc) << (uRam020d1a94 & 3) * -8 + 0x20;
  uVar1 = *(undefined2 *)(uVar5 + 0x20);
  uVar6 = uVar5 + 0x18 & 3;
  uVar7 = *(uint *)(uVar5 + 0x18 & 0xfffffffc);
  uVar3 = GetB3C4_Cell_RaceM((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                             *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x2d);
  uVar5 = (*(uint *)(uRam020d1a94 & 0xfffffffc) >> (uRam020d1a94 & 3) * 8 |
          *(uint *)(uRam020d1a94 & 0xfffffffc) << (uRam020d1a94 & 3) * -8 + 0x20) + 0x24;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  local_34[0] = (local_24[2] + (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20)) * 0x1000;
  local_34[1] = 0xb1000;
  sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3,
                           uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20,local_34,uVar1,1);
  uVar6 = uRam020d1a94;
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar5 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  uVar1 = *(undefined2 *)(uVar5 + 0x20);
  uVar5 = uVar5 + 0x18;
  uVar6 = uVar5 & 3;
  uVar7 = *(uint *)(uVar5 & 0xfffffffc);
  uVar3 = GetB3C4_Cell_RaceM(0x37);
  uVar5 = (*(uint *)(uRam020d1a94 & 0xfffffffc) >> (uRam020d1a94 & 3) * 8 |
          *(uint *)(uRam020d1a94 & 0xfffffffc) << (uRam020d1a94 & 3) * -8 + 0x20) + 0x24;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  local_28 = 0xb1000;
  local_34[2] = (local_18 + (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20)) * 0x1000;
  sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3,
                           uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20,local_34 + 2,uVar1,1);
  uVar6 = uRam020d1a94;
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar4 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  uVar1 = *(undefined2 *)(uVar4 + 0x20);
  uVar6 = uVar4 + 0x18 & 3;
  uVar7 = *(uint *)(uVar4 + 0x18 & 0xfffffffc);
  uVar5 = uVar4 + 4 & 3;
  uVar4 = *(uint *)(uVar4 + 4 & 0xfffffffc);
  uVar3 = GetB3C4_Cell_RaceM((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x2d);
  uVar5 = (*(uint *)(uRam020d1a94 & 0xfffffffc) >> (uRam020d1a94 & 3) * 8 |
          *(uint *)(uRam020d1a94 & 0xfffffffc) << (uRam020d1a94 & 3) * -8 + 0x20) + 0x24;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  local_24[1] = 0xb1000;
  local_24[0] = (local_14 + (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20)) * 0x1000;
  sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3,
                           uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20,local_24,uVar1,1);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  return;
}

