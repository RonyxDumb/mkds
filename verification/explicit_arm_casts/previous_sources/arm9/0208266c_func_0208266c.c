/* Decompiled C draft; module arm9; ROM address 0208266c. No matching claim. */
#include "types.h"
#include "deps/0208266c_func_0208266c.h"

void func_0208266c(int param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int aiStack_28 [3];
  int aiStack_1c [2];
  int iStack_14;
  
  if (param_2 == 0) {
    iVar2 = GetGlobalHD4();
    aiStack_28[0] = *(int *)(iVar2 + 0x15c);
    aiStack_28[2] = *(int *)(iVar2 + 0x164);
    lVar1 = (longlong)aiStack_28[2] * (longlong)aiStack_28[2] +
            (longlong)aiStack_28[0] * (longlong)aiStack_28[0];
    aiStack_28[1] = 0;
    if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
      Vector3_MaybeNormalize(aiStack_28,aiStack_28);
    }
    VecFx32_AddScale1(*(uint *)(uRam0208274c & 0xfffffffc) >> (uRam0208274c & 3) * 8 |
                      *(uint *)(uRam0208274c & 0xfffffffc) << (uRam0208274c & 3) * -8 + 0x20,
                      aiStack_28,iVar2 + 0x9c,aiStack_1c);
    uVar4 = param_1 + 0x20U & 3;
    uVar3 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar3 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    uVar4 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 4;
    uVar3 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    *(uint *)(param_1 + 0x28) = aiStack_1c[0] + (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20);
    uVar4 = param_1 + 0x20U & 3;
    uVar3 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar3 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    uVar4 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 8;
    uVar3 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    *(uint *)(param_1 + 0x2c) = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 0x1f400;
    uVar4 = param_1 + 0x20U & 3;
    uVar3 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar3 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    uVar4 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0xc;
    uVar3 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    *(uint *)(param_1 + 0x30) = iStack_14 + (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20);
    return;
  }
  return;
}

