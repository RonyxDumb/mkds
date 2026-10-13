/* Decompiled C draft; module arm9; ROM address 020641f0. No matching claim. */
#include "types.h"
#include "deps/020641f0_func_020641f0.h"

void func_020641f0(int param_1)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 local_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 local_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 local_f4;
  uint local_f0;
  uint uStack_ec;
  uint uStack_e8;
  undefined4 local_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 local_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 local_c4;
  uint local_c0;
  uint uStack_bc;
  uint uStack_b8;
  undefined1 auStack_b4 [48];
  undefined1 auStack_84 [48];
  undefined1 auStack_54 [52];
  
  uVar5 = param_1 + 0x50cU & 3;
  uVar4 = *(uint *)(param_1 + 0x50cU & 0xfffffffc);
  func_01ffcd84((int *)(uintptr_t)(param_1 + 0x120),uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
  uVar5 = param_1 + 0x4cU & 3;
  uVar4 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  if ((uVar5 & 0x10) == 0) {
    if ((uVar5 & 0x20) == 0) {
      *(undefined4 *)(param_1 + 0x150) = *(undefined4 *)(param_1 + 0x120);
      *(undefined4 *)(param_1 + 0x154) = *(undefined4 *)(param_1 + 0x124);
      *(undefined4 *)(param_1 + 0x158) = *(undefined4 *)(param_1 + 0x128);
      *(undefined4 *)(param_1 + 0x15c) = *(undefined4 *)(param_1 + 300);
      *(undefined4 *)(param_1 + 0x160) = *(undefined4 *)(param_1 + 0x130);
      *(undefined4 *)(param_1 + 0x164) = *(undefined4 *)(param_1 + 0x134);
      *(undefined4 *)(param_1 + 0x168) = *(undefined4 *)(param_1 + 0x138);
      *(undefined4 *)(param_1 + 0x16c) = *(undefined4 *)(param_1 + 0x13c);
      *(undefined4 *)(param_1 + 0x170) = *(undefined4 *)(param_1 + 0x140);
      *(undefined4 *)(param_1 + 0x174) = *(undefined4 *)(param_1 + 0x144);
      *(undefined4 *)(param_1 + 0x178) = *(undefined4 *)(param_1 + 0x148);
      *(undefined4 *)(param_1 + 0x17c) = *(undefined4 *)(param_1 + 0x14c);
      uVar5 = param_1 + 0x508U & 3;
      uVar4 = *(uint *)(param_1 + 0x508U & 0xfffffffc);
      uVar3 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
      *(uint *)(param_1 + 0x174) =
           *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
           *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
      uVar5 = uVar3 + 4 & 3;
      uVar4 = *(uint *)(uVar3 + 4 & 0xfffffffc);
      *(uint *)(param_1 + 0x178) = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
      uVar5 = uVar3 + 8 & 3;
      uVar4 = *(uint *)(uVar3 + 8 & 0xfffffffc);
      *(uint *)(param_1 + 0x17c) = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    }
    else {
      iVar8 = (int)(uint)*(ushort *)(param_1 + 0x364) >> 4;
      MTX_RotY43__from_thumb
                ((undefined4 *)(void *)(auStack_54),(int)*(short *)(iRam020646b4 + iVar8 * 4),
                 (int)*(short *)(iRam020646b4 + (iVar8 * 2 + 1) * 2));
      MTX_Concat43((uint)(uintptr_t)(auStack_54),(uint *)(uintptr_t)(param_1 + 0x120),(uint *)(uintptr_t)(param_1 + 0x150));
      uVar5 = param_1 + 0x508U & 3;
      uVar4 = *(uint *)(param_1 + 0x508U & 0xfffffffc);
      uVar3 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
      *(uint *)(param_1 + 0x174) =
           *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
           *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
      uVar5 = uVar3 + 4 & 3;
      uVar4 = *(uint *)(uVar3 + 4 & 0xfffffffc);
      *(uint *)(param_1 + 0x178) = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
      uVar5 = uVar3 + 8 & 3;
      uVar4 = *(uint *)(uVar3 + 8 & 0xfffffffc);
      *(uint *)(param_1 + 0x17c) = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    }
  }
  else {
    iVar8 = param_1 + 0x150;
    Matrix4x3_Identity(&local_114);
    local_e4 = local_114;
    uStack_e0 = uStack_110;
    uStack_dc = uStack_10c;
    uStack_d8 = uStack_108;
    local_d4 = local_104;
    uStack_d0 = uStack_100;
    uStack_cc = uStack_fc;
    uStack_c8 = uStack_f8;
    local_c4 = local_f4;
    local_c0 = local_f0;
    uStack_bc = uStack_ec;
    uStack_b8 = uStack_e8;
    func_01ffcd84((int *)(void *)(auStack_b4),param_1 + 0x34c);
    uVar5 = param_1 + 300U & 3;
    uVar4 = *(uint *)(param_1 + 300U & 0xfffffffc);
    uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    lVar2 = (ulonglong)uVar5 * 0xffffb000;
    local_f0 = (uint)lVar2 >> 0xc | ((int)((ulonglong)lVar2 >> 0x20) - uVar5) * 0x100000;
    uVar5 = param_1 + 0x130U & 3;
    uVar4 = *(uint *)(param_1 + 0x130U & 0xfffffffc);
    uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    lVar2 = (ulonglong)uVar5 * 0xffffb000;
    uStack_ec = (uint)lVar2 >> 0xc | ((int)((ulonglong)lVar2 >> 0x20) - uVar5) * 0x100000;
    uVar5 = param_1 + 0x134U & 3;
    uVar4 = *(uint *)(param_1 + 0x134U & 0xfffffffc);
    uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    local_c0 = -local_f0;
    lVar2 = (ulonglong)uVar5 * 0xffffb000;
    uStack_e8 = (uint)lVar2 >> 0xc | ((int)((ulonglong)lVar2 >> 0x20) - uVar5) * 0x100000;
    uStack_b8 = -uStack_e8;
    uStack_bc = -uStack_ec;
    MTX_Concat43(param_1 + 0x120,&local_114,(uint *)(uintptr_t)(iVar8));
    MTX_Concat43(iVar8,(uint *)(void *)(auStack_b4),(uint *)(uintptr_t)(iVar8));
    MTX_Concat43(iVar8,&local_e4,(uint *)(uintptr_t)(iVar8));
    uVar5 = param_1 + 0x4cU & 3;
    uVar4 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    if (((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0x20) != 0) {
      iVar1 = (int)(uint)*(ushort *)(param_1 + 0x364) >> 4;
      MTX_RotY43__from_thumb
                ((undefined4 *)(void *)(auStack_84),(int)*(short *)(iRam020646b4 + iVar1 * 4),
                 (int)*(short *)(iRam020646b4 + (iVar1 * 2 + 1) * 2));
      MTX_Concat43(iVar8,(uint *)(void *)(auStack_84),(uint *)(uintptr_t)(iVar8));
    }
    uVar5 = param_1 + 0x508U & 3;
    uVar4 = *(uint *)(param_1 + 0x508U & 0xfffffffc);
    uVar3 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    uVar5 = param_1 + 0x174U & 3;
    uVar6 = *(uint *)(param_1 + 0x174U & 0xfffffffc);
    uVar4 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *(uint *)(param_1 + 0x174) =
         (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) +
         (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
    uVar5 = param_1 + 0x508U & 3;
    uVar3 = *(uint *)(param_1 + 0x508U & 0xfffffffc);
    uVar4 = param_1 + 0x178U & 3;
    uVar6 = *(uint *)(param_1 + 0x178U & 0xfffffffc);
    uVar5 = (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + 4;
    uVar3 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(param_1 + 0x178) =
         (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) +
         (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20);
    uVar5 = param_1 + 0x508U & 3;
    uVar3 = *(uint *)(param_1 + 0x508U & 0xfffffffc);
    uVar4 = param_1 + 0x17cU & 3;
    uVar6 = *(uint *)(param_1 + 0x17cU & 0xfffffffc);
    uVar5 = (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + 8;
    uVar3 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(param_1 + 0x17c) =
         (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) +
         (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20);
  }
  *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0x174);
  *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_1 + 0x178);
  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 0x17c);
  uVar5 = param_1 + 0x174U & 3;
  uVar4 = *(uint *)(param_1 + 0x174U & 0xfffffffc);
  *(int *)(param_1 + 0x174) = (int)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) >> 4;
  uVar5 = param_1 + 0x178U & 3;
  uVar4 = *(uint *)(param_1 + 0x178U & 0xfffffffc);
  *(int *)(param_1 + 0x178) = (int)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) >> 4;
  uVar5 = param_1 + 0x17cU & 3;
  uVar4 = *(uint *)(param_1 + 0x17cU & 0xfffffffc);
  *(int *)(param_1 + 0x17c) = (int)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) >> 4;
  uVar5 = param_1 + 0x4cU & 3;
  uVar4 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0x2000000) == 0) {
    *(int *)(param_1 + 0x1b4) = param_1 + 0x150;
  }
  else {
    StructMQRacerEntry_SomeFn_77(param_1);
    *(int *)(param_1 + 0x1b4) = param_1 + 0x184;
  }
  uVar5 = param_1 + 0x590U & 3;
  uVar4 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
  uVar3 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = uVar3 + 0x18 & 3;
  uVar4 = *(uint *)(uVar3 + 0x18 & 0xfffffffc);
  if (uVar4 >> uVar5 * 8 != 0 || uVar4 << uVar5 * -8 + 0x20 != 0) {
    uVar5 = uVar3 + 0x30 & 3;
    uVar6 = *(uint *)(uVar3 + 0x30 & 0xfffffffc);
    uVar4 = uVar3 + 0x24 & 3;
    uVar3 = *(uint *)(uVar3 + 0x24 & 0xfffffffc);
    lVar2 = (longlong)(int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) *
            (longlong)(int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
    uVar4 = iRam020646b8 * ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
    uVar5 = param_1 + 0x2a0U & 3;
    uVar3 = *(uint *)(param_1 + 0x2a0U & 0xfffffffc);
    uVar6 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
    uVar5 = param_1 + 0x4d4U & 3;
    uVar3 = *(uint *)(param_1 + 0x4d4U & 0xfffffffc);
    uVar5 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
    if ((int)uVar6 < (int)uVar5) {
      *(short *)(param_1 + 0x3a4) = *(short *)(param_1 + 0x3a4) + (short)(uVar5 * 2000 >> 0xc);
    }
    else {
      uVar5 = (uint)((ulonglong)uVar6 * 4000) >> 0xc |
              (((int)uVar6 >> 0x1f) * 4000 + (int)((ulonglong)uVar6 * 4000 >> 0x20)) * 0x100000;
      func_0207a7ec();
      iVar8 = AbsValue();
      if (iVar8 < 0x29) {
        uVar3 = param_1 + 0x78U & 3;
        uVar6 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
        uVar5 = 0;
        if (((*(ushort *)(iRam020646bc + (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) * 0x5c) &
             3) != 0) && (iVar8 = IsAwardOrStaffRoll(), iVar8 == 1)) {
          uVar5 = 400;
        }
      }
      else {
        uVar3 = param_1 + 0x44U & 3;
        uVar6 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
        if (((uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) & 0x100) != 0) {
          uVar5 = -uVar5;
        }
      }
      if (4000 < (int)uVar5) {
        uVar5 = 4000;
      }
      *(short *)(param_1 + 0x3a4) = *(short *)(param_1 + 0x3a4) + (short)uVar5;
    }
    *(uint *)(param_1 + 0x4cc) = uVar4 >> 0xc & 0xffff;
  }
  uVar5 = param_1 + 0x590U & 3;
  uVar4 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
  uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 8;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  if ((uVar5 != 0) && (*(short *)(uVar5 + 0x18) != 0)) {
    StructMQRacerEntry_SomeFn_20(param_1);
    iVar8 = IsRacerFinishedRace(*(undefined2 *)(param_1 + 0x74));
    if (iVar8 != 0) {
      func_0207b354(param_1);
    }
    uVar5 = param_1 + 0x590U & 3;
    uVar4 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
    uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 8;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar6 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    uVar5 = uVar6 + 0x1c & 3;
    uVar3 = *(uint *)(uVar6 + 0x1c & 0xfffffffc);
    uVar4 = uVar6 + 0xc & 3;
    uVar7 = *(uint *)(uVar6 + 0xc & 0xfffffffc);
    uVar5 = (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + (uint)*(ushort *)(uVar6 + 0x1a) * 4;
    uVar3 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) =
         uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20;
  }
  uVar5 = param_1 + 0x4cU & 3;
  uVar4 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0x400000) != 0) {
    *(short *)(param_1 + 0x504) = *(short *)(param_1 + 0x504) + 1;
    *(short *)(param_1 + 0x506) = *(short *)(param_1 + 0x506) + 1;
    if (8 < *(ushort *)(param_1 + 0x506)) {
      *(undefined2 *)(param_1 + 0x506) = 0;
    }
    if (*(ushort *)(param_1 + 0x506) < 4) {
      uVar5 = param_1 + 0x4cU & 3;
      uVar4 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
      *(uint *)(param_1 + 0x4c) = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0xfeffffff;
    }
    else {
      uVar5 = param_1 + 0x4cU & 3;
      uVar4 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
      *(uint *)(param_1 + 0x4c) = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20 | 0x1000000;
    }
    if (0x5a < *(ushort *)(param_1 + 0x504)) {
      uVar5 = param_1 + 0x4cU & 3;
      uVar4 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
      *(uint *)(param_1 + 0x4c) = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0xfebfffff;
    }
  }
  func_01ff9b70(param_1);
  return;
}

