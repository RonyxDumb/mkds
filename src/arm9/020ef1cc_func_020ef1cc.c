/* Decompiled C draft; module arm9; ROM address 020ef1cc. No matching claim. */
#include "types.h"
#include "deps/020ef1cc_func_020ef1cc.h"

void func_020ef1cc(int param_1)

{
  longlong lVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  
  uVar4 = param_1 + 0x14U & 3;
  uVar12 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0x4c);
  uVar6 = param_1 + 0x44U & 3;
  uVar3 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  *(uint *)(param_1 + 0x9c) = -(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20);
  uVar6 = param_1 + 0x48U & 3;
  uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(param_1 + 0xa0) = -(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20);
  uVar6 = param_1 + 0x4cU & 3;
  uVar3 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  *(uint *)(param_1 + 0xa4) = -(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20);
  uVar6 = param_1 + 0x8cU & 3;
  uVar3 = *(uint *)(param_1 + 0x8cU & 0xfffffffc);
  uVar3 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  uVar6 = param_1 + 0x78U & 3;
  uVar11 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
  VecFx32_AddScale1((uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) +
                    ((uVar3 << 0xe) >> 0xc | (uVar3 >> 0x12) << 0x14),param_1 + 0x9c,param_1 + 0x50,
                    (int *)(uintptr_t)(param_1 + 0xa8));
  uVar6 = param_1 + 0xe8U & 3;
  uVar8 = *(uint *)(param_1 + 0xe8U & 0xfffffffc);
  uVar3 = param_1 + 0x8cU & 3;
  uVar11 = *(uint *)(param_1 + 0x8cU & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) *
          (longlong)(int)(uVar11 >> uVar3 * 8 | uVar11 << uVar3 * -8 + 0x20);
  VecFx32_AddScale1((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14,param_1 + 0x38,
                    param_1 + 0xa8,(int *)(uintptr_t)((uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20) + 0x50));
  uVar2 = uRam020ef338;
  uVar4 = param_1 + 0x18U & 3;
  uVar6 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  uVar3 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
  uVar4 = param_1 + 0x14U & 3;
  uVar6 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  uVar4 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
  iVar10 = 0;
  uVar7 = *(undefined4 *)(uVar4 + 0x54);
  uVar9 = *(undefined4 *)(uVar4 + 0x58);
  *(undefined4 *)(uVar3 + 0x50) = *(undefined4 *)(uVar4 + 0x50);
  *(undefined4 *)(uVar3 + 0x54) = uVar7;
  *(undefined4 *)(uVar3 + 0x58) = uVar9;
  uVar4 = param_1 + 0x1cU & 3;
  uVar6 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  uVar3 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
  uVar4 = param_1 + 0x18U & 3;
  uVar6 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  uVar4 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
  uVar7 = *(undefined4 *)(uVar4 + 0x54);
  uVar9 = *(undefined4 *)(uVar4 + 0x58);
  *(undefined4 *)(uVar3 + 0x50) = *(undefined4 *)(uVar4 + 0x50);
  *(undefined4 *)(uVar3 + 0x54) = uVar7;
  *(undefined4 *)(uVar3 + 0x58) = uVar9;
  *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_1 + 0xa8);
  *(undefined4 *)(param_1 + 0xb8) = *(undefined4 *)(param_1 + 0xac);
  *(undefined4 *)(param_1 + 0xbc) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined4 *)(param_1 + 0xc0) = *(undefined4 *)(param_1 + 0xb4);
  *(undefined4 *)(param_1 + 0xc4) = *(undefined4 *)(param_1 + 0xb8);
  *(undefined4 *)(param_1 + 200) = *(undefined4 *)(param_1 + 0xbc);
  *(undefined4 *)(param_1 + 0xcc) = uVar2;
  uVar4 = param_1 + 0xccU & 3;
  uVar6 = *(uint *)(param_1 + 0xccU & 0xfffffffc);
  *(uint *)(param_1 + 0xd0) = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
  uVar4 = param_1 + 0xd0U & 3;
  uVar6 = *(uint *)(param_1 + 0xd0U & 0xfffffffc);
  *(uint *)(param_1 + 0xd4) = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
  *(undefined4 *)(param_1 + 0xd8) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(param_1 + 0xdc) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(param_1 + 0xe0) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(param_1 + 0x16c) = 0;
  do {
    iVar5 = param_1 + iVar10 * 4;
    *(undefined4 *)(iVar5 + 0xec) = 0;
    iVar10 = iVar10 + 1;
    *(undefined4 *)(iVar5 + 300) = 0;
  } while (iVar10 < 0x10);
  if ((uint)*(ushort *)(param_1 + 0x28) ==
      (int)*(char *)((*(uint *)(uRam020ef33c & 0xfffffffc) >> (uRam020ef33c & 3) * 8 |
                     *(uint *)(uRam020ef33c & 0xfffffffc) << (uRam020ef33c & 3) * -8 + 0x20) + 0x62)
     ) {
    uVar4 = param_1 + 0xcU & 3;
    uVar6 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    uVar4 = (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) + 0x1fc;
    uVar6 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    func_020719bc(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20,0xe7);
    return;
  }
  return;
}

