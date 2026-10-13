/* Decompiled C draft; module arm9; ROM address 02076ed4. No matching claim. */
#include "types.h"
#include "deps/02076ed4_StructHD_SomeFn_10.h"

void StructHD_SomeFn_10(undefined4 *param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 auStack_44 [12];
  int local_38;
  int local_34;
  int local_30;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint uVar5;
  
  local_2c = *puRam02077058;
  uStack_28 = puRam02077058[1];
  uStack_24 = puRam02077058[2];
  VecFx32_Subtract(param_1 + 6,param_1 + 9,&local_38);
  lVar1 = (longlong)local_30 * (longlong)local_30 +
          (longlong)local_38 * (longlong)local_38 + (longlong)local_34 * (longlong)local_34;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    Vector3_MaybeNormalize(&local_38,&local_38);
  }
  param_1[0x57] = local_38;
  param_1[0x58] = local_34;
  param_1[0x59] = local_30;
  Vector3_Cross(&local_2c,&local_38,auStack_44);
  Vector3_Cross(&local_38,auStack_44,param_1);
  if (((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 == 0 &&
        *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 == 0) &&
      (uVar5 = (uint)(param_1 + 1) & 3, uVar2 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc),
      uVar2 >> uVar5 * 8 == 0 && uVar2 << uVar5 * -8 + 0x20 == 0)) &&
     (uVar5 = (uint)(param_1 + 2) & 3, uVar2 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc),
     uVar2 >> uVar5 * 8 == 0 && uVar2 << uVar5 * -8 + 0x20 == 0)) {
    *param_1 = 0x1000;
    param_1[1] = 0x1000;
    param_1[2] = 0x1000;
    uVar5 = (uint)(param_1 + 1) & 3;
    uVar2 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
    uVar3 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
    uVar2 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
            *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
    uVar5 = (uint)(param_1 + 2) & 3;
    uVar4 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    lVar1 = (longlong)(int)uVar5 * (longlong)(int)uVar5 +
            (longlong)(int)uVar2 * (longlong)(int)uVar2 +
            (longlong)(int)uVar3 * (longlong)(int)uVar3;
    if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
      Vector3_MaybeNormalize(param_1,param_1);
    }
  }
  *puRam0207705c = 2;
  uVar5 = (uint)(param_1 + 9) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 9) & 0xfffffffc);
  local_20 = (int)(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) >> 4;
  uVar5 = (uint)(param_1 + 10) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 10) & 0xfffffffc);
  uVar2 = (uint)(param_1 + 0x5e) & 3;
  uVar3 = *(uint *)((uint)(param_1 + 0x5e) & 0xfffffffc);
  local_1c = (int)((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) +
                  (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20)) >> 4;
  uVar5 = (uint)(param_1 + 0xb) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 0xb) & 0xfffffffc);
  local_18 = (int)(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) >> 4;
  uVar5 = (uint)(param_1 + 6) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
  local_14 = (int)(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) >> 4;
  uVar5 = (uint)(param_1 + 7) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 7) & 0xfffffffc);
  local_10 = (int)(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) >> 4;
  uVar5 = (uint)(param_1 + 8) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
  local_c = (int)(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) >> 4;
  G3i_LookAt_(&local_20,param_1,&local_14,1,param_1 + 0xc);
  return;
}

