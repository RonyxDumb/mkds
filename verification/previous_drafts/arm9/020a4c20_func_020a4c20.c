/* Decompiled C draft; module arm9; ROM address 020a4c20. No matching claim. */
#include "types.h"
#include "deps/020a4c20_func_020a4c20.h"

void func_020a4c20(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020a4c54 & 0xfffffffc) >> (uRam020a4c54 & 3) * 8 |
          *(uint *)(uRam020a4c54 & 0xfffffffc) << (uRam020a4c54 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 2) {
    func_020a305c();
    return;
  }
  return;
}

