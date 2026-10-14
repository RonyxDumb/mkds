/* Decompiled C draft; module arm9; ROM address 020821cc. No matching claim. */
#include "types.h"
#include "deps/020821cc_func_020821cc.h"

void func_020821cc(int param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int aiStack_30 [3];
  int aiStack_24 [2];
  int iStack_1c;
  
  if (param_2 == 0) {
    iVar2 = GetGlobalHD5();
    iVar3 = GetDriverEntry((int)*(char *)((*(uint *)(uRam02082360 & 0xfffffffc) >>
                                           (uRam02082360 & 3) * 8 |
                                          *(uint *)(uRam02082360 & 0xfffffffc) <<
                                          (uRam02082360 & 3) * -8 + 0x20) + 0x62));
    aiStack_30[0] = *(int *)(iVar2 + 0x15c);
    aiStack_30[2] = *(int *)(iVar2 + 0x164);
    uVar7 = iVar3 + 0x2a4U & 3;
    uVar4 = *(uint *)(iVar3 + 0x2a4U & 0xfffffffc);
    iVar9 = 0;
    lVar1 = (longlong)(int)(uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) *
            (longlong)
            (int)(*(uint *)(uRam02082364 & 0xfffffffc) >> (uRam02082364 & 3) * 8 |
                 *(uint *)(uRam02082364 & 0xfffffffc) << (uRam02082364 & 3) * -8 + 0x20) + 0x800;
    uVar8 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
    aiStack_30[1] = 0;
    uVar7 = iVar3 + 0x44U & 3;
    uVar4 = *(uint *)(iVar3 + 0x44U & 0xfffffffc);
    if (0x1000 < (int)uVar8) {
      uVar8 = 0x1000;
    }
    if (((uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) & 0x100) != 0) {
      iVar9 = -0x5800;
    }
    lVar1 = (longlong)aiStack_30[2] * (longlong)aiStack_30[2] +
            (longlong)aiStack_30[0] * (longlong)aiStack_30[0];
    if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
      Vector3_MaybeNormalize((uint)(uintptr_t)(aiStack_30),aiStack_30);
    }
    lVar1 = (longlong)(iVar9 * 3) * (longlong)(int)uVar8 + 0x800;
    VecFx32_AddScale1(((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000) + 0x5800,
                      (uint)(uintptr_t)(aiStack_30),iVar2 + 0x9c,aiStack_24);
    iVar9 = GetDriverEntry((int)*(char *)((*(uint *)(uRam02082360 & 0xfffffffc) >>
                                           (uRam02082360 & 3) * 8 |
                                          *(uint *)(uRam02082360 & 0xfffffffc) <<
                                          (uRam02082360 & 3) * -8 + 0x20) + 0x62));
    uVar7 = iVar9 + 0x508U & 3;
    uVar4 = *(uint *)(iVar9 + 0x508U & 0xfffffffc);
    uVar7 = (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) + 4;
    uVar4 = uVar7 & 3;
    uVar5 = *(uint *)(uVar7 & 0xfffffffc);
    uVar7 = param_1 + 0x20U & 3;
    uVar6 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar7 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 4;
    uVar6 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    *(uint *)(param_1 + 0x28) = aiStack_24[0] + (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20);
    uVar7 = param_1 + 0x20U & 3;
    uVar6 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar7 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 8;
    uVar6 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    *(uint *)(param_1 + 0x2c) =
         ((int)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) >> 4) +
         (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20);
    uVar7 = param_1 + 0x20U & 3;
    uVar4 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar4 = uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20;
    uVar7 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar7 = (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) + 0xc;
    uVar4 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    *(uint *)(param_1 + 0x30) = iStack_1c + (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20);
    *(uint *)(param_1 + 0x58) =
         uVar8 * 0x800 + 0x800 >> 0xc |
         ((((int)uVar8 >> 0x1f) << 0xb | uVar8 >> 0x15) + (uint)(0xfffff7ff < uVar8 * 0x800)) *
         0x100000;
    return;
  }
  return;
}

