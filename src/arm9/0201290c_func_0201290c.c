/* Decompiled C draft; module arm9; ROM address 0201290c. No matching claim. */
#include "types.h"
#include "deps/0201290c_func_0201290c.h"

void func_0201290c(int param_1,int param_2,int param_3,int param_4)

{
  undefined2 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uStack_7c;
  uint uStack_78;
  uint uStack_74;
  undefined4 uStack_70;
  uint uStack_6c;
  uint uStack_68;
  uint auStack_64 [6];
  uint uStack_4c;
  uint uStack_48;
  undefined2 uStack_44;
  undefined2 uStack_42;
  uint uStack_40;
  uint uStack_3c;
  undefined2 uStack_38;
  undefined2 uStack_36;
  uint uStack_34;
  uint uStack_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint uStack_20;
  uint uStack_1c;
  uint uStack_18;
  uint uVar6;
  
  uVar6 = param_1 + 0x1cU & 3;
  uVar5 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  if (uVar6 != 0x1000) {
    local_2c = uVar6;
    local_28 = uVar6;
    local_24 = uVar6;
    func_01ff9048(0x1b,(undefined4)(uintptr_t)(&local_2c),3);
  }
  if (param_4 != 0) {
    uVar6 = param_1 + 8U & 3;
    uVar5 = *(uint *)(param_1 + 8U & 0xfffffffc);
    iVar4 = param_1 + (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20);
    uVar6 = (uint)*(ushort *)(iVar4 + 4 + (uint)*(ushort *)(iVar4 + 10)) * param_2 +
            iVar4 + 4 + (uint)*(ushort *)(iVar4 + 10) + 4;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    iVar4 = iVar4 + (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
    uVar6 = iVar4 + 0xcU & 3;
    uVar5 = *(uint *)(iVar4 + 0xcU & 0xfffffffc);
    if (((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x1f0000) == 0) {
      return;
    }
    uVar6 = iVar4 + 4U & 3;
    uVar5 = *(uint *)(iVar4 + 4U & 0xfffffffc);
    uStack_7c = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    uVar6 = iVar4 + 8U & 3;
    uVar5 = *(uint *)(iVar4 + 8U & 0xfffffffc);
    uStack_78 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    uVar6 = iVar4 + 0xcU & 3;
    uVar5 = *(uint *)(iVar4 + 0xcU & 0xfffffffc);
    uStack_74 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    if ((*(ushort *)(iVar4 + 0x1e) & 0x20) != 0) {
      uStack_74 = uStack_74 & 0xffe0ffff;
    }
    uStack_70 = uRam02012b18;
    uVar6 = iVar4 + 0x14U & 3;
    uVar5 = *(uint *)(iVar4 + 0x14U & 0xfffffffc);
    uStack_6c = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    uStack_68 = (uint)*(ushort *)(iVar4 + 0x1c);
    func_01ff9048(uRam02012b14,(undefined4)(uintptr_t)(&uStack_7c),6);
    if ((*(ushort *)(iVar4 + 0x1e) & 1) != 0) {
      auStack_64[0] = 8;
      uStack_38 = *(undefined2 *)(iVar4 + 0x20);
      puVar1 = (undefined2 *)(iVar4 + 0x2c);
      uVar6 = iRam02012b1c + (uint)*(byte *)(param_1 + 0x16) * 4;
      uVar5 = uVar6 & 3;
      uVar2 = *(uint *)(uVar6 & 0xfffffffc);
      uStack_36 = *(undefined2 *)(iVar4 + 0x22);
      uVar6 = iVar4 + 0x24U & 3;
      uVar3 = *(uint *)(iVar4 + 0x24U & 0xfffffffc);
      uStack_34 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
      uVar6 = iVar4 + 0x28U & 3;
      uVar3 = *(uint *)(iVar4 + 0x28U & 0xfffffffc);
      uStack_30 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
      if ((*(ushort *)(iVar4 + 0x1e) & 2) == 0) {
        uStack_4c = *(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20;
        uVar6 = iVar4 + 0x30U & 3;
        uVar3 = *(uint *)(iVar4 + 0x30U & 0xfffffffc);
        uStack_48 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
        puVar1 = (undefined2 *)(iVar4 + 0x34);
      }
      else {
        auStack_64[0] = 9;
      }
      if ((*(ushort *)(iVar4 + 0x1e) & 4) == 0) {
        uStack_44 = *puVar1;
        uStack_42 = puVar1[1];
        puVar1 = puVar1 + 2;
      }
      else {
        auStack_64[0] = auStack_64[0] | 2;
      }
      if ((*(ushort *)(iVar4 + 0x1e) & 8) == 0) {
        uStack_40 = *(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20;
        uVar6 = (uint)(puVar1 + 2) & 3;
        uVar3 = *(uint *)((uint)(puVar1 + 2) & 0xfffffffc);
        uStack_3c = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
      }
      else {
        auStack_64[0] = auStack_64[0] | 4;
      }
      (*(code *)(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20))(auStack_64);
    }
  }
  uVar6 = param_1 + 0xcU & 3;
  uVar5 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  iVar4 = param_1 + (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20);
  uVar6 = (uint)*(ushort *)(iVar4 + (uint)*(ushort *)(iVar4 + 6)) * param_3 +
          iVar4 + (uint)*(ushort *)(iVar4 + 6) + 4;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  iVar4 = iVar4 + (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
  uVar6 = iVar4 + 8U & 3;
  uVar2 = *(uint *)(iVar4 + 8U & 0xfffffffc);
  uVar5 = iVar4 + 0xcU & 3;
  uVar3 = *(uint *)(iVar4 + 0xcU & 0xfffffffc);
  func_01ff9144(iVar4 + (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20),
                uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20);
  uVar6 = param_1 + 0x20U & 3;
  uVar5 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uStack_20 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  if (uStack_20 == 0x1000) {
    return;
  }
  uStack_1c = uStack_20;
  uStack_18 = uStack_20;
  func_01ff9048(0x1b,(undefined4)(uintptr_t)(&uStack_20),3);
  return;
}

