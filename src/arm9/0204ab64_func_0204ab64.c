/* Decompiled C draft; module arm9; ROM address 0204ab64. No matching claim. */
#include "types.h"
#include "deps/0204ab64_func_0204ab64.h"

void func_0204ab64(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(uRam0204aba4 & 0xfffffffc) >> (uRam0204aba4 & 3) * 8 |
          *(uint *)(uRam0204aba4 & 0xfffffffc) << (uRam0204aba4 & 3) * -8 + 0x20;
  uVar2 = uVar3 + 0x1c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((int)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) << 0x1f) < 0) {
    func_0210dca8(uVar3 + 8,param_1);
    return;
  }
  return;
}

