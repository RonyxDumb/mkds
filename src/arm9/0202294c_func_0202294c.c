/* Decompiled C draft; module arm9; ROM address 0202294c. No matching claim. */
#include "types.h"
#include "deps/0202294c_func_0202294c.h"

void func_0202294c(uint param_1)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  if (*(short *)((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                 *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 4) == 0) {
    return;
  }
  puVar1 = (ushort *)func_020222e0();
  uVar6 = param_1 + 0x30 & 3;
  uVar8 = *(uint *)(param_1 + 0x30 & 0xfffffffc);
  uVar8 = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
  uVar2 = CellBank_GetMetatileEntry((ushort *)(uintptr_t)(uVar8),*puVar1);
  *(undefined4 *)(param_1 + 0x2c) = uVar2;
  uVar6 = param_1 + 0x18 & 3;
  uVar4 = *(uint *)(param_1 + 0x18 & 0xfffffffc);
  uVar6 = (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) + 4;
  uVar4 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar6 = (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) & 0xff;
  func_02022474((undefined4 *)(uintptr_t)(param_1 + 0x38),1);
  if (uVar6 != 0) {
    if (uVar6 == 2) {
      func_020224c0(param_1 + 0x38,(int)(short)puVar1[2],(int)(short)puVar1[3]);
    }
    else {
      uVar6 = (uint)(puVar1 + 2) & 3;
      uVar7 = *(uint *)((uint)(puVar1 + 2) & 0xfffffffc);
      uVar4 = (uint)(puVar1 + 4) & 3;
      uVar3 = *(uint *)((uint)(puVar1 + 4) & 0xfffffffc);
      func_02022484(param_1 + 0x38,uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20,
                    uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
      func_020224a4(param_1 + 0x38,puVar1[1]);
      func_020224c0(param_1 + 0x38,(int)(short)puVar1[6],(int)(short)puVar1[7]);
    }
  }
  uVar8 = uVar8 + 0xc;
  uVar6 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  uVar6 = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
  if (uVar6 == 0) {
    return;
  }
  uVar8 = param_1 + 0x34 & 3;
  uVar4 = *(uint *)(param_1 + 0x34 & 0xfffffffc);
  if ((uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) == 0xffffffff) {
    return;
  }
  uVar6 = uVar6 + 4;
  uVar8 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar7 = uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20;
  uVar8 = param_1 + 0x34 & 3;
  uVar3 = *(uint *)(param_1 + 0x34 & 0xfffffffc);
  uVar6 = uVar7 + (uint)*puVar1 * 8;
  uVar4 = uVar6 & 3;
  uVar5 = *(uint *)(uVar6 & 0xfffffffc);
  uVar6 = uVar7 + (uint)*puVar1 * 8 + 4;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  func_02022a60(uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20,
                uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20,
                uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20);
  return;
}

