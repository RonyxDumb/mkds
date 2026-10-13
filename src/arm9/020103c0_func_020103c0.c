/* Decompiled C draft; module arm9; ROM address 020103c0. No matching claim. */
#include "types.h"
#include "deps/020103c0_func_020103c0.h"

void func_020103c0(int param_1,ushort *param_2,int param_3,ushort *param_4)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar4 = *param_2;
  uVar2 = param_3 + 0x2cU & 3;
  uVar5 = *(uint *)(param_3 + 0x2cU & 0xfffffffc);
  uVar2 = (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) & 0xffff;
  uVar5 = (uint)*param_4;
  if ((param_4[1] & 1) == 0) {
    uVar2 = (uVar2 << 0xf) >> 0x10;
    uVar5 = (uVar5 << 0xf) >> 0x10;
  }
  uVar6 = 0;
  if ((char)param_2[1] != '\0') {
    do {
      pbVar1 = (byte *)(param_1 + (uint)uVar4 + uVar6);
      uVar6 = uVar6 + 1;
      uVar7 = (uint)*(ushort *)(param_1 + 4 + (uint)*(ushort *)(param_1 + 10)) * (uint)*pbVar1 +
              param_1 + 4 + (uint)*(ushort *)(param_1 + 10) + 4;
      uVar3 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      *(short *)(param_1 + (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) + 0x1c) =
           (short)((uVar5 + uVar2) * 0x10000 >> 0x10);
    } while (uVar6 < (byte)param_2[1]);
  }
  *(byte *)((int)param_2 + 3) = *(byte *)((int)param_2 + 3) | 1;
  return;
}

