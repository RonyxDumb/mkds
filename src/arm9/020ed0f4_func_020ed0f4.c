/* Decompiled C draft; module arm9; ROM address 020ed0f4. No matching claim. */
#include "types.h"
#include "deps/020ed0f4_func_020ed0f4.h"

undefined4 func_020ed0f4(int param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  int local_58;
  int local_54;
  int local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  undefined1 auStack_40 [12];
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 auStack_28 [12];
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uVar3 = param_1 + 0x168U & 3;
  uVar2 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
  puVar5 = (undefined4 *)(param_1 + 0x50);
  uVar3 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x18;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar6 = param_1 + 0x130;
  VecFx32_Subtract(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20,(uint)(uintptr_t)(puVar5),&local_58);
  lVar1 = (longlong)local_50 * (longlong)local_50 +
          (longlong)local_58 * (longlong)local_58 + (longlong)local_54 * (longlong)local_54;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    Vector3_MaybeNormalize((uint)(uintptr_t)(&local_58),&local_4c);
  }
  iVar4 = VecFx32_CrossProduct_0(uVar6,(uint)(uintptr_t)(&local_4c));
  if ((iVar4 <= iRam020ed264) &&
     (uVar3 = param_1 + 0x158U & 3, uVar2 = *(uint *)(param_1 + 0x158U & 0xfffffffc),
     uVar2 >> uVar3 * 8 == 0 && uVar2 << uVar3 * -8 + 0x20 == 0)) {
    return 0;
  }
  local_58 = local_58 >> 2;
  local_54 = local_54 >> 2;
  local_50 = local_50 >> 2;
  iVar4 = Vector3_DotProduct(uVar6,(uint)(uintptr_t)(&local_58));
  lVar1 = (longlong)
          (int)(*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
               *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) * (longlong)iVar4;
  local_4c = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar3 = param_1 + 0x134U & 3;
  uVar2 = *(uint *)(param_1 + 0x134U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) * (longlong)iVar4;
  local_48 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar3 = param_1 + 0x138U & 3;
  uVar2 = *(uint *)(param_1 + 0x138U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) * (longlong)iVar4;
  local_44 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  VecFx32_Add((uint)(uintptr_t)(&local_58),(uint)(uintptr_t)(&local_4c),&local_58);
  VecFx32_Subtract((uint)(uintptr_t)(puVar5),(uint)(uintptr_t)(&local_4c),(int *)(void *)(auStack_40));
  local_34 = *puVar5;
  uStack_30 = *(undefined4 *)(param_1 + 0x54);
  uStack_2c = *(undefined4 *)(param_1 + 0x58);
  VecFx32_Add((uint)(uintptr_t)(puVar5),(uint)(uintptr_t)(&local_58),(int *)(void *)(auStack_28));
  uVar3 = param_1 + 0x168U & 3;
  uVar2 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
  uVar3 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x18;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  puVar5 = (undefined4 *)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  local_1c = *puVar5;
  uStack_18 = puVar5[1];
  uStack_14 = puVar5[2];
  uVar3 = param_1 + 300U & 3;
  uVar2 = *(uint *)(param_1 + 300U & 0xfffffffc);
  func_020f4020(param_1 + 0x170,(undefined4 *)(void *)(auStack_40),uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
  return 1;
}

