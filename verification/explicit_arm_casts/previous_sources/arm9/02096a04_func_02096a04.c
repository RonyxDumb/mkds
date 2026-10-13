/* Decompiled C draft; module arm9; ROM address 02096a04. No matching claim. */
#include "types.h"
#include "deps/02096a04_func_02096a04.h"

void func_02096a04(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined1 auStack_7c [36];
  undefined4 local_58;
  int local_54;
  undefined4 local_50;
  undefined4 local_4c;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  
  local_88 = 0x1e;
  func_01ff9048(0x14,&local_88,1);
  func_01ff9048(0x11,0,0);
  uVar6 = param_2 + 0xa8U & 3;
  uVar4 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
  local_54 = (int)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) >> 4;
  local_58 = 0;
  local_50 = 0;
  func_01ff9048(0x1c,&local_58,3);
  uVar5 = MaybeGetBBMtxAtPosition(param_2 + 4);
  func_01ff9048(0x19,uVar5,0xc);
  StructMapObject_SomeFn_9
            (param_1,*(uint *)(DAT_02096d58 & 0xfffffffc) >> (DAT_02096d58 & 3) * 8 |
                     *(uint *)(DAT_02096d58 & 0xfffffffc) << (DAT_02096d58 & 3) * -8 + 0x20);
  DrawObject2D3D(param_1,*(uint *)(DAT_02096d58 & 0xfffffffc) >> (DAT_02096d58 & 3) * 8 |
                         *(uint *)(DAT_02096d58 & 0xfffffffc) << (DAT_02096d58 & 3) * -8 + 0x20,
                 param_2);
  local_84 = 1;
  func_01ff9048(0x12,&local_84);
  uVar6 = param_2 + 0xb0U & 3;
  uVar4 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
  switch(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) {
  case 0:
    goto switchD_02096abc_default;
  case 1:
    break;
  case 2:
    break;
  case 3:
    goto switchD_02096abc_default;
  case 4:
    goto LAB_02096af8;
  case 5:
    goto LAB_02096af8;
  case 6:
    break;
  case 7:
LAB_02096af8:
    StructMapObject_SetNsbtpFrame
              (*(uint *)(DAT_02096d5c & 0xfffffffc) >> (DAT_02096d5c & 3) * 8 |
               *(uint *)(DAT_02096d5c & 0xfffffffc) << (DAT_02096d5c & 3) * -8 + 0x20,1);
  default:
    goto switchD_02096abc_default;
  }
  StructMapObject_SetNsbtpFrame
            (*(uint *)(DAT_02096d5c & 0xfffffffc) >> (DAT_02096d5c & 3) * 8 |
             *(uint *)(DAT_02096d5c & 0xfffffffc) << (DAT_02096d5c & 3) * -8 + 0x20,0);
switchD_02096abc_default:
  uVar6 = param_2 + 0xb0U & 3;
  uVar4 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
  if (uVar4 >> uVar6 * 8 != 0 || uVar4 << uVar6 * -8 + 0x20 != 0) {
    func_01ff9048(0x11,0,0);
    uVar6 = param_2 + 0x104U & 3;
    uVar4 = *(uint *)(param_2 + 0x104U & 0xfffffffc);
    if (uVar4 >> uVar6 * 8 == 0 && uVar4 << uVar6 * -8 + 0x20 == 0) {
      uVar6 = param_2 + 0xa4U & 3;
      uVar4 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
      local_3c = (int)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) >> 4;
      local_40 = 0;
      local_38 = 0;
      func_01ff9048(0x1c,&local_40,3);
    }
    else {
      uVar6 = param_2 + 0xb8U & 3;
      uVar4 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
      local_48 = (int)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) >> 4;
      local_4c = 0;
      local_44 = 0;
      func_01ff9048(0x1c,&local_4c,3);
    }
    uVar5 = MaybeGetBBMtxAtPosition(param_2 + 4);
    func_01ff9048(0x19,uVar5,0xc);
    StructMapObject_SomeFn_9
              (param_1,*(uint *)(DAT_02096d5c & 0xfffffffc) >> (DAT_02096d5c & 3) * 8 |
                       *(uint *)(DAT_02096d5c & 0xfffffffc) << (DAT_02096d5c & 3) * -8 + 0x20);
    DrawObject2D3D(param_1,*(uint *)(DAT_02096d5c & 0xfffffffc) >> (DAT_02096d5c & 3) * 8 |
                           *(uint *)(DAT_02096d5c & 0xfffffffc) << (DAT_02096d5c & 3) * -8 + 0x20,
                   param_2);
    local_80 = 1;
    func_01ff9048(0x12,&local_80);
  }
  uVar6 = param_2 + 0x104U & 3;
  uVar4 = *(uint *)(param_2 + 0x104U & 0xfffffffc);
  uVar6 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
  if ((uVar6 == 1) || (uVar6 == 2)) {
    uVar6 = param_2 + 0xe8U & 3;
    uVar8 = *(uint *)(param_2 + 0xe8U & 0xfffffffc);
    uVar4 = param_2 + 200U & 3;
    uVar7 = *(uint *)(param_2 + 200U & 0xfffffffc);
    iVar1 = (int)((uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) & 0xffff) >> 4;
    uVar10 = (uint)*(short *)(DAT_02096d60 + iVar1 * 4);
    lVar3 = (ulonglong)uVar10 * 0x7000;
    uVar8 = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
    uVar6 = param_2 + 0xb4U & 3;
    uVar9 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    if ((int)uVar8 < 1) {
      uVar8 = -uVar8;
    }
    uVar5 = MaybeGetBBMtxAtPosition(param_2 + 4);
    func_01ff9048(0x19,uVar5,0xc);
    local_30 = (int)((uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) + uVar8) >> 4;
    local_34 = 0;
    local_2c = 0;
    func_01ff9048(0x1c,&local_34,3);
    iVar2 = (int)((uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) & 0xffff) >> 4;
    MTX_RotY33__from_thumb
              (auStack_7c,(int)*(short *)(DAT_02096d60 + iVar2 * 4),
               (int)*(short *)(DAT_02096d60 + (iVar2 * 2 + 1) * 2));
    func_01ff9048(0x1a,auStack_7c,9);
    MTX_RotZ33__from_thumb(auStack_7c,uVar10,(int)*(short *)(DAT_02096d60 + (iVar1 * 2 + 1) * 2));
    func_01ff9048(0x1a,auStack_7c,9);
  }
  else {
    uVar6 = param_2 + 0xa0U & 3;
    uVar4 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
    local_24 = (int)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) >> 4;
    local_28 = 0;
    local_20 = 0;
    func_01ff9048(0x1c,&local_28,3);
    uVar5 = MaybeGetBBMtxAtPosition(param_2 + 4);
    func_01ff9048(0x19,uVar5,0xc);
  }
  StructMapObject_SomeFn_9
            (param_1,*(uint *)(DAT_02096d64 & 0xfffffffc) >> (DAT_02096d64 & 3) * 8 |
                     *(uint *)(DAT_02096d64 & 0xfffffffc) << (DAT_02096d64 & 3) * -8 + 0x20);
  DrawObject2D3D(param_1,*(uint *)(DAT_02096d64 & 0xfffffffc) >> (DAT_02096d64 & 3) * 8 |
                         *(uint *)(DAT_02096d64 & 0xfffffffc) << (DAT_02096d64 & 3) * -8 + 0x20,
                 param_2);
  return;
}

