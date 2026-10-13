/* Decompiled C draft; module arm9; ROM address 020fe120. No matching claim. */
#include "types.h"
#include "deps/020fe120_func_020fe120.h"

void func_020fe120(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 + 0x74U & 3;
  uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if ((uVar2 & 0x8000) != 0) {
    func_020f68b0();
    return;
  }
  if ((uVar2 & 0x4000) != 0) {
    func_020f63cc();
    *(undefined4 *)(param_1 + 0x170) = 0x5a;
    *(undefined4 *)(param_1 + 0x174) = 0;
    return;
  }
  return;
}

