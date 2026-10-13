/* Decompiled C draft; module arm9; ROM address 02087e90. No matching claim. */
#include "types.h"
#include "deps/02087e90_Animation_SetWithBlendAt.h"

void Animation_SetWithBlendAt(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar2 = param_1 + 0x1cU & 3;
  uVar1 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + param_2 * 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
    return;
  }
  if (*(ushort *)(param_1 + 0x1a) != param_2) {
    *(undefined4 *)(param_1 + 0x2c) = 1;
    uVar2 = param_1 + 0x34U & 3;
    uVar1 = *(uint *)(param_1 + 0x34U & 0xfffffffc);
    if (uVar1 >> uVar2 * 8 != 0 || uVar1 << uVar2 * -8 + 0x20 != 0) {
      uVar2 = param_1 + 0x14U & 3;
      uVar1 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
      StructML_SomeFn_2(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
      *(undefined4 *)(param_1 + 0x34) = 0;
    }
    uVar2 = param_1 + 0x1cU & 3;
    uVar1 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) +
            (uint)*(ushort *)(param_1 + 0x1a) * 4;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    *(uint *)(param_1 + 0x34) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    uVar2 = param_1 + 0x34U & 3;
    uVar1 = *(uint *)(param_1 + 0x34U & 0xfffffffc);
    *(undefined4 *)((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 4) = 0x1000;
    *(short *)(param_1 + 0x1a) = (short)param_2;
    uVar2 = param_1 + 0x1cU & 3;
    uVar5 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    uVar1 = param_1 + 0x14U & 3;
    uVar3 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
    uVar2 = (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) +
            (uint)*(ushort *)(param_1 + 0x1a) * 4;
    uVar5 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    StructML_SomeFn_3(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,
                      uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20);
    iVar4 = iRam02087f80;
    uVar2 = param_1 + 0x1cU & 3;
    uVar1 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) +
            (uint)*(ushort *)(param_1 + 0x1a) * 4;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    *(undefined4 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 4) = 0;
    uVar2 = param_1 + 0x28U & 3;
    uVar5 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
    uVar1 = param_1 + 0x1cU & 3;
    uVar6 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    uVar2 = iVar4 + (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) * 4;
    uVar5 = uVar2 & 3;
    uVar3 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) +
            (uint)*(ushort *)(param_1 + 0x1a) * 4;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    iVar4 = (*(code *)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20))
                      (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
    uVar2 = param_1 + 0x20U & 3;
    uVar1 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) +
            (uint)*(ushort *)(param_1 + 0x1a) * 4;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    Animation_SetParameters
              ((undefined2 *)(uintptr_t)(param_1),iVar4 << 0xc,(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xffff);
    return;
  }
  return;
}

