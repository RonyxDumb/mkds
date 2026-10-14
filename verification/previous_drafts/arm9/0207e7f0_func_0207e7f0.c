/* Decompiled C draft; module arm9; ROM address 0207e7f0. No matching claim. */
#include "types.h"
#include "deps/0207e7f0_func_0207e7f0.h"

void func_0207e7f0(uint param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined1 auStack_3c [12];
  undefined1 auStack_30 [12];
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 *puVar4;
  
  uVar3 = param_1 + 8 & 3;
  uVar2 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar3 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x18;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  puVar4 = (undefined4 *)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  local_60 = *puVar4;
  uStack_5c = puVar4[1];
  uStack_58 = puVar4[2];
  uVar3 = param_1 + 8 & 3;
  uVar2 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar3 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x18;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  puVar4 = (undefined4 *)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  local_48 = *puVar4;
  uStack_44 = puVar4[1];
  uStack_40 = puVar4[2];
  local_18 = *puRam0207e940;
  uStack_14 = puRam0207e940[1];
  uStack_10 = puRam0207e940[2];
  local_24 = *puRam0207e940;
  uStack_20 = puRam0207e940[1];
  uStack_1c = puRam0207e940[2];
  Vector3_Cross(param_1 + 0x10,(uint)(uintptr_t)(&local_24),(uint *)(void *)(auStack_3c));
  VecFx32_Subtract((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                   *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x80,(uint)(uintptr_t)(&local_48),
                   (int *)(void *)(auStack_30));
  uVar5 = VecFx32_CrossProduct_0((uint)(uintptr_t)(auStack_30),(uint)(uintptr_t)(auStack_3c));
  uVar3 = param_1 + 8 & 3;
  uVar2 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar3 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x1c;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar5 = FX_Div(uVar5,(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + 0x1000);
  *(undefined4 *)(param_1 + 0x74) = uVar5;
  uVar3 = param_1 + 0x74 & 3;
  uVar2 = *(uint *)(param_1 + 0x74 & 0xfffffffc);
  iVar6 = AbsValue(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
  if (0x1000 < iVar6) {
    uVar3 = param_1 + 0x74 & 3;
    uVar2 = *(uint *)(param_1 + 0x74 & 0xfffffffc);
    if (0 < (int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
      *(undefined4 *)(param_1 + 0x74) = 0x1000;
    }
    *(undefined4 *)(param_1 + 0x74) = 0xfffff000;
  }
  local_54 = local_18;
  uStack_50 = uStack_14;
  uStack_4c = uStack_10;
  Vector3_Cross(param_1 + 0x10,(uint)(uintptr_t)(&local_54),(uint *)(uintptr_t)(param_1 + 0x60));
  uVar3 = param_1 + 8 & 3;
  uVar7 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar2 = param_1 + 0x74 & 3;
  uVar10 = *(uint *)(param_1 + 0x74 & 0xfffffffc);
  uVar3 = (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) + 0x1c;
  uVar7 = uVar3 & 3;
  uVar9 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = param_1 + 0x60 & 3;
  uVar8 = *(uint *)(param_1 + 0x60 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar10 >> uVar2 * 8 | uVar10 << uVar2 * -8 + 0x20) *
          (longlong)(int)(uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20);
  uVar7 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  lVar1 = (longlong)(int)(uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) * (longlong)(int)uVar7;
  *(uint *)(param_1 + 0x60) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar3 = param_1 + 100 & 3;
  uVar2 = *(uint *)(param_1 + 100 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) * (longlong)(int)uVar7;
  *(uint *)(param_1 + 100) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar3 = param_1 + 0x68 & 3;
  uVar2 = *(uint *)(param_1 + 0x68 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) * (longlong)(int)uVar7;
  *(uint *)(param_1 + 0x68) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  VecFx32_Add((uint)(uintptr_t)(&local_60),param_1 + 0x60,(int *)(uintptr_t)(param_1 + 0x44));
  return;
}

