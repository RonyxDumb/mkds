/* Decompiled C draft; module arm9; ROM address 020a1154. No matching claim. */
#include "types.h"
#include "deps/020a1154_func_020a1154.h"

uint func_020a1154(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 * 0x70 +
          (*(uint *)(uRam020a117c & 0xfffffffc) >> (uRam020a117c & 3) * 8 |
          *(uint *)(uRam020a117c & 0xfffffffc) << (uRam020a117c & 3) * -8 + 0x20) + 0x4c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  if ((int)uVar2 < 1) {
    uVar2 = 0;
  }
  return uVar2 & 0xffff;
}

