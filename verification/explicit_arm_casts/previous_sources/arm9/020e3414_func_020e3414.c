/* Decompiled C draft; module arm9; ROM address 020e3414. No matching claim. */
#include "types.h"
#include "deps/020e3414_func_020e3414.h"

void func_020e3414(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uStack_18;
  int iStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  uVar1 = param_1 + 8U & 3;
  uVar4 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar3 = param_1 + 0x14U & 3;
  uVar2 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  *(uint *)(param_1 + 8) =
       (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) +
       (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
  uVar1 = param_1 + 8U & 3;
  uVar4 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar3 = param_1 + 0xacU & 3;
  uVar2 = *(uint *)(param_1 + 0xacU & 0xfffffffc);
  if ((int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) <
      (int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
    uVar1 = param_1 + 0x78U & 3;
    uVar3 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
    if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 4) == 0) {
      uVar1 = param_1 + 0x70U & 3;
      uVar3 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
      uVar2 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
      uVar1 = iRam020e34bc + 0x68U & 3;
      uVar3 = *(uint *)(iRam020e34bc + 0x68U & 0xfffffffc);
      if (uVar2 == (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20)) {
        uStack_10 = 2;
      }
      else {
        uVar1 = iRam020e34bc + 0x8cU & 3;
        uVar3 = *(uint *)(iRam020e34bc + 0x8cU & 0xfffffffc);
        if (uVar2 == (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20)) {
          uStack_10 = 3;
        }
        else {
          uStack_10 = 4;
        }
      }
      iStack_14 = param_1 + 4;
      uStack_18 = 0x128;
      uStack_c = func_020d4ef4();
      func_0210b7a8(&uStack_18);
    }
    *(undefined2 *)(param_1 + 0x90) = 4;
    *(undefined2 *)(param_1 + 0x92) = 1;
    return;
  }
  return;
}

