/* Decompiled C draft; module arm9; ROM address 020ec1fc. No matching claim. */
#include "types.h"
#include "deps/020ec1fc_func_020ec1fc.h"

void func_020ec1fc(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uStack_28;
  uint uStack_24;
  int iStack_20;
  uint uStack_1c;
  
  uVar5 = uRam020ec310;
  uVar6 = param_2 + 4U & 3;
  uVar4 = *(uint *)(param_2 + 4U & 0xfffffffc);
  sVar1 = *(short *)(param_2 + 0x8e);
  *(int *)(param_2 + 0x4c) = (int)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) >> 4;
  uVar6 = param_2 + 8U & 3;
  uVar4 = *(uint *)(param_2 + 8U & 0xfffffffc);
  *(int *)(param_2 + 0x50) = (int)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) >> 4;
  uVar6 = param_2 + 0xcU & 3;
  uVar4 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  *(int *)(param_2 + 0x54) = (int)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) >> 4;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  func_020ea8a8(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20,param_2 + 0x28,param_2 + 0x1c);
  if (sVar1 != 0) {
    uVar6 = param_2 + 0xd0U & 3;
    uVar5 = *(uint *)(param_2 + 0xd0U & 0xfffffffc);
    uVar6 = 0x5a000 - (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20);
    lVar3 = (ulonglong)uVar6 * 0x2e;
    uStack_28 = (uint)lVar3 >> 0xc |
                (((int)uVar6 >> 0x1f) * 0x2e + (int)((ulonglong)lVar3 >> 0x20)) * 0x100000;
    uVar6 = param_2 + 4U & 3;
    uVar5 = *(uint *)(param_2 + 4U & 0xfffffffc);
    uStack_24 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    uVar6 = param_2 + 0xcU & 3;
    uVar5 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
    uStack_1c = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    uVar6 = param_2 + 0xbcU & 3;
    uVar9 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
    uVar5 = param_2 + 0xccU & 3;
    uVar8 = *(uint *)(param_2 + 0xccU & 0xfffffffc);
    uVar4 = param_2 + 0xc4U & 3;
    uVar7 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
    lVar3 = (longlong)(int)(uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) *
            (longlong)(int)(uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20);
    uVar6 = param_2 + 0xd4U & 3;
    uVar5 = *(uint *)(param_2 + 0xd4U & 0xfffffffc);
    lVar2 = (longlong)(int)(uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) *
            (longlong)(int)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20);
    uVar6 = param_2 + 0xb4U & 3;
    uVar5 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    iStack_20 = ((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) -
                ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14)) -
                ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
    uVar6 = param_2 + 0x58U & 3;
    uVar5 = *(uint *)(param_2 + 0x58U & 0xfffffffc);
    VecFx32_AddScale1(-(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20),param_2 + 0xbc,&uStack_24,
                      &uStack_24);
    func_020e5634(param_2 + 0x114,&uStack_24);
    func_020e53ac(param_2 + 0x114,&uStack_28,0,param_4);
    return;
  }
  return;
}

