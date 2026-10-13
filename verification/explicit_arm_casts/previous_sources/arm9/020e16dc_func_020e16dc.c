/* Decompiled C draft; module arm9; ROM address 020e16dc. No matching claim. */
#include "types.h"
#include "deps/020e16dc_func_020e16dc.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4
func_020e16dc(uint param_1,int param_2,int param_3,ushort param_4,ushort param_5,ushort param_6,
             undefined2 *param_7,ushort param_8,int param_9,int param_10,int param_11,
             undefined4 param_12,uint param_13,uint *param_14,uint *param_15,uint *param_16,
             uint *param_17,undefined4 param_18)

{
  longlong lVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  bool bVar5;
  uint uVar6;
  uint uVar7;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  uint uVar8;
  
  bVar5 = false;
  if ((param_8 & 0x60) == 0) {
    bVar2 = false;
    bVar3 = true;
    if (param_9 != 0) {
      if ((param_4 & param_5) == 0) {
        uVar8 = param_13 + 4 & 3;
        uVar7 = *(uint *)(param_13 + 4 & 0xfffffffc);
        uVar8 = -(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20);
      }
      else {
        uVar8 = param_13 + 4 & 3;
        uVar7 = *(uint *)(param_13 + 4 & 0xfffffffc);
        uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
      }
      uVar7 = param_11 + 0x120U & 3;
      uVar6 = *(uint *)(param_11 + 0x120U & 0xfffffffc);
      if ((int)(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) < (int)uVar8) {
        bVar2 = true;
      }
    }
    if (!bVar2) {
      bVar2 = false;
      if (param_10 != 0) {
        if ((param_4 & param_6) == 0) {
          uVar8 = (uint)(param_14 + 1) & 3;
          uVar7 = *(uint *)((uint)(param_14 + 1) & 0xfffffffc);
          uVar8 = -(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20);
        }
        else {
          uVar8 = (uint)(param_14 + 1) & 3;
          uVar7 = *(uint *)((uint)(param_14 + 1) & 0xfffffffc);
          uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
        }
        uVar7 = param_11 + 0x120U & 3;
        uVar6 = *(uint *)(param_11 + 0x120U & 0xfffffffc);
        if ((int)(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) < (int)uVar8) {
          bVar2 = true;
        }
      }
      if (!bVar2) {
        bVar3 = false;
      }
    }
    if (bVar3) {
      bVar5 = true;
    }
  }
  lVar1 = (longlong)
          (int)(*(uint *)(param_13 & 0xfffffffc) >> (param_13 & 3) * 8 |
               *(uint *)(param_13 & 0xfffffffc) << (param_13 & 3) * -8 + 0x20) * (longlong)param_2;
  local_4c = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar8 = param_13 + 4 & 3;
  uVar7 = *(uint *)(param_13 + 4 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) * (longlong)param_2;
  local_48 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar8 = param_13 + 8 & 3;
  uVar7 = *(uint *)(param_13 + 8 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) * (longlong)param_2;
  local_44 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  lVar1 = (longlong)
          (int)(*(uint *)((uint)param_14 & 0xfffffffc) >> ((uint)param_14 & 3) * 8 |
               *(uint *)((uint)param_14 & 0xfffffffc) << ((uint)param_14 & 3) * -8 + 0x20) *
          (longlong)param_3;
  local_40 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar8 = (uint)(param_14 + 1) & 3;
  uVar7 = *(uint *)((uint)(param_14 + 1) & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) * (longlong)param_3;
  local_3c = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar8 = (uint)(param_14 + 2) & 3;
  uVar7 = *(uint *)((uint)(param_14 + 2) & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) * (longlong)param_3;
  local_38 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  VecFx32_Add(&local_4c,&local_40,&local_4c);
  local_4c = local_4c << 10;
  local_48 = local_48 << 10;
  local_44 = local_44 << 10;
  iVar4 = func_020d70ac(&local_4c,&uStack_34);
  if (iVar4 == param_1 * 0x400 ||
      (int)(iVar4 + param_1 * -0x400) < 0 != SBORROW4(iVar4,param_1 * 0x400)) {
    if (iVar4 == 0) {
      uStack_34 = *param_14;
      uStack_30 = param_14[1];
      uStack_2c = param_14[2];
      local_40 = (uint)((longlong)(int)uStack_34 * (longlong)(int)param_1) >> 0xc |
                 (int)((ulonglong)((longlong)(int)uStack_34 * (longlong)(int)param_1) >> 0x20) <<
                 0x14;
      local_3c = (uint)((longlong)(int)uStack_30 * (longlong)(int)param_1) >> 0xc |
                 (int)((ulonglong)((longlong)(int)uStack_30 * (longlong)(int)param_1) >> 0x20) <<
                 0x14;
      local_38 = (uint)((longlong)(int)uStack_2c * (longlong)(int)param_1) >> 0xc |
                 (int)((ulonglong)((longlong)(int)uStack_2c * (longlong)(int)param_1) >> 0x20) <<
                 0x14;
    }
    else {
      local_40 = (uint)((longlong)(int)uStack_34 * (longlong)(int)param_1) >> 0xc |
                 (int)((ulonglong)((longlong)(int)uStack_34 * (longlong)(int)param_1) >> 0x20) <<
                 0x14;
      local_3c = (uint)((longlong)(int)uStack_30 * (longlong)(int)param_1) >> 0xc |
                 (int)((ulonglong)((longlong)(int)uStack_30 * (longlong)(int)param_1) >> 0x20) <<
                 0x14;
      local_38 = (uint)((longlong)(int)uStack_2c * (longlong)(int)param_1) >> 0xc |
                 (int)((ulonglong)((longlong)(int)uStack_2c * (longlong)(int)param_1) >> 0x20) <<
                 0x14;
      local_4c = (int)local_4c >> 10;
      local_44 = (int)local_44 >> 10;
      local_48 = (int)local_48 >> 10;
      VecFx32_Subtract(&local_40,&local_4c,&local_40);
      param_1 = VecFx32_Norm(&local_40);
    }
    if (bVar5) {
      uVar8 = param_11 + 0x11cU & 3;
      uVar7 = *(uint *)(param_11 + 0x11cU & 0xfffffffc);
      if ((uVar7 >> uVar8 * 8 == 0 && uVar7 << uVar8 * -8 + 0x20 == 0) || ((param_4 & 8) == 0)) {
        *param_7 = 0;
        param_16 = param_15;
      }
      else {
        *param_7 = 0x1e;
      }
    }
    else {
      *param_7 = 8;
    }
    uVar8 = (uint)(param_16 + 6) & 3;
    uVar7 = *(uint *)((uint)(param_16 + 6) & 0xfffffffc);
    if ((int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) <= (int)param_1) {
      param_16[6] = param_1;
      param_16[7] = uStack_34;
      param_16[8] = uStack_30;
      param_16[9] = uStack_2c;
    }
    local_40 = local_40 * 0x400;
    local_3c = local_3c << 10;
    local_38 = local_38 << 10;
    if ((int)(*(uint *)((uint)param_16 & 0xfffffffc) >> ((uint)param_16 & 3) * 8 |
             *(uint *)((uint)param_16 & 0xfffffffc) << ((uint)param_16 & 3) * -8 + 0x20) <
        (int)local_40) {
      *param_16 = local_40;
    }
    else {
      uVar8 = (uint)(param_16 + 3) & 3;
      uVar7 = *(uint *)((uint)(param_16 + 3) & 0xfffffffc);
      if ((int)local_40 < (int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20)) {
        param_16[3] = local_40;
      }
    }
    uVar8 = (uint)(param_16 + 1) & 3;
    uVar7 = *(uint *)((uint)(param_16 + 1) & 0xfffffffc);
    if ((int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) < (int)local_3c) {
      param_16[1] = local_3c;
    }
    else {
      uVar8 = (uint)(param_16 + 4) & 3;
      uVar7 = *(uint *)((uint)(param_16 + 4) & 0xfffffffc);
      if ((int)local_3c < (int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20)) {
        param_16[4] = local_3c;
      }
    }
    uVar8 = (uint)(param_16 + 2) & 3;
    uVar7 = *(uint *)((uint)(param_16 + 2) & 0xfffffffc);
    if ((int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) < (int)local_38) {
      param_16[2] = local_38;
    }
    else {
      uVar8 = (uint)(param_16 + 5) & 3;
      uVar7 = *(uint *)((uint)(param_16 + 5) & 0xfffffffc);
      if ((int)local_38 < (int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20)) {
        param_16[5] = local_38;
      }
    }
    if (param_17 != (uint *)0x0) {
      local_4c = -local_4c;
      local_48 = -local_48;
      local_44 = -local_44;
      uVar8 = (uint)(param_17 + 1) & 3;
      uVar7 = *(uint *)((uint)(param_17 + 1) & 0xfffffffc);
      if ((int)local_48 < (int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20)) {
        *param_17 = local_4c;
        param_17[1] = local_48;
        param_17[2] = local_44;
      }
    }
    if (bVar5) {
      func_020e0680(param_11,param_12,&uStack_34,param_18);
    }
    return 1;
  }
  return 0;
}

