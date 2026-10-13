/* Decompiled C draft; module arm9; ROM address 020e79c4. No matching claim. */
#include "types.h"
#include "deps/020e79c4_func_020e79c4.h"

void func_020e79c4(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = (*(uint *)(uRam020e7a10 & 0xfffffffc) >> (uRam020e7a10 & 3) * 8 |
          *(uint *)(uRam020e7a10 & 0xfffffffc) << (uRam020e7a10 & 3) * -8 + 0x20) + 0xc;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) != 6) {
    uVar3 = func_02108e6c(4);
    func_0212c6f0(uVar3,1);
    *puRam020e7a14 = 0;
    return;
  }
  return;
}

