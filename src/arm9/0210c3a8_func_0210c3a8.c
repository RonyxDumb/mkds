/* Decompiled C draft; module arm9; ROM address 0210c3a8. No matching claim. */
#include "types.h"
#include "deps/0210c3a8_func_0210c3a8.h"

void func_0210c3a8(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 + 0xcU & 3;
  uVar1 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 != 0) {
    do {
      func_0212c6f0(uVar2,0);
      *(byte *)(uVar2 + 0x19) = *(byte *)(uVar2 + 0x19) & 0xfb;
      *(byte *)(uVar2 + 0x19) = *(byte *)(uVar2 + 0x19) & 0xf7;
      *(byte *)(uVar2 + 0x19) = *(byte *)(uVar2 + 0x19) & 0xfd;
      func_0210bc54(param_1 + 0xc,uVar2);
      uVar2 = param_1 + 0xcU & 3;
      uVar1 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    } while (uVar2 != 0);
  }
  uVar2 = param_1 + 0x18U & 3;
  uVar1 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 != 3) {
    func_0210bc54(uVar2 * 0xc + iRam0210c44c,param_1);
    *(undefined4 *)(param_1 + 0x18) = 3;
  }
  func_0210c1b0(param_1);
  return;
}

