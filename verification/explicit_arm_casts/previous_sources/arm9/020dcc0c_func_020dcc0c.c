/* Decompiled C draft; module arm9; ROM address 020dcc0c. No matching claim. */
#include "types.h"
#include "deps/020dcc0c_func_020dcc0c.h"

void func_020dcc0c(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uStack_18;
  int iStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  uVar2 = uRam020dccbc;
  *(undefined4 *)(param_1 + 0xe8) = 0x2000;
  *(undefined4 *)(param_1 + 0xec) = uVar2;
  *(undefined4 *)(param_1 + 0x1e0) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0x1e4) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0x1e8) = *(undefined4 *)(param_1 + 0xc);
  uVar1 = param_1 + 0x1d8U & 3;
  uVar3 = *(uint *)(param_1 + 0x1d8U & 0xfffffffc);
  *(undefined4 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0xa8) = uRam020dccc0;
  *(undefined2 *)(param_1 + 0x1f8) = 0;
  uVar1 = param_1 + 0x78U & 3;
  uVar3 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
  if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 4) == 0) {
    uVar1 = param_1 + 0x70U & 3;
    uVar3 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
    uVar4 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
    uVar1 = iRam020dccc4 + 0x68U & 3;
    uVar3 = *(uint *)(iRam020dccc4 + 0x68U & 0xfffffffc);
    if (uVar4 == (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20)) {
      uStack_10 = 2;
    }
    else {
      uVar1 = iRam020dccc4 + 0x8cU & 3;
      uVar3 = *(uint *)(iRam020dccc4 + 0x8cU & 0xfffffffc);
      if (uVar4 == (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20)) {
        uStack_10 = 3;
      }
      else {
        uStack_10 = 4;
      }
    }
    iStack_14 = param_1 + 4;
    uStack_18 = 300;
    uStack_c = func_020d4ef4();
    func_0210b7a8(&uStack_18);
    return;
  }
  return;
}

