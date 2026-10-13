/* Decompiled C draft; module arm9; ROM address 0207a11c. No matching claim. */
#include "types.h"
#include "deps/0207a11c_func_0207a11c.h"

undefined2 func_0207a11c(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam0207a130 & 0xfffffffc) >> (uRam0207a130 & 3) * 8 |
          *(uint *)(uRam0207a130 & 0xfffffffc) << (uRam0207a130 & 3) * -8 + 0x20) + 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return *(undefined2 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 6);
}

