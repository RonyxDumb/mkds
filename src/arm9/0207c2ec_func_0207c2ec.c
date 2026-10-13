/* Decompiled C draft; module arm9; ROM address 0207c2ec. No matching claim. */
#include "types.h"
#include "deps/0207c2ec_func_0207c2ec.h"

void func_0207c2ec(int param_1,uint param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = func_01ffc67c(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                        *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20);
  if (iVar2 != 0) {
    return;
  }
  uVar1 = *(ushort *)(param_2 + 4);
  uVar3 = func_02061f90();
  if (uVar1 == uVar3) {
    iVar2 = (uint)uVar1 * 0x210 +
            (*(uint *)(uRam0207c444 & 0xfffffffc) >> (uRam0207c444 & 3) * 8 |
            *(uint *)(uRam0207c444 & 0xfffffffc) << (uRam0207c444 & 3) * -8 + 0x20);
    uVar3 = iVar2 + 0x58;
    uVar4 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if (((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) == 0xf) ||
       (uVar3 = param_1 + 8U & 3, uVar4 = *(uint *)(param_1 + 8U & 0xfffffffc),
       uVar3 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20, uVar3 == 0)) {
      uVar3 = param_1 + 4U & 3;
      uVar4 = *(uint *)(param_1 + 4U & 0xfffffffc);
      uVar5 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
      uVar3 = iVar2 + 0x30;
      uVar4 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      if (uVar5 == 0 || (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) == 0x13) {
        uVar3 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) + 0x78;
        uVar4 = uVar3 & 3;
        uVar3 = *(uint *)(uVar3 & 0xfffffffc);
        func_0204360c(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20,0x600);
      }
      else {
        (*(code *)(*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                  *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20))(param_1,param_2);
      }
    }
    else {
      (*(code *)(*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20))(param_1,param_2);
    }
  }
  else {
    uVar3 = param_1 + 0x14U & 3;
    uVar4 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
    if (uVar4 >> uVar3 * 8 == 0 && uVar4 << uVar3 * -8 + 0x20 == 0) {
      uVar3 = param_1 + 0x18U & 3;
      uVar4 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
      if (uVar4 >> uVar3 * 8 != 0 || uVar4 << uVar3 * -8 + 0x20 != 0) {
        uVar3 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) + 0x78;
        uVar4 = uVar3 & 3;
        uVar3 = *(uint *)(uVar3 & 0xfffffffc);
        func_0204360c(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20,0x80);
        *(short *)(param_1 + 0x1e) = *(short *)(param_1 + 0x1e) + -1;
        if (*(short *)(param_1 + 0x1e) < 1) {
          *(undefined4 *)(param_1 + 0x18) = 0;
        }
      }
    }
    else {
      uVar3 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
              *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) + 0x78;
      uVar4 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      func_0204360c(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20,0x40);
      *(short *)(param_1 + 0x1c) = *(short *)(param_1 + 0x1c) + -1;
      if (*(short *)(param_1 + 0x1c) < 1) {
        *(undefined4 *)(param_1 + 0x14) = 0;
      }
    }
  }
  uVar3 = param_1 + 0x10U & 3;
  uVar4 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  if (uVar4 >> uVar3 * 8 != 0 || uVar4 << uVar3 * -8 + 0x20 != 0) {
    uVar3 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
            *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) + 0x78;
    uVar4 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    func_0204360c(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20,0x600);
    return;
  }
  return;
}

