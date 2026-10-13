/* Decompiled C draft; module arm9; ROM address 020a1084. No matching claim. */
#include "types.h"
#include "deps/020a1084_func_020a1084.h"

bool func_020a1084(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 * 0x70 +
          (*(uint *)(uRam020a10a8 & 0xfffffffc) >> (uRam020a10a8 & 3) * 8 |
          *(uint *)(uRam020a10a8 & 0xfffffffc) << (uRam020a10a8 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0;
}

