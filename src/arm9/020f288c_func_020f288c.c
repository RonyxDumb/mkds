/* Decompiled C draft; module arm9; ROM address 020f288c. No matching claim. */
#include "types.h"
#include "deps/020f288c_func_020f288c.h"

void func_020f288c(int param_1,uint param_2)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar7;
  uint uVar8;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint uVar6;
  
  uVar8 = param_1 + 0x13c;
  puVar7 = (uint *)(param_1 + 0x130);
  iVar2 = Vector3_DotProduct(param_2,uVar8);
  lVar1 = (longlong)
          (int)(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
               *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) * (longlong)iVar2;
  local_20 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar6 = param_2 + 4 & 3;
  uVar3 = *(uint *)(param_2 + 4 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) * (longlong)iVar2;
  local_1c = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar6 = param_2 + 8 & 3;
  uVar3 = *(uint *)(param_2 + 8 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) * (longlong)iVar2;
  local_18 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar6 = param_1 + 0x13cU & 3;
  uVar3 = *(uint *)(param_1 + 0x13cU & 0xfffffffc);
  *(uint *)(param_1 + 0x13c) = (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) - local_20;
  uVar6 = param_1 + 0x140U & 3;
  uVar3 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
  *(uint *)(param_1 + 0x140) = (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) - local_1c;
  uVar6 = param_1 + 0x144U & 3;
  uVar3 = *(uint *)(param_1 + 0x144U & 0xfffffffc);
  *(uint *)(param_1 + 0x144) = (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) - local_18;
  uVar6 = param_1 + 0x160U & 3;
  uVar3 = *(uint *)(param_1 + 0x160U & 0xfffffffc);
  if (uVar3 >> uVar6 * 8 != 0 || uVar3 << uVar6 * -8 + 0x20 != 0) {
    VecFx32_Subtract(uVar8,(uint)(uintptr_t)(&local_20),(int *)(uintptr_t)(uVar8));
  }
  uVar6 = param_1 + 0x140U & 3;
  uVar3 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
  uVar4 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  uVar3 = *(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
          *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20;
  uVar6 = param_1 + 0x144U & 3;
  uVar5 = *(uint *)(param_1 + 0x144U & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  lVar1 = (longlong)(int)uVar6 * (longlong)(int)uVar6 +
          (longlong)(int)uVar3 * (longlong)(int)uVar3 + (longlong)(int)uVar4 * (longlong)(int)uVar4;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    Vector3_MaybeNormalize(uVar8,(int *)(uintptr_t)(uVar8));
  }
  uVar6 = param_1 + 0x144U & 3;
  uVar3 = *(uint *)(param_1 + 0x144U & 0xfffffffc);
  *puVar7 = *(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
            *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20;
  *(undefined4 *)(param_1 + 0x134) = 0;
  *(uint *)(param_1 + 0x138) = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  uVar6 = param_1 + 0x134U & 3;
  uVar3 = *(uint *)(param_1 + 0x134U & 0xfffffffc);
  uVar8 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  uVar3 = *(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
          *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20;
  uVar6 = param_1 + 0x138U & 3;
  uVar4 = *(uint *)(param_1 + 0x138U & 0xfffffffc);
  uVar6 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
  lVar1 = (longlong)(int)uVar6 * (longlong)(int)uVar6 +
          (longlong)(int)uVar3 * (longlong)(int)uVar3 + (longlong)(int)uVar8 * (longlong)(int)uVar8;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    Vector3_MaybeNormalize((uint)(uintptr_t)(puVar7),puVar7);
  }
  Vector3_Cross((uint)(uintptr_t)(puVar7),param_1 + 0xf0,(uint *)(uintptr_t)(param_1 + 0x148));
  DriverContext_MaybeQueuePlaySfx(param_1,0xd5,0x7f,0);
  return;
}

