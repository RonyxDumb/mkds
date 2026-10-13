/* Decompiled C draft; module arm9; ROM address 020e2a74. No matching claim. */
#include "types.h"
#include "deps/020e2a74_func_020e2a74.h"

void func_020e2a74(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uStack_48;
  uint auStack_44 [10];
  uint uStack_1c;
  uint uStack_18;
  
  uVar8 = param_1 + 0x3cU & 3;
  uVar4 = *(uint *)(param_1 + 0x3cU & 0xfffffffc);
  if (uVar4 >> uVar8 * 8 != 0 || uVar4 << uVar8 * -8 + 0x20 != 0) {
    iVar5 = VecFx32_CrossProduct_0(param_2 + 0x40,param_1 + 0x2c);
    uVar8 = param_2 + 0x9cU & 3;
    uVar6 = *(uint *)(param_2 + 0x9cU & 0xfffffffc);
    uVar4 = param_2 + 0xf4U & 3;
    uVar7 = *(uint *)(param_2 + 0xf4U & 0xfffffffc);
    if (*(short *)((uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) + 0x2e) == 0) {
      iVar5 = -iVar5;
    }
    if (*(short *)((uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + 0x12) < iVar5) {
      return;
    }
  }
  uVar8 = param_2 + 0x78U & 3;
  uVar4 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
  if ((iRam020e2cbc < (int)((uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) & 0x3fffffe0)) &&
     (iVar5 = func_0203c5e4(), iVar5 == 0)) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  if ((!bVar3) &&
     (uVar8 = param_2 + 0x128U & 3, uVar4 = *(uint *)(param_2 + 0x128U & 0xfffffffc),
     uVar4 >> uVar8 * 8 != 0 || uVar4 << uVar8 * -8 + 0x20 != 0)) {
    if (*(short *)(param_2 + 0xfe) < 0x10) {
      uVar8 = param_2 + 4;
    }
    else {
      uVar8 = param_2 + 0x144;
    }
    *(int *)(param_2 + 0x4c) =
         (int)(*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
              *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) >> 4;
    uVar4 = uVar8 + 4 & 3;
    uVar6 = *(uint *)(uVar8 + 4 & 0xfffffffc);
    *(int *)(param_2 + 0x50) = (int)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) >> 4;
    uVar4 = uVar8 + 8 & 3;
    uVar8 = *(uint *)(uVar8 + 8 & 0xfffffffc);
    *(int *)(param_2 + 0x54) = (int)(uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) >> 4;
    uVar8 = param_2 + 0x128U & 3;
    uVar4 = *(uint *)(param_2 + 0x128U & 0xfffffffc);
    func_020ea868(uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20,param_2 + 0x28,param_2 + 0x1c,
                  param_4);
  }
  uVar8 = param_2 + 4U & 3;
  uVar4 = *(uint *)(param_2 + 4U & 0xfffffffc);
  *(int *)(param_2 + 0x4c) = (int)(uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) >> 4;
  uVar8 = param_2 + 8U & 3;
  uVar4 = *(uint *)(param_2 + 8U & 0xfffffffc);
  *(int *)(param_2 + 0x50) = (int)(uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) >> 4;
  uVar8 = param_2 + 0xcU & 3;
  uVar4 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  *(int *)(param_2 + 0x54) = (int)(uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) >> 4;
  uVar8 = param_2 + 300U & 3;
  uVar4 = *(uint *)(param_2 + 300U & 0xfffffffc);
  uVar8 = uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20;
  if (uVar8 != 0) {
    *(uint *)(uVar8 + 0xc) = (uint)*(ushort *)(param_2 + 0x130) << 0xc;
    uVar4 = uVar8 + 0x1c & 3;
    uVar7 = *(uint *)(uVar8 + 0x1c & 0xfffffffc);
    uVar6 = uVar8 + 0xc & 3;
    uVar9 = *(uint *)(uVar8 + 0xc & 0xfffffffc);
    uVar8 = (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + (uint)*(ushort *)(uVar8 + 0x1a) * 4;
    uVar4 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    *(uint *)(uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) =
         uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20;
  }
  LightInfo_MaybeApply((ushort *)(uintptr_t)(param_2 + iRam020e2cc0));
  uVar8 = param_2 + 0x124U & 3;
  uVar4 = *(uint *)(param_2 + 0x124U & 0xfffffffc);
  func_020ea8a8(uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20,param_2 + 0x28,param_2 + 0x1c,
                param_4);
  if (!bVar3) {
    uVar8 = param_2 + 0x110U & 3;
    uVar4 = *(uint *)(param_2 + 0x110U & 0xfffffffc);
    uVar8 = uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20;
    iVar5 = (int)(uint)*(ushort *)(param_2 + 0x10c) >> 4;
    lVar1 = (longlong)(int)uVar8 * (longlong)(int)*(short *)(iRam020e2cc4 + iVar5 * 4) + 0x800;
    lVar2 = (longlong)(int)uVar8 * (longlong)(int)*(short *)(iRam020e2cc4 + (iVar5 * 2 + 1) * 2) +
            0x800;
    MTX_RotX43__from_thumb
              (auStack_44,(uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000,
               (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000);
    uVar8 = param_2 + 0x100U & 3;
    uVar4 = *(uint *)(param_2 + 0x100U & 0xfffffffc);
    auStack_44[0] = uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20;
    uVar8 = param_2 + 0x104U & 3;
    uVar4 = *(uint *)(param_2 + 0x104U & 0xfffffffc);
    uStack_1c = uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20;
    uVar8 = param_2 + 0x108U & 3;
    uVar4 = *(uint *)(param_2 + 0x108U & 0xfffffffc);
    uStack_18 = uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20;
    func_01ff9048(0x11,0,0);
    func_01ff9048(0x19,(undefined4)(uintptr_t)(auStack_44),0xc);
    func_020849d0(*(uint *)(uRam020e2cc8 & 0xfffffffc) >> (uRam020e2cc8 & 3) * 8 |
                  *(uint *)(uRam020e2cc8 & 0xfffffffc) << (uRam020e2cc8 & 3) * -8 + 0x20);
    uStack_48 = 1;
    func_01ff9048(0x12,&uStack_48);
    uStack_18 = -uStack_18;
    func_01ff9048(0x19,(undefined4)(uintptr_t)(auStack_44),0xc);
    func_020849d0(*(uint *)(uRam020e2cc8 & 0xfffffffc) >> (uRam020e2cc8 & 3) * 8 |
                  *(uint *)(uRam020e2cc8 & 0xfffffffc) << (uRam020e2cc8 & 3) * -8 + 0x20);
    return;
  }
  return;
}

