/* Decompiled C draft; module arm9; ROM address 020ef8c4. No matching claim. */
#include "types.h"
#include "deps/020ef8c4_func_020ef8c4.h"

void func_020ef8c4(int param_1)

{
  uint uVar1;
  longlong lVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar8;
  uint uVar7;
  
  uVar1 = param_1 + 0x14U & 3;
  uVar6 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  uVar7 = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
  *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0x4c);
  uVar1 = param_1 + 0x44U & 3;
  uVar6 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  *(uint *)(param_1 + 0x9c) = -(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20);
  uVar1 = param_1 + 0x48U & 3;
  uVar6 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(param_1 + 0xa0) = -(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20);
  uVar1 = param_1 + 0x4cU & 3;
  uVar6 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  *(uint *)(param_1 + 0xa4) = -(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20);
  uVar1 = param_1 + 0x8cU & 3;
  uVar6 = *(uint *)(param_1 + 0x8cU & 0xfffffffc);
  uVar8 = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x78U & 3;
  uVar6 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
  VecFx32_AddScale1((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) +
                    ((uVar8 << 0xe) >> 0xc | (uVar8 >> 0x12) << 0x14),param_1 + 0x9c,param_1 + 0x50,
                    (int *)(uintptr_t)(param_1 + 0xa8));
  uVar1 = param_1 + 0xe8U & 3;
  uVar4 = *(uint *)(param_1 + 0xe8U & 0xfffffffc);
  uVar6 = param_1 + 0x8cU & 3;
  uVar8 = *(uint *)(param_1 + 0x8cU & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) *
          (longlong)(int)(uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20);
  VecFx32_AddScale1((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14,param_1 + 0x38,
                    param_1 + 0xa8,(int *)(uintptr_t)(uVar7 + 0x50));
  uVar3 = *(undefined4 *)(param_1 + 0x3c);
  uVar5 = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(uVar7 + 0xa0) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(uVar7 + 0xa4) = uVar3;
  *(undefined4 *)(uVar7 + 0xa8) = uVar5;
  uVar1 = param_1 + 0x9cU & 3;
  uVar6 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
  *(uint *)(uVar7 + 0xac) = -(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20);
  uVar1 = param_1 + 0xa0U & 3;
  uVar6 = *(uint *)(param_1 + 0xa0U & 0xfffffffc);
  *(uint *)(uVar7 + 0xb0) = -(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20);
  uVar1 = param_1 + 0xa4U & 3;
  uVar6 = *(uint *)(param_1 + 0xa4U & 0xfffffffc);
  *(uint *)(uVar7 + 0xb4) = -(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20);
  Vector3_Cross((uint)(uintptr_t)((undefined4 *)(uVar7 + 0xa0)),uVar7 + 0xac,(uint *)(uintptr_t)(uVar7 + 0x94));
  return;
}

