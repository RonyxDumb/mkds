/* Decompiled C draft; module arm9; ROM address 020fae74. No matching claim. */
#include "types.h"
#include "deps/020fae74_func_020fae74.h"

void func_020fae74(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (*(short *)(param_1 + 0x2f6) != 7) {
    func_020faed0();
    return;
  }
  uVar3 = param_1 + 0x2b0U & 3;
  uVar2 = *(uint *)(param_1 + 0x2b0U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 != 0) {
    uVar2 = param_1 + 0x74U & 3;
    uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    *(uint *)(uVar3 + 0xb4) =
         (uint)(((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x10000) == 0);
    return;
  }
  return;
}

