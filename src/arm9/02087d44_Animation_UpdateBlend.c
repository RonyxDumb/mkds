/* Decompiled C draft; module arm9; ROM address 02087d44. No matching claim. */
#include "types.h"
#include "deps/02087d44_Animation_UpdateBlend.h"

void Animation_UpdateBlend(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = param_1 + 0x2cU & 3;
  uVar1 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
  if (uVar1 >> uVar4 * 8 == 0 && uVar1 << uVar4 * -8 + 0x20 == 0) {
    return;
  }
  uVar4 = param_1 + 0x1cU & 3;
  uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  uVar1 = param_1 + 0x30U & 3;
  uVar2 = *(uint *)(param_1 + 0x30U & 0xfffffffc);
  uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + (uint)*(ushort *)(param_1 + 0x1a) * 4;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  uVar4 = uVar5 + 4;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(uint *)(uVar5 + 4) =
       (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) +
       (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  uVar4 = param_1 + 0x34U & 3;
  uVar1 = *(uint *)(param_1 + 0x34U & 0xfffffffc);
  uVar5 = uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20;
  uVar1 = param_1 + 0x30U & 3;
  uVar2 = *(uint *)(param_1 + 0x30U & 0xfffffffc);
  uVar4 = uVar5 + 4;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(uint *)(uVar5 + 4) =
       (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) -
       (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  uVar4 = param_1 + 0x1cU & 3;
  uVar1 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  uVar4 = (uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) + (uint)*(ushort *)(param_1 + 0x1a) * 4;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + 4;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if (0xfff < (int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20)) {
    *(undefined4 *)(param_1 + 0x2c) = 0;
    uVar4 = param_1 + 0x1cU & 3;
    uVar1 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    uVar4 = (uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) +
            (uint)*(ushort *)(param_1 + 0x1a) * 4;
    uVar1 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    *(undefined4 *)((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + 4) = 0x1000;
    uVar4 = param_1 + 0x14U & 3;
    uVar3 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
    uVar1 = param_1 + 0x34U & 3;
    uVar2 = *(uint *)(param_1 + 0x34U & 0xfffffffc);
    StructML_SomeFn_2((uint *)(uintptr_t)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20),
                      uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
    *(undefined4 *)(param_1 + 0x34) = 0;
    return;
  }
  return;
}

