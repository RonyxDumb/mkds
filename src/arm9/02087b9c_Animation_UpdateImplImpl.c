/* Decompiled C draft; module arm9; ROM address 02087b9c. No matching claim. */
#include "types.h"
#include "deps/02087b9c_Animation_UpdateImplImpl.h"

void Animation_UpdateImplImpl(short *param_1)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  sVar1 = *param_1;
  if (sVar1 == 0) {
    uVar6 = (uint)(param_1 + 2) & 3;
    uVar3 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    uVar2 = (uint)(param_1 + 6) & 3;
    uVar5 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
    iVar4 = (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) - 0x1000;
    if (iVar4 <= (int)(uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20)) {
      *(int *)(param_1 + 6) = iVar4;
      param_1[4] = 0;
      param_1[5] = 0;
      param_1[1] = 1;
      return;
    }
    return;
  }
  if (sVar1 == 1) {
    uVar6 = (uint)(param_1 + 2) & 3;
    uVar2 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    uVar2 = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
    uVar6 = (uint)(param_1 + 6) & 3;
    uVar5 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    if ((int)uVar6 < (int)uVar2) {
      if ((int)uVar6 < 1) {
        *(uint *)(param_1 + 6) = (uVar2 - 0x1000) + uVar6;
      }
      return;
    }
    *(uint *)(param_1 + 6) = uVar6 - uVar2;
    return;
  }
  if (sVar1 != 2) {
    return;
  }
  if ((ushort)param_1[8] < (ushort)param_1[9]) {
    uVar6 = (uint)(param_1 + 2) & 3;
    uVar2 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    uVar2 = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
    uVar6 = (uint)(param_1 + 6) & 3;
    uVar5 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    if ((int)uVar6 < (int)uVar2) {
      if ((int)uVar6 < 1) {
        *(uint *)(param_1 + 6) = (uVar2 - 0x1000) + uVar6;
        param_1[8] = param_1[8] + 1;
      }
    }
    else {
      *(uint *)(param_1 + 6) = uVar6 - uVar2;
      param_1[8] = param_1[8] + 1;
    }
    if ((ushort)param_1[9] <= (ushort)param_1[8]) {
      uVar6 = (uint)(param_1 + 2) & 3;
      uVar2 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
      *(uint *)(param_1 + 6) = (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) - 0x1000;
      param_1[4] = 0;
      param_1[5] = 0;
      param_1[1] = 1;
      return;
    }
    return;
  }
  return;
}

