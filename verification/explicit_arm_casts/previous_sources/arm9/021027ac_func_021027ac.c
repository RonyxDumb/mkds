/* Decompiled C draft; module arm9; ROM address 021027ac. No matching claim. */
#include "types.h"
#include "deps/021027ac_func_021027ac.h"

void func_021027ac(int param_1,undefined4 param_2,int param_3)

{
  ushort uVar1;
  longlong lVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uStack_54;
  uint uStack_50;
  uint uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  uVar8 = param_1 + 300U & 3;
  uVar3 = *(uint *)(param_1 + 300U & 0xfffffffc);
  if (uVar3 >> uVar8 * 8 == 0 && uVar3 << uVar8 * -8 + 0x20 == 0) {
    return;
  }
  uVar8 = param_1 + 0x198U & 3;
  uVar3 = *(uint *)(param_1 + 0x198U & 0xfffffffc);
  if (uVar3 >> uVar8 * 8 != 0 || uVar3 << uVar8 * -8 + 0x20 != 0) {
    puVar4 = (undefined4 *)func_020e6cf8(param_1 + 0x50);
    uStack_48 = *puVar4;
    uStack_44 = puVar4[1];
    uStack_40 = puVar4[2];
    uStack_30 = puVar4[6];
    uStack_2c = puVar4[7];
    uStack_28 = puVar4[8];
    uStack_24 = puVar4[9];
    uStack_20 = puVar4[10];
    uStack_1c = puVar4[0xb];
    uVar8 = param_1 + 0x19cU & 3;
    uVar3 = *(uint *)(param_1 + 0x19cU & 0xfffffffc);
    uVar8 = uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20;
    if ((int)uVar8 < 1) {
      uVar8 = -uVar8;
    }
    iVar9 = 0x1000 - ((uint)((ulonglong)uVar8 * 0xa4) >> 0xc |
                     (((int)uVar8 >> 0x1f) * 0xa4 + (int)((ulonglong)uVar8 * 0xa4 >> 0x20)) *
                     0x100000);
    uStack_34 = (uint)((longlong)(int)puVar4[5] * (longlong)iVar9) >> 0xc |
                (int)((ulonglong)((longlong)(int)puVar4[5] * (longlong)iVar9) >> 0x20) << 0x14;
    uStack_3c = (uint)((longlong)(int)puVar4[3] * (longlong)iVar9) >> 0xc |
                (int)((ulonglong)((longlong)(int)puVar4[3] * (longlong)iVar9) >> 0x20) << 0x14;
    uStack_38 = (uint)((longlong)(int)puVar4[4] * (longlong)iVar9) >> 0xc |
                (int)((ulonglong)((longlong)(int)puVar4[4] * (longlong)iVar9) >> 0x20) << 0x14;
    uVar8 = param_1 + 0x19cU & 3;
    uVar3 = *(uint *)(param_1 + 0x19cU & 0xfffffffc);
    VecFx32_AddScale1(uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20,&uStack_48,&uStack_3c,
                      &uStack_3c);
    uVar8 = param_1 + 0x180U & 3;
    uVar7 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
    uVar3 = param_1 + 0x68U & 3;
    uVar5 = *(uint *)(param_1 + 0x68U & 0xfffffffc);
    lVar2 = (longlong)(int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) *
            (longlong)(int)(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20);
    uStack_54 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
    uVar8 = param_1 + 0x184U & 3;
    uVar7 = *(uint *)(param_1 + 0x184U & 0xfffffffc);
    uVar3 = param_1 + 0x6cU & 3;
    uVar5 = *(uint *)(param_1 + 0x6cU & 0xfffffffc);
    lVar2 = (longlong)(int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) *
            (longlong)(int)(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20);
    uStack_50 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
    uVar8 = param_1 + 0x70U & 3;
    uVar3 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
    uStack_4c = uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20;
    iVar6 = func_0203c5e4();
    iVar9 = iRam02102984;
    if (iVar6 == 0) {
      iVar9 = iRam02102988;
    }
    uStack_54 = (uint)((longlong)(int)uStack_54 * (longlong)iVar9) >> 0xc |
                (int)((ulonglong)((longlong)(int)uStack_54 * (longlong)iVar9) >> 0x20) << 0x14;
    uStack_50 = (uint)((longlong)(int)uStack_50 * (longlong)iVar9) >> 0xc |
                (int)((ulonglong)((longlong)(int)uStack_50 * (longlong)iVar9) >> 0x20) << 0x14;
    uVar1 = *(ushort *)(param_1 + 0xd8);
    if (uVar1 != 0x1f) {
      uVar8 = param_3 + 0x14U & 3;
      uVar3 = *(uint *)(param_3 + 0x14U & 0xfffffffc);
      *(uint *)(param_3 + 0x14) = (uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) & 0xffe0ffff;
      uVar8 = param_3 + 0x14U & 3;
      uVar3 = *(uint *)(param_3 + 0x14U & 0xfffffffc);
      *(uint *)(param_3 + 0x14) =
           uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20 | (uint)uVar1 << 0x10;
    }
    func_020e6a18(param_3);
    func_020e67c4(param_3,&uStack_48,&uStack_54,0);
    if (*(short *)(param_1 + 0xd8) != 0x1f) {
      uVar8 = param_3 + 0x14U & 3;
      uVar3 = *(uint *)(param_3 + 0x14U & 0xfffffffc);
      *(uint *)(param_3 + 0x14) = (uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) & 0xffe0ffff;
      uVar8 = param_3 + 0x14U & 3;
      uVar3 = *(uint *)(param_3 + 0x14U & 0xfffffffc);
      *(uint *)(param_3 + 0x14) = uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20 | 0x1f0000;
      return;
    }
    return;
  }
  return;
}

