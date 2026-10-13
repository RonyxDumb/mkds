/* Decompiled C draft; module arm9; ROM address 02076cd0. No matching claim. */
#include "types.h"
#include "deps/02076cd0_StructHD_SomeLookAt.h"

void StructHD_SomeLookAt(undefined4 *param_1)

{
  longlong lVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int local_44;
  int local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint uVar6;
  
  local_38 = param_1[0x30];
  uStack_34 = param_1[0x31];
  uStack_30 = param_1[0x32];
  local_2c = param_1[9];
  local_28 = param_1[10];
  local_24 = param_1[0xb];
  local_20 = param_1[6];
  local_18 = param_1[8];
  uVar6 = (uint)(param_1 + 0x56) & 3;
  uVar3 = *(uint *)((uint)(param_1 + 0x56) & 0xfffffffc);
  local_1c = param_1[7] + (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20);
  VecFx32_Subtract((uint)(uintptr_t)(&local_20),(uint)(uintptr_t)(&local_2c),&local_44);
  lVar1 = (longlong)local_3c * (longlong)local_3c +
          (longlong)local_44 * (longlong)local_44 + (longlong)local_40 * (longlong)local_40;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    Vector3_MaybeNormalize((uint)(uintptr_t)(&local_44),&local_44);
  }
  param_1[0x57] = local_44;
  param_1[0x58] = local_40;
  param_1[0x59] = local_3c;
  Vector3_Cross((uint)(uintptr_t)(&local_38),(uint)(uintptr_t)(&local_44),param_1 + 3);
  Vector3_Cross((uint)(uintptr_t)(&local_44),(uint)(uintptr_t)(param_1 + 3),param_1);
  if (((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 == 0 &&
        *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 == 0) &&
      (uVar6 = (uint)(param_1 + 1) & 3, uVar3 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc),
      uVar3 >> uVar6 * 8 == 0 && uVar3 << uVar6 * -8 + 0x20 == 0)) &&
     (uVar6 = (uint)(param_1 + 2) & 3, uVar3 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc),
     uVar3 >> uVar6 * 8 == 0 && uVar3 << uVar6 * -8 + 0x20 == 0)) {
    *param_1 = 0x1000;
    param_1[1] = 0x1000;
    param_1[2] = 0x1000;
    uVar6 = (uint)(param_1 + 1) & 3;
    uVar3 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
    uVar4 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
    uVar3 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
            *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
    uVar6 = (uint)(param_1 + 2) & 3;
    uVar5 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    lVar1 = (longlong)(int)uVar6 * (longlong)(int)uVar6 +
            (longlong)(int)uVar3 * (longlong)(int)uVar3 +
            (longlong)(int)uVar4 * (longlong)(int)uVar4;
    if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
      Vector3_MaybeNormalize((uint)(uintptr_t)(param_1),param_1);
    }
  }
  if (*(char *)(param_1 + 0x4c) != '\0') {
    func_02073904((uint)(uintptr_t)(param_1));
    VecFx32_Add((uint)(uintptr_t)(&local_2c),(uint)(uintptr_t)(param_1 + 0x46),&local_2c);
    VecFx32_Add((uint)(uintptr_t)(&local_20),(uint)(uintptr_t)(param_1 + 0x43),&local_20);
    VecFx32_Add((uint)(uintptr_t)(param_1 + 0x49),(uint)(uintptr_t)(&local_20),&local_20);
  }
  puVar2 = puRam02076ed0;
  param_1[0x27] = local_2c >> 4;
  param_1[0x28] = local_28 >> 4;
  param_1[0x29] = local_24 >> 4;
  uVar6 = (uint)(param_1 + 0x28) & 3;
  uVar5 = *(uint *)((uint)(param_1 + 0x28) & 0xfffffffc);
  uVar3 = (uint)(param_1 + 0x5e) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 0x5e) & 0xfffffffc);
  param_1[0x28] =
       (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) +
       ((int)(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) >> 4);
  param_1[0x24] = local_20 >> 4;
  param_1[0x25] = local_1c >> 4;
  param_1[0x26] = local_18 >> 4;
  *puVar2 = 2;
  G3i_LookAt_((uint)(uintptr_t)(param_1 + 0x27),(undefined4)(uintptr_t)(param_1),(uint)(uintptr_t)(param_1 + 0x24),1,param_1 + 0xc);
  return;
}

