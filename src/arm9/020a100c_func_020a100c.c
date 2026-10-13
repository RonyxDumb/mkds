/* Decompiled C draft; module arm9; ROM address 020a100c. No matching claim. */
#include "types.h"
#include "deps/020a100c_func_020a100c.h"

undefined4 func_020a100c(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar3 = *(uint *)(uRam020a1044 & 0xfffffffc) >> (uRam020a1044 & 3) * 8 |
          *(uint *)(uRam020a1044 & 0xfffffffc) << (uRam020a1044 & 3) * -8 + 0x20;
  uVar4 = 0;
  uVar1 = uVar3 + 0x3b4 & 3;
  uVar2 = *(uint *)(uVar3 + 0x3b4 & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) ==
       (uint)*(ushort *)(param_1 * 0x70 + uVar3 + 0x46)) &&
     (uVar1 = uVar3 + 0x3a8 & 3, uVar2 = *(uint *)(uVar3 + 0x3a8 & 0xfffffffc),
     (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) < 0)) {
    uVar4 = 1;
  }
  return uVar4;
}

