/* Decompiled C draft; module arm9; ROM address 0210d9a0. No matching claim. */
#include "types.h"
#include "deps/0210d9a0_func_0210d9a0.h"

void func_0210d9a0(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = func_0210d960();
  switch(param_2) {
  case 0:
    uVar4 = param_1 + 4 & 3;
    uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc);
    if (uVar3 >> uVar4 * 8 != 0 || uVar3 << uVar4 * -8 + 0x20 != 0) {
      func_0210d200(0);
      func_0210d120(0);
      func_0212c6f0((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                    *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x10,0);
      func_0212c6f0((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                    *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0xc,0);
      uVar4 = param_1 + 0x18 & 3;
      uVar3 = *(uint *)(param_1 + 0x18 & 0xfffffffc);
      uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      if (uVar4 != 0) {
        func_0212c6f0(uVar4,0);
      }
      *(undefined4 *)(param_1 + 0x10) = 0;
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    break;
  case 1:
    uVar4 = param_1 + 4 & 3;
    uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc);
    if ((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) != 1) {
      func_0210d200(0);
      func_0210d120(0);
      uVar4 = param_1 + 4 & 3;
      uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc);
      if ((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) == 5) {
        uVar1 = func_0210d960();
        func_0212c620((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                      *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0xc,0x7f,uVar1
                     );
        func_0212c620((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                      *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x10,0x7f,
                      uVar1);
        uVar4 = param_1 + 0x18 & 3;
        uVar3 = *(uint *)(param_1 + 0x18 & 0xfffffffc);
        uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
        if (uVar4 != 0) {
          func_0212c620(uVar4,0x7f,uVar1);
        }
      }
      *(undefined4 *)(param_1 + 0x10) = 0;
      *(undefined4 *)(param_1 + 0xc) = 1;
    }
    break;
  case 2:
    uVar4 = param_1 + 4 & 3;
    uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    if (uVar4 != 2) {
      if (uVar4 == 5) {
        uVar2 = func_0210d960();
        func_0212c620((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                      *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0xc,0x7f,uVar2
                     );
        func_0212c620((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                      *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x10,0x7f,
                      uVar2);
        uVar4 = param_1 + 0x18 & 3;
        uVar3 = *(uint *)(param_1 + 0x18 & 0xfffffffc);
        uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
        if (uVar4 != 0) {
          func_0212c620(uVar4,0x7f,uVar2);
        }
        func_0210d1a4(0x7f,uVar1);
      }
      *(undefined4 *)(param_1 + 0x10) = 1;
      *(undefined4 *)(param_1 + 0xc) = 1;
    }
    break;
  case 3:
    uVar4 = param_1 + 4 & 3;
    uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc);
    if ((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) != 3) {
      *(undefined4 *)(param_1 + 0x10) = 0;
      *(undefined4 *)(param_1 + 0xc) = 0;
      func_0210d200(5);
      func_0210d120(5);
      func_0212c6f0((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                    *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x10,5);
    }
    break;
  case 4:
    uVar4 = param_1 + 4 & 3;
    uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc);
    if ((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) != 4) {
      *(undefined4 *)(param_1 + 0x10) = 0;
      *(undefined4 *)(param_1 + 0xc) = 0;
      func_0210d200();
      func_0210d120(uVar1);
      func_0212c6f0((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                    *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x10,uVar1);
      func_0212c6f0((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                    *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0xc,uVar1);
      uVar4 = param_1 + 0x18 & 3;
      uVar3 = *(uint *)(param_1 + 0x18 & 0xfffffffc);
      uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      if (uVar4 != 0) {
        func_0212c6f0(uVar4,uVar1);
      }
    }
    break;
  case 5:
    uVar4 = param_1 + 4 & 3;
    uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc);
    if ((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) != 5) {
      func_0212c620((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                    *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0xc,0,uVar1);
      func_0212c620((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                    *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x10,0,uVar1);
      uVar4 = param_1 + 0x18 & 3;
      uVar3 = *(uint *)(param_1 + 0x18 & 0xfffffffc);
      uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      if (uVar4 != 0) {
        func_0212c620(uVar4,0,uVar1);
      }
      *(undefined4 *)(param_1 + 0x10) = 0;
      *(undefined4 *)(param_1 + 0xc) = 0;
      func_0210d1a4(0,uVar1);
      uVar4 = param_1 + 4 & 3;
      uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc);
      *(uint *)(param_1 + 8) = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    }
  }
  *(undefined4 *)(param_1 + 4) = param_2;
  return;
}

