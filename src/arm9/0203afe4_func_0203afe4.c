/* Decompiled C draft; module arm9; ROM address 0203afe4. No matching claim. */
#include "types.h"
#include "deps/0203afe4_func_0203afe4.h"

bool func_0203afe4(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam0203b010 & 0xfffffffc) >> (uRam0203b010 & 3) * 8 |
          *(uint *)(uRam0203b010 & 0xfffffffc) << (uRam0203b010 & 3) * -8 + 0x20) + 0xc;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 6) {
    return uRam0203b014 <= param_1;
  }
  return true;
}

