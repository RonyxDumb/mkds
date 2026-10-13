/* Decompiled C draft; module arm9; ROM address 020ef9a8. No matching claim. */
#include "types.h"
#include "deps/020ef9a8_func_020ef9a8.h"

void func_020ef9a8(int param_1)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar1 = param_1 + 0x14U & 3;
  uVar6 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0x4c);
  uVar2 = param_1 + 0x44U & 3;
  uVar4 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  *(uint *)(param_1 + 0x9c) = -(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
  uVar2 = param_1 + 0x48U & 3;
  uVar4 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(param_1 + 0xa0) = -(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
  uVar2 = param_1 + 0x4cU & 3;
  uVar4 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  *(uint *)(param_1 + 0xa4) = -(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
  uVar2 = param_1 + 0x8cU & 3;
  uVar4 = *(uint *)(param_1 + 0x8cU & 0xfffffffc);
  uVar7 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
  uVar2 = param_1 + 0x78U & 3;
  uVar4 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
  VecFx32_AddScale1((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) +
                    ((uVar7 << 0xe) >> 0xc | (uVar7 >> 0x12) << 0x14),param_1 + 0x9c,param_1 + 0x50,
                    param_1 + 0xa8);
  uVar2 = param_1 + 0xe8U & 3;
  uVar5 = *(uint *)(param_1 + 0xe8U & 0xfffffffc);
  uVar4 = param_1 + 0x8cU & 3;
  uVar7 = *(uint *)(param_1 + 0x8cU & 0xfffffffc);
  lVar3 = (longlong)(int)(uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) *
          (longlong)(int)(uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20);
  VecFx32_AddScale1((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14,param_1 + 0x38,
                    param_1 + 0xa8,(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) + 0x50);
  return;
}

