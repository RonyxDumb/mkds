/* Decompiled C draft; module arm9; ROM address 020a3f48. No matching claim. */
#include "types.h"
#include "deps/020a3f48_func_020a3f48.h"

void func_020a3f48(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *(uint *)(uRam020a3fa4 & 0xfffffffc) >> (uRam020a3fa4 & 3) * 8 |
          *(uint *)(uRam020a3fa4 & 0xfffffffc) << (uRam020a3fa4 & 3) * -8 + 0x20;
  uVar3 = uVar1 + 8 & 3;
  uVar2 = *(uint *)(uVar1 + 8 & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if ((uVar3 == 2) &&
     (uVar2 = uVar1 + 0x18 & 3, uVar1 = *(uint *)(uVar1 + 0x18 & 0xfffffffc),
     uVar1 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20, uVar1 == 0)) {
    func_0209bf8c();
    return;
  }
  if (uVar3 == 4) {
    func_0209bf8c(uVar1);
    return;
  }
  return;
}

