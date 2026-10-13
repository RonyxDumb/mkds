/* Decompiled C draft; module arm9; ROM address 021001ac. No matching claim. */
#include "types.h"
#include "deps/021001ac_func_021001ac.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_021001ac(int param_1,undefined4 param_2,int param_3)

{
  ushort uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  uint uStack_2c;
  uint uStack_28;
  
  if (0 < *(short *)(param_1 + 0xd8)) {
    uStack_38 = 0x1e;
    func_01ff9048(0x14,(undefined4)(uintptr_t)(&uStack_38),1);
    uVar8 = param_1 + 0xd0U & 3;
    uVar2 = *(uint *)(param_1 + 0xd0U & 0xfffffffc);
    uVar3 = func_020e6cf8(uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20);
    func_01ff9048(0x19,uVar3,0xc);
    uVar8 = param_1 + 0x70U & 3;
    uVar2 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
    uStack_28 = uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20;
    uVar8 = param_1 + 0x6cU & 3;
    uVar2 = *(uint *)(param_1 + 0x6cU & 0xfffffffc);
    uStack_2c = uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20;
    uVar8 = param_1 + 0x68U & 3;
    uVar2 = *(uint *)(param_1 + 0x68U & 0xfffffffc);
    uStack_30 = uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20;
    func_01ff9048(0x1b,(undefined4)(uintptr_t)(&uStack_30),3);
    uVar8 = param_1 + 0x160U & 3;
    uVar2 = *(uint *)(param_1 + 0x160U & 0xfffffffc);
    if (((int)(uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20) < 0xe) &&
       (2 < *(ushort *)(param_1 + 0x13a))) {
      iVar4 = MaybeGetItemByIndex();
      iVar7 = (int)*(short *)(param_1 + 0xd8);
      iStack_3c = (int)*(short *)(param_1 + 0x164);
      uVar8 = param_1 + 0x158U & 3;
      uVar2 = *(uint *)(param_1 + 0x158U & 0xfffffffc);
      uVar8 = uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20;
      if ((iVar7 < 0x1f) && (iVar7 < iStack_3c)) {
        iStack_3c = iVar7;
      }
      if (0x1f < iStack_3c) {
        iStack_3c = 0x1f;
      }
      if (iStack_3c < 1) {
        iStack_3c = 1;
      }
      func_01ff9048(0x11,0,0);
      uVar2 = iVar4 + 0x14U & 3;
      uVar6 = *(uint *)(iVar4 + 0x14U & 0xfffffffc);
      *(uint *)(iVar4 + 0x14) = (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) & 0xffe0ffff;
      uVar2 = iVar4 + 0x14U & 3;
      uVar6 = *(uint *)(iVar4 + 0x14U & 0xfffffffc);
      *(uint *)(iVar4 + 0x14) = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20 | iStack_3c << 0x10;
      func_020e6a18(iVar4);
      iVar7 = 0;
      *(undefined2 *)(iVar4 + 0x18) = 0;
      if (0 < (int)uVar8) {
        do {
          iVar5 = iVar7;
          if (uVar8 == 2) {
            iVar5 = -iVar7;
          }
          func_01ff9048(0x1c,(iVar5 + 1) * 0xc + iRam021003e4,3);
          iVar5 = func_020d3c44();
          uVar2 = iVar4 + 0x14U & 3;
          uVar6 = *(uint *)(iVar4 + 0x14U & 0xfffffffc);
          *(uint *)(iVar4 + 0x14) = (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) & 0xc0ffffff;
          uVar2 = iVar4 + 0x14U & 3;
          uVar6 = *(uint *)(iVar4 + 0x14U & 0xfffffffc);
          *(uint *)(iVar4 + 0x14) = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20 | iVar5 << 0x18;
          func_020e6854(iVar4,param_1 + 0x50,1,0x1f);
          iVar7 = iVar7 + 1;
        } while (iVar7 < (int)uVar8);
      }
      uStack_34 = 1;
      func_01ff9048(0x12,&uStack_34);
      if (iStack_3c != 0x1f) {
        uVar8 = iVar4 + 0x14U & 3;
        uVar2 = *(uint *)(iVar4 + 0x14U & 0xfffffffc);
        *(uint *)(iVar4 + 0x14) = (uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20) & 0xffe0ffff;
        uVar8 = iVar4 + 0x14U & 3;
        uVar2 = *(uint *)(iVar4 + 0x14U & 0xfffffffc);
        *(uint *)(iVar4 + 0x14) = uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20 | 0x1f0000;
      }
    }
    iVar4 = func_020d3c44();
    uVar8 = param_3 + 0x14U & 3;
    uVar2 = *(uint *)(param_3 + 0x14U & 0xfffffffc);
    *(uint *)(param_3 + 0x14) = (uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20) & 0xc0ffffff;
    uVar8 = param_3 + 0x14U & 3;
    uVar2 = *(uint *)(param_3 + 0x14U & 0xfffffffc);
    *(uint *)(param_3 + 0x14) = uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20 | iVar4 << 0x18;
    uVar8 = param_3 + 0x14U & 3;
    uVar2 = *(uint *)(param_3 + 0x14U & 0xfffffffc);
    uVar1 = *(ushort *)(param_1 + 0xd8);
    *(uint *)(param_3 + 0x14) = (uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20) & 0xffe0ffff;
    uVar8 = param_3 + 0x14U & 3;
    uVar2 = *(uint *)(param_3 + 0x14U & 0xfffffffc);
    *(uint *)(param_3 + 0x14) =
         uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20 | (uint)uVar1 << 0x10;
    func_020ed588(param_1);
    return;
  }
  return;
}

