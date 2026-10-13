/* Decompiled C draft; module arm9; ROM address 020a79c4. No matching claim. */
#include "types.h"
#include "deps/020a79c4_func_020a79c4.h"

void func_020a79c4(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 local_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined1 auStack_b8 [36];
  undefined1 auStack_94 [36];
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  uint uStack_4c;
  uint uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  int iStack_3c;
  undefined4 uStack_38;
  uint uStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  
  local_c4 = 0x1e;
  func_01ff9048(0x14,&local_c4,1);
  uVar4 = param_2 + 0x1fcU & 3;
  uVar2 = *(uint *)(param_2 + 0x1fcU & 0xfffffffc);
  switch(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    iVar5 = 0;
    if (*(short *)(param_2 + 0x1d0) == 0) {
      return;
    }
    iVar7 = param_2 + 0xb0;
    iVar6 = param_2;
    do {
      uStack_c0 = 0x1e;
      func_01ff9048(0x14,&uStack_c0,1);
      uStack_58 = 0;
      uStack_50 = 0;
      uStack_54 = 0xa00;
      func_01ff9048(0x1c,&uStack_58,3);
      uVar3 = func_020e6cf8(iVar7);
      func_01ff9048(0x19,uVar3,0xc);
      if (((*(ushort *)(param_2 + 2) & 0x12) == 0) &&
         (uVar4 = iVar6 + 0xecU & 3, uVar2 = *(uint *)(iVar6 + 0xecU & 0xfffffffc),
         uVar4 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20, uVar4 != 0)) {
        iVar1 = (int)(uVar4 & 0xffff) >> 4;
        MTX_RotZ33__from_thumb
                  (auStack_94,(int)*(short *)(DAT_020a7ea4 + iVar1 * 4),
                   (int)*(short *)(DAT_020a7ea4 + (iVar1 * 2 + 1) * 2));
        func_01ff9048(0x1a,auStack_94,9);
      }
      uVar4 = iVar6 + 200U & 3;
      uVar2 = *(uint *)(iVar6 + 200U & 0xfffffffc);
      uVar4 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
      if ((int)uVar4 < 0x1000) {
        uStack_44 = 0;
        uStack_4c = uVar4;
        uStack_48 = uVar4;
        func_01ff9048(0x1b,&uStack_4c,3);
      }
      if (iVar5 == 3) {
        StructMapObject_SomeFn_9
                  (param_1,*(uint *)(DAT_020a7ea8 & 0xfffffffc) >> (DAT_020a7ea8 & 3) * 8 |
                           *(uint *)(DAT_020a7ea8 & 0xfffffffc) << (DAT_020a7ea8 & 3) * -8 + 0x20);
        DrawObject2D3D(param_1,*(uint *)(DAT_020a7ea8 & 0xfffffffc) >> (DAT_020a7ea8 & 3) * 8 |
                               *(uint *)(DAT_020a7ea8 & 0xfffffffc) <<
                               (DAT_020a7ea8 & 3) * -8 + 0x20,param_2);
      }
      else {
        StructMapObject_SomeFn_9
                  (param_1,*(uint *)(DAT_020a7eac & 0xfffffffc) >> (DAT_020a7eac & 3) * 8 |
                           *(uint *)(DAT_020a7eac & 0xfffffffc) << (DAT_020a7eac & 3) * -8 + 0x20);
        DrawObject2D3D(param_1,*(uint *)(DAT_020a7eac & 0xfffffffc) >> (DAT_020a7eac & 3) * 8 |
                               *(uint *)(DAT_020a7eac & 0xfffffffc) <<
                               (DAT_020a7eac & 3) * -8 + 0x20,param_2);
      }
      iVar7 = iVar7 + 0x48;
      iVar6 = iVar6 + 0x48;
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)(uint)*(ushort *)(param_2 + 0x1d0));
    return;
  case 3:
    iVar5 = 0;
    if (*(short *)(param_2 + 0x1d0) == 0) {
      return;
    }
    iVar7 = 0xa000;
    iVar6 = param_2;
    do {
      uStack_bc = 0x1e;
      func_01ff9048(0x14,&uStack_bc,1);
      uVar3 = func_020e6cf8(param_2 + 4);
      func_01ff9048(0x19,uVar3,0xc);
      uStack_38 = 0x80;
      uStack_40 = 0;
      iStack_3c = iVar7 >> 4;
      func_01ff9048(0x1c,&uStack_40,3);
      uVar4 = iVar6 + 200U & 3;
      uVar2 = *(uint *)(iVar6 + 200U & 0xfffffffc);
      uVar4 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
      if ((int)uVar4 < 0x1000) {
        uStack_2c = 0;
        uStack_34 = uVar4;
        uStack_30 = uVar4;
        func_01ff9048(0x1b,&uStack_34,3);
      }
      if (iVar5 == 3) {
        StructMapObject_SomeFn_9
                  (param_1,*(uint *)(DAT_020a7ea8 & 0xfffffffc) >> (DAT_020a7ea8 & 3) * 8 |
                           *(uint *)(DAT_020a7ea8 & 0xfffffffc) << (DAT_020a7ea8 & 3) * -8 + 0x20);
        DrawObject2D3D(param_1,*(uint *)(DAT_020a7ea8 & 0xfffffffc) >> (DAT_020a7ea8 & 3) * 8 |
                               *(uint *)(DAT_020a7ea8 & 0xfffffffc) <<
                               (DAT_020a7ea8 & 3) * -8 + 0x20,param_2);
      }
      else {
        StructMapObject_SomeFn_9
                  (param_1,*(uint *)(DAT_020a7eac & 0xfffffffc) >> (DAT_020a7eac & 3) * 8 |
                           *(uint *)(DAT_020a7eac & 0xfffffffc) << (DAT_020a7eac & 3) * -8 + 0x20);
        DrawObject2D3D(param_1,*(uint *)(DAT_020a7eac & 0xfffffffc) >> (DAT_020a7eac & 3) * 8 |
                               *(uint *)(DAT_020a7eac & 0xfffffffc) <<
                               (DAT_020a7eac & 3) * -8 + 0x20,param_2);
      }
      iVar7 = iVar7 + 0x14000;
      iVar6 = iVar6 + 0x48;
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)(uint)*(ushort *)(param_2 + 0x1d0));
  default:
    return;
  }
  uVar3 = func_020e6cf8(param_2 + 4);
  func_01ff9048(0x19,uVar3,0xc);
  local_70 = 0;
  local_6c = 0xa00;
  local_68 = 0;
  func_01ff9048(0x1c,&local_70,3);
  iVar6 = 0;
  iVar5 = param_2;
  if (*(short *)(param_2 + 0x1d0) == 0) {
    return;
  }
  do {
    uVar4 = iVar5 + 0xecU & 3;
    uVar2 = *(uint *)(iVar5 + 0xecU & 0xfffffffc);
    uVar4 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
    if (uVar4 != 0) {
      iVar7 = (int)(uVar4 & 0xffff) >> 4;
      MTX_RotZ33__from_thumb
                (auStack_b8,(int)*(short *)(DAT_020a7ea4 + iVar7 * 4),
                 (int)*(short *)(DAT_020a7ea4 + (iVar7 * 2 + 1) * 2));
      func_01ff9048(0x1a,auStack_b8,9);
    }
    if (iVar6 != 0) {
      uStack_64 = 0;
      uStack_60 = 0x1400;
      uStack_5c = 0x80;
      func_01ff9048(0x1c,&uStack_64,3);
    }
    if (iVar6 == 3) {
      StructMapObject_SomeFn_9
                (param_1,*(uint *)(DAT_020a7ea8 & 0xfffffffc) >> (DAT_020a7ea8 & 3) * 8 |
                         *(uint *)(DAT_020a7ea8 & 0xfffffffc) << (DAT_020a7ea8 & 3) * -8 + 0x20);
      DrawObject2D3D(param_1,*(uint *)(DAT_020a7ea8 & 0xfffffffc) >> (DAT_020a7ea8 & 3) * 8 |
                             *(uint *)(DAT_020a7ea8 & 0xfffffffc) << (DAT_020a7ea8 & 3) * -8 + 0x20,
                     param_2);
    }
    else {
      StructMapObject_SomeFn_9
                (param_1,*(uint *)(DAT_020a7eac & 0xfffffffc) >> (DAT_020a7eac & 3) * 8 |
                         *(uint *)(DAT_020a7eac & 0xfffffffc) << (DAT_020a7eac & 3) * -8 + 0x20);
      DrawObject2D3D(param_1,*(uint *)(DAT_020a7eac & 0xfffffffc) >> (DAT_020a7eac & 3) * 8 |
                             *(uint *)(DAT_020a7eac & 0xfffffffc) << (DAT_020a7eac & 3) * -8 + 0x20,
                     param_2);
    }
    iVar6 = iVar6 + 1;
    iVar5 = iVar5 + 0x48;
  } while (iVar6 < (int)(uint)*(ushort *)(param_2 + 0x1d0));
  return;
}

