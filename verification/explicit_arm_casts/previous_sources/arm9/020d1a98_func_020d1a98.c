/* Decompiled C draft; module arm9; ROM address 020d1a98. No matching claim. */
#include "types.h"
#include "deps/020d1a98_func_020d1a98.h"

/* WARNING: Type propagation algorithm not settling */

void func_020d1a98(int param_1)

{
  undefined2 uVar1;
  longlong lVar2;
  short sVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int local_4c [3];
  undefined4 local_40;
  int local_3c [3];
  undefined4 local_30;
  int local_2c [3];
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  
  local_2c[2] = *piRam020d1dd8;
  local_20 = piRam020d1dd8[1];
  local_1c = piRam020d1dd8[2];
  local_18 = piRam020d1dd8[3];
  uVar6 = (uint)(piRam020d1dd8 + 4) & 3;
  uVar4 = *(uint *)((uint)(piRam020d1dd8 + 4) & 0xfffffffc);
  local_14 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
  uVar4 = *(uint *)(uRam020d1ddc & 0xfffffffc) >> (uRam020d1ddc & 3) * 8 |
          *(uint *)(uRam020d1ddc & 0xfffffffc) << (uRam020d1ddc & 3) * -8 + 0x20;
  uVar6 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
  lVar2 = (longlong)iRam020d1de0 * (longlong)(int)uVar6;
  iVar7 = (int)(lVar2 >> 0x22) - ((int)uVar6 >> 0x1f);
  if (iVar7 != 0) {
    uVar1 = *(undefined2 *)(uVar4 + 0x20);
    uVar9 = uVar4 + 0x18 & 3;
    uVar8 = *(uint *)(uVar4 + 0x18 & 0xfffffffc);
    uVar5 = GetB3C4_Cell_RaceM(iVar7 + 0x2d,(int)lVar2);
    uVar6 = (*(uint *)(uRam020d1ddc & 0xfffffffc) >> (uRam020d1ddc & 3) * 8 |
            *(uint *)(uRam020d1ddc & 0xfffffffc) << (uRam020d1ddc & 3) * -8 + 0x20) + 0x24;
    uVar4 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    local_4c[0] = (local_2c[2] + (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20)) * 0x1000;
    local_4c[1] = 0xb1000;
    sVar3 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar5,
                             uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20,local_4c,uVar1,1);
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar3;
  }
  uVar9 = *(uint *)(uRam020d1ddc & 0xfffffffc) >> (uRam020d1ddc & 3) * 8 |
          *(uint *)(uRam020d1ddc & 0xfffffffc) << (uRam020d1ddc & 3) * -8 + 0x20;
  uVar6 = *(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
          *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20;
  uVar1 = *(undefined2 *)(uVar9 + 0x20);
  lVar2 = (longlong)iRam020d1de4 *
          (longlong)
          ((int)((longlong)iRam020d1de0 * (longlong)(int)uVar6 >> 0x22) - ((int)uVar6 >> 0x1f));
  uVar4 = uVar9 + 0x18 & 3;
  uVar8 = *(uint *)(uVar9 + 0x18 & 0xfffffffc);
  uVar5 = GetB3C4_Cell_RaceM((uVar6 - (int)lVar2) + 0x2d,(int)((ulonglong)lVar2 >> 0x20));
  uVar6 = (*(uint *)(uRam020d1ddc & 0xfffffffc) >> (uRam020d1ddc & 3) * 8 |
          *(uint *)(uRam020d1ddc & 0xfffffffc) << (uRam020d1ddc & 3) * -8 + 0x20) + 0x24;
  uVar9 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  local_4c[2] = (local_20 + (uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20)) * 0x1000;
  local_40 = 0xb1000;
  sVar3 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar5,
                           uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20,local_4c + 2,uVar1,1);
  uVar4 = uRam020d1ddc;
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar3;
  uVar6 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar6 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
  uVar1 = *(undefined2 *)(uVar6 + 0x20);
  uVar6 = uVar6 + 0x18;
  uVar4 = uVar6 & 3;
  uVar8 = *(uint *)(uVar6 & 0xfffffffc);
  uVar5 = GetB3C4_Cell_RaceM(0x37);
  uVar6 = (*(uint *)(uRam020d1ddc & 0xfffffffc) >> (uRam020d1ddc & 3) * 8 |
          *(uint *)(uRam020d1ddc & 0xfffffffc) << (uRam020d1ddc & 3) * -8 + 0x20) + 0x24;
  uVar9 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  local_3c[1] = 0xb1000;
  local_3c[0] = (local_1c + (uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20)) * 0x1000;
  sVar3 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar5,
                           uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20,local_3c,uVar1,1);
  iVar7 = iRam020d1de0;
  uVar4 = uRam020d1ddc;
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar3;
  uVar6 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar9 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
  uVar6 = uVar9 + 4 & 3;
  uVar4 = *(uint *)(uVar9 + 4 & 0xfffffffc);
  uVar6 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
  uVar1 = *(undefined2 *)(uVar9 + 0x20);
  uVar4 = uVar9 + 0x18 & 3;
  uVar8 = *(uint *)(uVar9 + 0x18 & 0xfffffffc);
  uVar5 = GetB3C4_Cell_RaceM(((int)((longlong)iVar7 * (longlong)(int)uVar6 >> 0x22) -
                             ((int)uVar6 >> 0x1f)) + 0x2d);
  uVar6 = (*(uint *)(uRam020d1ddc & 0xfffffffc) >> (uRam020d1ddc & 3) * 8 |
          *(uint *)(uRam020d1ddc & 0xfffffffc) << (uRam020d1ddc & 3) * -8 + 0x20) + 0x24;
  uVar9 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  local_30 = 0xb1000;
  local_3c[2] = (local_18 + (uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20)) * 0x1000;
  sVar3 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar5,
                           uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20,local_3c + 2,uVar1,1);
  iVar7 = iRam020d1de0;
  uVar4 = uRam020d1ddc;
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar3;
  uVar6 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar9 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
  uVar6 = uVar9 + 4 & 3;
  uVar4 = *(uint *)(uVar9 + 4 & 0xfffffffc);
  uVar6 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
  uVar1 = *(undefined2 *)(uVar9 + 0x20);
  uVar4 = uVar9 + 0x18 & 3;
  uVar8 = *(uint *)(uVar9 + 0x18 & 0xfffffffc);
  uVar5 = GetB3C4_Cell_RaceM((uVar6 - iRam020d1de4 *
                                      ((int)((longlong)iVar7 * (longlong)(int)uVar6 >> 0x22) -
                                      ((int)uVar6 >> 0x1f))) + 0x2d);
  uVar6 = (*(uint *)(uRam020d1ddc & 0xfffffffc) >> (uRam020d1ddc & 3) * 8 |
          *(uint *)(uRam020d1ddc & 0xfffffffc) << (uRam020d1ddc & 3) * -8 + 0x20) + 0x24;
  uVar9 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  local_2c[1] = 0xb1000;
  local_2c[0] = (local_14 + (uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20)) * 0x1000;
  sVar3 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar5,
                           uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20,local_2c,uVar1,1);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar3;
  return;
}

