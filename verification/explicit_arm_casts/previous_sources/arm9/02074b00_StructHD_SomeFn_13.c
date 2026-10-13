/* Decompiled C draft; module arm9; ROM address 02074b00. No matching claim. */
#include "types.h"
#include "deps/02074b00_StructHD_SomeFn_13.h"

void StructHD_SomeFn_13(int param_1)

{
  short sVar1;
  short sVar2;
  longlong lVar3;
  int iVar4;
  uint uVar5;
  uint uVar7;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 uStack_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  undefined1 auStack_40 [40];
  uint uVar6;
  
  iVar4 = GetDriverEntry(*(undefined2 *)(param_1 + 0x210));
  uVar7 = param_1 + 0x218U & 3;
  uVar5 = *(uint *)(param_1 + 0x218U & 0xfffffffc);
  uVar6 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
  *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0xb8) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0xbc) = *(undefined4 *)(param_1 + 0x20);
  local_64 = *(undefined4 *)(iVar4 + 0x80);
  local_60 = *(undefined4 *)(iVar4 + 0x84);
  uStack_5c = *(undefined4 *)(iVar4 + 0x88);
  uVar7 = uVar6 + 8 & 3;
  uVar5 = *(uint *)(uVar6 + 8 & 0xfffffffc);
  VecFx32_AddScale1(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20,iVar4 + 0x120,
                    (undefined4 *)(iVar4 + 0x80),&local_70);
  local_6c = 0x1f4000;
  local_60 = 0x1f4000;
  local_58 = *(uint *)(iVar4 + 0x138);
  local_50 = *(int *)(iVar4 + 0x140);
  lVar3 = (longlong)(int)local_50 * (longlong)(int)local_50 +
          (longlong)(int)local_58 * (longlong)(int)local_58;
  local_54 = 0;
  if ((int)(uint)((uint)lVar3 < 0x10) <= (int)((ulonglong)lVar3 >> 0x20)) {
    Vector3_MaybeNormalize(&local_58,&local_58);
  }
  uVar7 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
          *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
  local_50 = (uint)((longlong)(int)local_50 * (longlong)(int)uVar7) >> 0xc |
             (int)((ulonglong)((longlong)(int)local_50 * (longlong)(int)uVar7) >> 0x20) << 0x14;
  local_58 = (uint)((longlong)(int)local_58 * (longlong)(int)uVar7) >> 0xc |
             (int)((ulonglong)((longlong)(int)local_58 * (longlong)(int)uVar7) >> 0x20) << 0x14;
  local_54 = (uint)((longlong)(int)local_54 * (longlong)(int)uVar7) >> 0xc |
             (int)((ulonglong)((longlong)(int)local_54 * (longlong)(int)uVar7) >> 0x20) << 0x14;
  VecFx32_Add(&local_70,&local_58,&local_70);
  VecFx32_Add(&local_64,&local_58,&local_64);
  uVar7 = GetSomeTimeOrDuration();
  if (uVar7 < *(ushort *)(uVar6 + 0x46)) {
    *(undefined4 *)(param_1 + 0x18) = local_64;
    *(undefined4 *)(param_1 + 0x1c) = local_60;
    *(undefined4 *)(param_1 + 0x20) = uStack_5c;
    *(undefined4 *)(param_1 + 0x24) = local_70;
    *(undefined4 *)(param_1 + 0x28) = local_6c;
    *(undefined4 *)(param_1 + 0x2c) = uStack_68;
  }
  else {
    uVar7 = param_1 + 0x144U & 3;
    uVar5 = *(uint *)(param_1 + 0x144U & 0xfffffffc);
    if ((int)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) < 0x1000) {
      *(undefined4 *)(param_1 + 0x18) = local_64;
      *(undefined4 *)(param_1 + 0x1c) = local_60;
      *(undefined4 *)(param_1 + 0x20) = uStack_5c;
      *(undefined4 *)(param_1 + 0x24) = local_70;
      *(undefined4 *)(param_1 + 0x28) = local_6c;
      *(undefined4 *)(param_1 + 0x2c) = uStack_68;
      uVar7 = param_1 + 0x144U & 3;
      uVar5 = *(uint *)(param_1 + 0x144U & 0xfffffffc);
      *(uint *)(param_1 + 0x144) = (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) + 0x52;
      VecFx32_Subtract(param_1 + 0x134,(undefined4 *)(param_1 + 0x24),param_1 + 0xa8);
      VecFx32_Subtract(param_1 + 0xb4,param_1 + 0x18,param_1 + 0xb4);
      uVar7 = param_1 + 0x144U & 3;
      uVar5 = *(uint *)(param_1 + 0x144U & 0xfffffffc);
      VecFx32_AddScale1(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20,param_1 + 0xa8,&local_70,
                        param_1 + 0x24);
      uVar7 = param_1 + 0x144U & 3;
      uVar5 = *(uint *)(param_1 + 0x144U & 0xfffffffc);
      VecFx32_AddScale1(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20,param_1 + 0xb4,&local_64,
                        param_1 + 0x18);
    }
  }
  StructHD_SomeLookAt(param_1);
  VecFx32_Subtract(&local_70,&local_64,&local_4c);
  lVar3 = (longlong)(int)local_44 * (longlong)(int)local_44 +
          (longlong)(int)local_4c * (longlong)(int)local_4c +
          (longlong)(int)local_48 * (longlong)(int)local_48;
  if ((int)(uint)((uint)lVar3 < 0x10) <= (int)((ulonglong)lVar3 >> 0x20)) {
    Vector3_MaybeNormalize(&local_4c,&local_4c);
  }
  func_02146f98(auStack_40,uRam02074e64,
                (int)*(short *)(iRam02074e60 + ((int)(uint)*puRam02074e5c >> 4) * 4),
                (int)*(short *)(iRam02074e60 + (((int)(uint)*puRam02074e5c >> 4) * 2 + 1) * 2));
  MTX_MultVec33(&local_4c,auStack_40,&local_4c);
  local_4c = (uint)((ulonglong)uRam02074e68 * (ulonglong)local_4c) >> 0xc |
             (((int)local_4c >> 0x1f) * uRam02074e68 +
             (int)((ulonglong)uRam02074e68 * (ulonglong)local_4c >> 0x20)) * 0x100000;
  local_48 = (uint)((ulonglong)uRam02074e68 * (ulonglong)local_48) >> 0xc |
             (((int)local_48 >> 0x1f) * uRam02074e68 +
             (int)((ulonglong)uRam02074e68 * (ulonglong)local_48 >> 0x20)) * 0x100000;
  local_44 = (uint)((ulonglong)uRam02074e68 * (ulonglong)local_44) >> 0xc |
             (((int)local_44 >> 0x1f) * uRam02074e68 +
             (int)((ulonglong)uRam02074e68 * (ulonglong)local_44 >> 0x20)) * 0x100000;
  SetSomeTDVector(&local_4c);
  uVar7 = param_1 + 0x218U & 3;
  uVar5 = *(uint *)(param_1 + 0x218U & 0xfffffffc);
  uVar7 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
  if (*(short *)(uVar7 + 0x3c) == 0) {
    *(undefined2 *)(param_1 + 0x68) = *(undefined2 *)(uVar7 + 0x32);
    *(undefined2 *)(param_1 + 0x6a) = *(undefined2 *)(uVar7 + 0x34);
    return;
  }
  sVar1 = *(short *)(uVar7 + 0x34);
  sVar2 = *(short *)(uVar7 + 0x3a);
  uVar5 = param_1 + 0x240U & 3;
  uVar6 = *(uint *)(param_1 + 0x240U & 0xfffffffc);
  uVar5 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  *(short *)(param_1 + 0x68) =
       *(short *)(uVar7 + 0x32) +
       (short)(((int)*(short *)(uVar7 + 0x38) - (int)*(short *)(uVar7 + 0x32)) * uVar5 >> 0xc);
  *(short *)(param_1 + 0x6a) = sVar1 + (short)(((int)sVar2 - (int)sVar1) * uVar5 >> 0xc);
  uVar5 = param_1 + 0x240U & 3;
  uVar6 = *(uint *)(param_1 + 0x240U & 0xfffffffc);
  *(uint *)(param_1 + 0x240) =
       (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + (int)*(short *)(uVar7 + 0x3c);
  uVar7 = param_1 + 0x240U & 3;
  uVar5 = *(uint *)(param_1 + 0x240U & 0xfffffffc);
  if (0x1000 < (int)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20)) {
    *(undefined4 *)(param_1 + 0x240) = 0x1000;
  }
  return;
}

