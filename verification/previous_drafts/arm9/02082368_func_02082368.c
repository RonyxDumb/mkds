/* Decompiled C draft; module arm9; ROM address 02082368. No matching claim. */
#include "types.h"
#include "deps/02082368_func_02082368.h"

void func_02082368(int param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int aiStack_30 [3];
  int aiStack_24 [2];
  int iStack_1c;
  
  if (param_2 == 0) {
    iVar3 = GetGlobalHD5();
    iVar4 = GetDriverEntry((int)*(char *)((*(uint *)(uRam020824c8 & 0xfffffffc) >>
                                           (uRam020824c8 & 3) * 8 |
                                          *(uint *)(uRam020824c8 & 0xfffffffc) <<
                                          (uRam020824c8 & 3) * -8 + 0x20) + 0x62));
    aiStack_30[0] = *(int *)(iVar3 + 0x15c);
    aiStack_30[2] = *(int *)(iVar3 + 0x164);
    lVar1 = (longlong)aiStack_30[2] * (longlong)aiStack_30[2] +
            (longlong)aiStack_30[0] * (longlong)aiStack_30[0];
    aiStack_30[1] = 0;
    if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
      Vector3_MaybeNormalize((uint)(uintptr_t)(aiStack_30),aiStack_30);
    }
    VecFx32_AddScale1(0x5800,(uint)(uintptr_t)(aiStack_30),iVar3 + 0x9c,aiStack_24);
    iVar3 = GetDriverEntry((int)*(char *)((*(uint *)(uRam020824c8 & 0xfffffffc) >>
                                           (uRam020824c8 & 3) * 8 |
                                          *(uint *)(uRam020824c8 & 0xfffffffc) <<
                                          (uRam020824c8 & 3) * -8 + 0x20) + 0x62));
    uVar2 = uRam020824cc;
    uVar8 = iVar3 + 0x508U & 3;
    uVar5 = *(uint *)(iVar3 + 0x508U & 0xfffffffc);
    uVar8 = (uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) + 4;
    uVar5 = uVar8 & 3;
    uVar6 = *(uint *)(uVar8 & 0xfffffffc);
    uVar8 = param_1 + 0x20U & 3;
    uVar7 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar7 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    uVar8 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    uVar8 = (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) + 4;
    uVar7 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    *(uint *)(param_1 + 0x28) = aiStack_24[0] + (uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20);
    uVar8 = param_1 + 0x20U & 3;
    uVar7 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar7 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    uVar8 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    uVar8 = (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) + 8;
    uVar7 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    *(uint *)(param_1 + 0x2c) =
         ((int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) >> 4) +
         (uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20);
    uVar8 = param_1 + 0x20U & 3;
    uVar5 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar5 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar8 = (uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) + 0xc;
    uVar5 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    *(uint *)(param_1 + 0x30) = iStack_1c + (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20);
    uVar8 = iVar4 + 0x2a4U & 3;
    uVar6 = *(uint *)(iVar4 + 0x2a4U & 0xfffffffc);
    uVar5 = uVar2 & 3;
    uVar7 = *(uint *)(uVar2 & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) *
            (longlong)(int)(uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) + 0x800;
    uVar8 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
    if (0x1000 < (int)uVar8) {
      uVar8 = 0x1000;
    }
    uVar8 = 0x1000 - uVar8;
    *(uint *)(param_1 + 0x58) =
         uVar8 * 0x400 + 0x800 >> 0xc |
         ((((int)uVar8 >> 0x1f) << 10 | uVar8 >> 0x16) + (uint)(0xfffff7ff < uVar8 * 0x400)) *
         0x100000;
    return;
  }
  return;
}

