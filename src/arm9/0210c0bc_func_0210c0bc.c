/* Decompiled C draft; module arm9; ROM address 0210c0bc. No matching claim. */
#include "types.h"
#include "deps/0210c0bc_func_0210c0bc.h"

void func_0210c0bc(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  func_0210c238(param_1,0);
  uVar2 = param_1 + 0xcU & 3;
  uVar1 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  if (uVar1 >> uVar2 * 8 != 0 || uVar1 << uVar2 * -8 + 0x20 != 0) {
    do {
      func_0210bc54(param_1 + 0xc);
      uVar2 = param_1 + 0xcU & 3;
      uVar1 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    } while (uVar1 >> uVar2 * 8 != 0 || uVar1 << uVar2 * -8 + 0x20 != 0);
  }
  uVar2 = param_1 + 0x18U & 3;
  uVar1 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 != 3) {
    func_0210bc54(uVar2 * 0xc + iRam0210c130,param_1);
    *(undefined4 *)(param_1 + 0x18) = 3;
    return;
  }
  return;
}

