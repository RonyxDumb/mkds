/* Decompiled C draft; module arm9; ROM address 02063cc4. No matching claim. */
#include "types.h"
#include "deps/02063cc4_StructMQRacerEntry_SomeFn_50.h"

void StructMQRacerEntry_SomeFn_50(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined1 auStack_b0 [36];
  undefined1 auStack_8c [36];
  undefined4 uStack_68;
  int iStack_64;
  undefined4 uStack_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  undefined4 local_3c;
  uint local_38 [4];
  uint local_28;
  uint local_24;
  uint local_20 [3];
  uint uVar6;
  
  uVar4 = param_1 + 0x4cU & 3;
  uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  uVar6 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  uVar4 = param_1 + 0x7cU & 3;
  uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  uVar5 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  bVar9 = (uVar6 & 0x10) != 0;
  uVar4 = param_1 + 0x590U & 3;
  uVar8 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
  uVar8 = uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20;
  uVar4 = uVar5 & uRam02064170;
  if ((uVar4 != 0) || ((uVar6 & 0x11800000) != 0)) {
    uVar3 = 0;
    if ((uVar4 == 0) && ((uVar6 & 0x1800000) == 0)) {
      uVar3 = StructMQRacerEntry_SomeFn_68(param_1,0);
    }
    func_0208155c(*(undefined2 *)(param_1 + 0x74),uVar3);
    *(undefined2 *)(param_1 + 900) = 0;
    return;
  }
  if ((uVar5 & uRam02064174) == 0) {
    *(short *)(param_1 + 900) = (short)uRam02064178;
  }
  else {
    *(ushort *)(param_1 + 900) = ~*(ushort *)(param_1 + 900);
    if (*(short *)(param_1 + 900) == 0) {
      return;
    }
  }
  local_d0 = 0x1e;
  func_01ff9048(0x14,(undefined4)(uintptr_t)(&local_d0),1);
  if (bVar9) {
    uVar4 = param_1 + 0x508U & 3;
    uVar5 = *(uint *)(param_1 + 0x508U & 0xfffffffc);
    uVar6 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    *(int *)(param_1 + 0x144) =
         (int)(*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
              *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) >> 4;
    uVar4 = uVar6 + 4 & 3;
    uVar5 = *(uint *)(uVar6 + 4 & 0xfffffffc);
    *(int *)(param_1 + 0x148) = (int)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) >> 4;
    uVar4 = uVar6 + 8 & 3;
    uVar5 = *(uint *)(uVar6 + 8 & 0xfffffffc);
    *(int *)(param_1 + 0x14c) = (int)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) >> 4;
    func_01ff9048(0x19,param_1 + 0x120,0xc);
    func_01ff9048(0x1b,param_1 + 0xbc,3);
    uVar4 = param_1 + 0x418U & 3;
    uVar5 = *(uint *)(param_1 + 0x418U & 0xfffffffc);
    local_54 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    uVar4 = param_1 + 0x404U & 3;
    uVar5 = *(uint *)(param_1 + 0x404U & 0xfffffffc);
    local_58 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    uVar4 = param_1 + 0x414U & 3;
    uVar5 = *(uint *)(param_1 + 0x414U & 0xfffffffc);
    local_5c = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    func_01ff9048(0x1b,(undefined4)(uintptr_t)(&local_5c),3);
    uVar4 = uVar8 + 0x1c & 3;
    uVar5 = *(uint *)(uVar8 + 0x1c & 0xfffffffc);
    StructAD00Sh_SomeFn_0(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20);
    local_cc = 0x1e;
    func_01ff9048(0x14,(undefined4)(uintptr_t)(&local_cc),1);
  }
  uVar4 = param_1 + 0x1b4U & 3;
  uVar5 = *(uint *)(param_1 + 0x1b4U & 0xfffffffc);
  func_01ff9048(0x19,uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20,0xc);
  func_01ff9048(0x1b,param_1 + 0xbc,3);
  local_c8 = 0x1d;
  func_01ff9048(0x13,(undefined4)(uintptr_t)(&local_c8),1);
  uVar4 = param_1 + 0x418U & 3;
  uVar5 = *(uint *)(param_1 + 0x418U & 0xfffffffc);
  local_48 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  uVar4 = param_1 + 0x404U & 3;
  uVar5 = *(uint *)(param_1 + 0x404U & 0xfffffffc);
  local_4c = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  uVar4 = param_1 + 0x414U & 3;
  uVar5 = *(uint *)(param_1 + 0x414U & 0xfffffffc);
  local_50 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  func_01ff9048(0x1b,(undefined4)(uintptr_t)(&local_50),3);
  if (!bVar9) {
    uVar4 = uVar8 + 0x1c & 3;
    uVar5 = *(uint *)(uVar8 + 0x1c & 0xfffffffc);
    StructAD00Sh_SomeFn_0(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20);
  }
  LightInfo_MaybeApply((ushort *)(uintptr_t)(uVar8 + 0x40));
  uVar4 = uVar8 + 0x58 & 3;
  uVar5 = *(uint *)(uVar8 + 0x58 & 0xfffffffc);
  if (uVar5 >> uVar4 * 8 == 0 && uVar5 << uVar4 * -8 + 0x20 == 0) {
    uVar4 = uVar8 + 0x60 & 3;
    uVar5 = *(uint *)(uVar8 + 0x60 & 0xfffffffc);
    func_02079b9c(uVar8,uVar5 >> uVar4 * 8 == 0 && uVar5 << uVar4 * -8 + 0x20 == 0);
    local_c4 = 0x1c;
    func_01ff9048(0x13,(undefined4)(uintptr_t)(&local_c4),1);
    uVar4 = param_1 + 0x4f4U & 3;
    uVar5 = *(uint *)(param_1 + 0x4f4U & 0xfffffffc);
    local_40 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    uVar4 = param_1 + 0x4f0U & 3;
    uVar5 = *(uint *)(param_1 + 0x4f0U & 0xfffffffc);
    local_44 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    local_3c = 0x1000;
    func_01ff9048(0x1b,(undefined4)(uintptr_t)(&local_44),3);
    uVar4 = uVar8 + 0x14 & 3;
    uVar5 = *(uint *)(uVar8 + 0x14 & 0xfffffffc);
    func_020849d0(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20);
    uVar4 = uVar8 + 0x18 & 3;
    uVar5 = *(uint *)(uVar8 + 0x18 & 0xfffffffc);
    if (uVar5 >> uVar4 * 8 != 0 || uVar5 << uVar4 * -8 + 0x20 != 0) {
      uVar4 = param_1 + 0x590U & 3;
      uVar5 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
      uVar5 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
      uVar4 = uVar5 + 0x20;
      uVar6 = uVar4 & 3;
      uVar1 = *(uint *)(uVar4 & 0xfffffffc);
      uVar5 = uVar5 + 0x54;
      uVar4 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      uVar7 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
      uVar4 = (uVar1 >> uVar6 * 8 | uVar1 << uVar6 * -8 + 0x20) + 0x10;
      uVar5 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      uVar6 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
      local_c0 = 0x1c;
      func_01ff9048(0x14,(undefined4)(uintptr_t)(&local_c0),1);
      func_01ff9048(0x1c,uVar7 + 0x18,3);
      iVar2 = (int)(uint)*(ushort *)(param_1 + 0x3a4) >> 4;
      MTX_RotX33__from_thumb
                ((undefined4 *)(void *)(auStack_b0),(int)*(short *)(iRam0206417c + iVar2 * 4),
                 (int)*(short *)(iRam0206417c + (iVar2 * 2 + 1) * 2));
      func_01ff9048(0x1a,(undefined4)(uintptr_t)(auStack_b0),9);
      uVar4 = uVar8 + 0x18 & 3;
      uVar5 = *(uint *)(uVar8 + 0x18 & 0xfffffffc);
      func_020849d0(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20);
      uVar4 = uVar7 + 0x18 & 3;
      uVar5 = *(uint *)(uVar7 + 0x18 & 0xfffffffc);
      if (uVar5 >> uVar4 * 8 != 0 || uVar5 << uVar4 * -8 + 0x20 != 0) {
        uVar4 = uVar7 + 0x24 & 3;
        uVar5 = *(uint *)(uVar7 + 0x24 & 0xfffffffc);
        local_38[0] = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
        local_38[1] = 0;
        local_38[2] = 0;
        func_01ff9048(0x1c,(undefined4)(uintptr_t)(local_38),3);
        uVar4 = uVar8 + 0x18 & 3;
        uVar5 = *(uint *)(uVar8 + 0x18 & 0xfffffffc);
        func_020849d0(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20);
      }
      local_bc = 0x1c;
      func_01ff9048(0x14,(undefined4)(uintptr_t)(&local_bc),1);
      func_01ff9048(0x1c,uVar7,3);
      local_38[3] = uVar6;
      local_28 = uVar6;
      local_24 = uVar6;
      func_01ff9048(0x1b,(undefined4)(uintptr_t)(local_38 + 3),3);
      func_01ff9048(0x11,0,0);
      uVar4 = param_1 + 0x4ccU & 3;
      uVar5 = *(uint *)(param_1 + 0x4ccU & 0xfffffffc);
      iVar2 = (int)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) >> 4;
      MTX_RotY33__from_thumb
                ((undefined4 *)(void *)(auStack_8c),(int)*(short *)(iRam0206417c + iVar2 * 4),
                 (int)*(short *)(iRam0206417c + (iVar2 * 2 + 1) * 2));
      func_01ff9048(0x1a,(undefined4)(uintptr_t)(auStack_8c),9);
      func_01ff9048(0x1a,(undefined4)(uintptr_t)(auStack_b0),9);
      uVar4 = uVar8 + 0x18 & 3;
      uVar5 = *(uint *)(uVar8 + 0x18 & 0xfffffffc);
      func_020849d0(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20);
      if (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 != 0 ||
          *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20 != 0) {
        local_b8 = 1;
        func_01ff9048(0x12,&local_b8);
        uVar4 = uVar7 + 0xc & 3;
        uVar5 = *(uint *)(uVar7 + 0xc & 0xfffffffc);
        local_20[0] = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
        local_20[1] = 0;
        local_20[2] = 0;
        func_01ff9048(0x1c,local_20,3);
        func_01ff9048(0x1a,auStack_8c,9);
        func_01ff9048(0x1a,auStack_b0,9);
        uVar4 = uVar8 + 0x18 & 3;
        uVar5 = *(uint *)(uVar8 + 0x18 & 0xfffffffc);
        func_020849d0(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20);
      }
    }
  }
  uVar4 = uVar8 + 0x5c & 3;
  uVar5 = *(uint *)(uVar8 + 0x5c & 0xfffffffc);
  if (uVar5 >> uVar4 * 8 == 0 && uVar5 << uVar4 * -8 + 0x20 == 0) {
    uVar4 = uVar8 + 0x20 & 3;
    uVar5 = *(uint *)(uVar8 + 0x20 & 0xfffffffc);
    iVar2 = (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
            *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) * 0xc +
            (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20);
    uStack_68 = *(undefined4 *)(iVar2 + 0x44);
    uStack_60 = *(undefined4 *)(iVar2 + 0x4c);
    uVar4 = param_1 + 0x408U & 3;
    uVar1 = *(uint *)(param_1 + 0x408U & 0xfffffffc);
    uVar5 = param_1 + 0x4f8U & 3;
    uVar6 = *(uint *)(param_1 + 0x4f8U & 0xfffffffc);
    iStack_64 = *(int *)(iVar2 + 0x48) +
                (uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) +
                (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
    uStack_b4 = 0x1d;
    func_01ff9048(0x14,&uStack_b4,1);
    func_01ff9048(0x1c,&uStack_68,3);
    uVar4 = uVar8 + 0x10 & 3;
    uVar5 = *(uint *)(uVar8 + 0x10 & 0xfffffffc);
    func_020849d0(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20);
    return;
  }
  return;
}

