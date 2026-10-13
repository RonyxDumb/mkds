/* Decompiled C draft; module arm9; ROM address 0203e74c. No matching claim. */
#include "types.h"
#include "deps/0203e74c_func_0203e74c.h"

void func_0203e74c(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam0203e784 & 0xfffffffc) >> (uRam0203e784 & 3) * 8 |
          *(uint *)(uRam0203e784 & 0xfffffffc) << (uRam0203e784 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 4) {
    func_0203e788(param_1,0);
    return;
  }
  return;
}

