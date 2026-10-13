/* Decompiled C draft; module arm9; ROM address 0207a70c. No matching claim. */
#include "types.h"
#include "deps/0207a70c_func_0207a70c.h"

void func_0207a70c(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 ==
      *(char *)((*(uint *)(uRam0207a734 & 0xfffffffc) >> (uRam0207a734 & 3) * 8 |
                *(uint *)(uRam0207a734 & 0xfffffffc) << (uRam0207a734 & 3) * -8 + 0x20) + 0x62)) {
    uVar3 = *(uint *)(uRam0207a738 & 0xfffffffc) >> (uRam0207a738 & 3) * 8 |
            *(uint *)(uRam0207a738 & 0xfffffffc) << (uRam0207a738 & 3) * -8 + 0x20;
    uVar2 = uVar3 + 8;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    *(uint *)(uVar3 + 8) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 1;
  }
  return;
}

