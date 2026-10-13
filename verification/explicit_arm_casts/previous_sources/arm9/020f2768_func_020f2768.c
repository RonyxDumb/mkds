/* Decompiled C draft; module arm9; ROM address 020f2768. No matching claim. */
#include "types.h"
#include "deps/020f2768_func_020f2768.h"

void func_020f2768(int param_1,uint param_2)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar7;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint uVar6;
  
  puVar7 = (undefined4 *)(param_1 + 0x130);
  iVar2 = Vector3_DotProduct(param_2,puVar7);
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
  uVar6 = param_1 + 0x130U & 3;
  uVar3 = *(uint *)(param_1 + 0x130U & 0xfffffffc);
  *(uint *)(param_1 + 0x130) = (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) - local_20;
  uVar6 = param_1 + 0x134U & 3;
  uVar3 = *(uint *)(param_1 + 0x134U & 0xfffffffc);
  *(uint *)(param_1 + 0x134) = (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) - local_1c;
  uVar6 = param_1 + 0x138U & 3;
  uVar3 = *(uint *)(param_1 + 0x138U & 0xfffffffc);
  *(uint *)(param_1 + 0x138) = (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) - local_18;
  uVar6 = param_1 + 0x160U & 3;
  uVar3 = *(uint *)(param_1 + 0x160U & 0xfffffffc);
  if (uVar3 >> uVar6 * 8 != 0 || uVar3 << uVar6 * -8 + 0x20 != 0) {
    VecFx32_Subtract(puVar7,&local_20,puVar7);
  }
  uVar6 = param_1 + 0x134U & 3;
  uVar3 = *(uint *)(param_1 + 0x134U & 0xfffffffc);
  uVar4 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  uVar3 = *(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
          *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20;
  uVar6 = param_1 + 0x138U & 3;
  uVar5 = *(uint *)(param_1 + 0x138U & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  lVar1 = (longlong)(int)uVar6 * (longlong)(int)uVar6 +
          (longlong)(int)uVar3 * (longlong)(int)uVar3 + (longlong)(int)uVar4 * (longlong)(int)uVar4;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    Vector3_MaybeNormalize(puVar7,puVar7);
  }
  *(undefined4 *)(param_1 + 0x13c) = *puVar7;
  *(undefined4 *)(param_1 + 0x140) = *(undefined4 *)(param_1 + 0x134);
  *(undefined4 *)(param_1 + 0x144) = *(undefined4 *)(param_1 + 0x138);
  Vector3_Cross(puVar7,param_1 + 0xf0,param_1 + 0x148);
  uVar6 = param_1 + 0xf4U & 3;
  uVar3 = *(uint *)(param_1 + 0xf4U & 0xfffffffc);
  *(uint *)(param_1 + 0xf4) = (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) + 1;
  DriverContext_MaybeQueuePlaySfx(param_1,0xd5,0x7f,0);
  return;
}

