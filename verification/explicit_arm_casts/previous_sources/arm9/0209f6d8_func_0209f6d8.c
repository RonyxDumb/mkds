/* Decompiled C draft; module arm9; ROM address 0209f6d8. No matching claim. */
#include "types.h"
#include "deps/0209f6d8_func_0209f6d8.h"

void func_0209f6d8(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  uint uStack_18;
  int iStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  uVar3 = param_2 + 0xa4U & 3;
  uVar5 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
  uVar2 = param_2 + 0xa8U & 3;
  uVar1 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
  piVar7 = (int *)(param_2 + 0xa4);
  *(uint *)(param_2 + 0xa4) =
       (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) +
       (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
  uVar3 = param_2 + 0xa8U & 3;
  uVar2 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
  piVar6 = (int *)(param_2 + 0xa8);
  *(uint *)(param_2 + 0xa8) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x4000;
  uVar3 = param_2 + 0xa4U & 3;
  uVar2 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 == 0) {
    uVar3 = param_2 + 0xa8U & 3;
    uVar2 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    *piVar7 = (*(uint *)((uint)piVar7 & 0xfffffffc) >> ((uint)piVar7 & 3) * 8 |
              *(uint *)((uint)piVar7 & 0xfffffffc) << ((uint)piVar7 & 3) * -8 + 0x20) +
              (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
    *piVar6 = (*(uint *)((uint)piVar6 & 0xfffffffc) >> ((uint)piVar6 & 3) * 8 |
              *(uint *)((uint)piVar6 & 0xfffffffc) << ((uint)piVar6 & 3) * -8 + 0x20) + 0x4000;
  }
  else if (0x16bfff < (int)uVar3) {
    uVar3 = param_2 + 0xa8U & 3;
    uVar2 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    *(uint *)(param_2 + 0xa8) = 0x4000 - (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
    uVar3 = param_2 + 0xacU & 3;
    uVar2 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    *(uint *)(param_2 + 0xac) = (uint)(uVar2 >> uVar3 * 8 == 0 && uVar2 << uVar3 * -8 + 0x20 == 0);
  }
  if (*(short *)(param_2 + 0xa2) == 0) {
    return;
  }
  iVar4 = func_0210f744(0);
  uVar3 = param_2 + 0x9cU & 3;
  uVar2 = *(uint *)(param_2 + 0x9cU & 0xfffffffc);
  if (*(short *)((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x28) != iVar4) {
    return;
  }
  uVar3 = param_2 + 0x78U & 3;
  uVar2 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
  uStack_18 = (uint)*(ushort *)(param_2 + 0xa2);
  if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 4) == 0) {
    uVar3 = param_2 + 0x70U & 3;
    uVar2 = *(uint *)(param_2 + 0x70U & 0xfffffffc);
    uVar1 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    uVar3 = iRam0209f7fc + 0x68U & 3;
    uVar2 = *(uint *)(iRam0209f7fc + 0x68U & 0xfffffffc);
    if (uVar1 == (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
      uStack_10 = 2;
    }
    else {
      uVar3 = iRam0209f7fc + 0x8cU & 3;
      uVar2 = *(uint *)(iRam0209f7fc + 0x8cU & 0xfffffffc);
      if (uVar1 == (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
        uStack_10 = 3;
      }
      else {
        uStack_10 = 4;
      }
    }
    iStack_14 = param_2 + 4;
    uStack_c = func_020d4ef4();
    func_0210b7a8(&uStack_18);
    return;
  }
  return;
}

