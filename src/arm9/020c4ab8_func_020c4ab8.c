/* Decompiled C draft; module arm9; ROM address 020c4ab8. No matching claim. */
#include "types.h"
#include "deps/020c4ab8_func_020c4ab8.h"

void func_020c4ab8(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020c4ae0 & 0xfffffffc) >> (uRam020c4ae0 & 3) * 8 |
          *(uint *)(uRam020c4ae0 & 0xfffffffc) << (uRam020c4ae0 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 1) {
    *(undefined4 *)
     ((*(uint *)(uRam020c4ae4 & 0xfffffffc) >> (uRam020c4ae4 & 3) * 8 |
      *(uint *)(uRam020c4ae4 & 0xfffffffc) << (uRam020c4ae4 & 3) * -8 + 0x20) + param_1 * 4 + 4) = 0
    ;
  }
  return;
}

