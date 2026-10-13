/* Decompiled C draft; module arm9; ROM address 020ec918. No matching claim. */
#include "types.h"
#include "deps/020ec918_func_020ec918.h"

void func_020ec918(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = param_1 + 0x214U & 3;
  uVar3 = *(uint *)(param_1 + 0x214U & 0xfffffffc);
  if ((int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) < 0) {
    func_020ec9c0();
    return;
  }
  func_020ece1c(param_1,param_2,param_4,param_5);
  uVar1 = param_1 + 0x214U & 3;
  uVar3 = *(uint *)(param_1 + 0x214U & 0xfffffffc);
  if (uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0) {
    uVar1 = param_1 + 0x74U & 3;
    uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    if ((((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & uRam020ec9bc) != 0) &&
       (uVar1 = param_1 + 0x158U & 3, uVar3 = *(uint *)(param_1 + 0x158U & 0xfffffffc),
       uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0)) {
      return;
    }
    uVar1 = param_1 + 0x214U & 3;
    uVar3 = *(uint *)(param_1 + 0x214U & 0xfffffffc);
    *(uint *)(param_1 + 0x214) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) - 1;
    return;
  }
  iVar2 = func_020ed0f4(param_1);
  if (iVar2 != 0) {
    *(undefined4 *)(param_1 + 0x214) = 0xffffffff;
  }
  return;
}

