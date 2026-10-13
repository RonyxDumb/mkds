/* Decompiled C draft; module arm9; ROM address 02093cf4. No matching claim. */
#include "types.h"
#include "deps/02093cf4_func_02093cf4.h"

void func_02093cf4(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 local_18;
  int local_14;
  undefined4 uStack_10;
  undefined4 local_c;
  
  uVar4 = param_2 + 0xa8U & 3;
  uVar1 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
  switch(uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) {
  case 0:
    break;
  case 1:
    iVar3 = func_020d8cc8(param_2 + 0xac);
    if (iVar3 != 0) {
      *(undefined4 *)(param_2 + 0xa0) = 0x2d;
      *(undefined4 *)(param_2 + 0xa8) = 2;
    }
    func_020d879c(param_2 + 0xac,param_2 + 4);
    return;
  case 2:
    uVar4 = param_2 + 0xa0U & 3;
    uVar1 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
    uVar4 = uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20;
    if (uVar4 == 0x2d) {
      uVar4 = param_2 + 0x78U & 3;
      uVar1 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
      if (((uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) & 4) == 0) {
        uVar5 = func_02108e6c(8);
        func_0212c6f0(uVar5,0);
        local_18 = *DAT_02093ea8;
        uStack_10 = DAT_02093ea8[2];
        local_c = DAT_02093ea8[3];
        local_14 = param_2 + 4;
        local_c = func_020d4ef4();
        uVar5 = func_02108e6c(8);
        func_0210b708(&local_18,uVar5);
      }
    }
    else if ((int)uVar4 < 1) {
      *(undefined4 *)(param_2 + 0xa0) = 0;
      *(undefined4 *)(param_2 + 0xa8) = 3;
    }
    uVar4 = param_2 + 0xa0U & 3;
    uVar1 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
    *(uint *)(param_2 + 0xa0) = (uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) - 1;
    return;
  case 3:
    func_020937c4(param_2 + 4,param_2 + 0x40,*(undefined2 *)(param_2 + 0x7e));
    if ((*(ushort *)(param_2 + 2) & 0x12) == 0) {
      func_0208b7bc(0x4b,param_2 + 4);
      func_0208b7bc(0x4c,param_2 + 4);
      func_0208b7bc(0x4d,param_2 + 4);
    }
    *(undefined4 *)(param_2 + 0xa0) = 0x4b;
    *(undefined4 *)(param_2 + 0xa8) = 0;
  default:
    return;
  }
  uVar4 = param_2 + 0xa0U & 3;
  uVar1 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
  uVar4 = uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20;
  *(uint *)(param_2 + 0xa0) = uVar4 - 1;
  if ((int)uVar4 < 1) {
    *(undefined4 *)(param_2 + 0xb0) = 0x2000;
    uVar4 = param_2 + 0xacU & 3;
    uVar1 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    uVar2 = uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20;
    uVar4 = param_2 + 0xb8U & 3;
    uVar6 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar4 = (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) * 0x54 +
            (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x34;
    uVar1 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar4 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
    *(uint *)(param_2 + 0xbc) = (uVar4 << 0xd) >> 0xc | (uVar4 >> 0x13) << 0x14;
    *(undefined4 *)(param_2 + 0xa8) = 1;
    return;
  }
  return;
}

