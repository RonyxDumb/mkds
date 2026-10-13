/* Decompiled C draft; module arm9; ROM address 020f758c. No matching claim. */
#include "types.h"
#include "deps/020f758c_func_020f758c.h"

void func_020f758c(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x8000) != 0) {
    func_020f68b0();
  }
  *(short *)(param_1 + 0xd8) = *(short *)(param_1 + 0xd8) + -1;
  if (0 < *(short *)(param_1 + 0xd8)) {
    if (*(short *)(param_1 + 0xd8) < 10) {
      func_020f9c40(param_1);
      return;
    }
    return;
  }
  uVar1 = param_1 + 0x44U & 3;
  uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  func_020f0f70((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) * 0x44 +
                (*(uint *)(uRam020f75fc & 0xfffffffc) >> (uRam020f75fc & 3) * 8 |
                *(uint *)(uRam020f75fc & 0xfffffffc) << (uRam020f75fc & 3) * -8 + 0x20),param_1);
  return;
}

