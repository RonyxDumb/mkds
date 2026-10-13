/* Decompiled C draft; module arm9; ROM address 020a1048. No matching claim. */
#include "types.h"
#include "deps/020a1048_func_020a1048.h"

undefined4 func_020a1048(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar4;
  undefined4 uVar5;
  uint uVar3;
  
  uVar4 = *(uint *)(uRam020a1080 & 0xfffffffc) >> (uRam020a1080 & 3) * 8 |
          *(uint *)(uRam020a1080 & 0xfffffffc) << (uRam020a1080 & 3) * -8 + 0x20;
  uVar5 = 0;
  uVar2 = param_1 * 0x70 + uVar4 + 0x4c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar2 = uVar4 + 0x3b0 & 3;
  uVar1 = *(uint *)(uVar4 + 0x3b0 & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) == uVar3) &&
     (uVar2 = uVar4 + 0x3ac & 3, uVar1 = *(uint *)(uVar4 + 0x3ac & 0xfffffffc),
     (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) != uVar3)) {
    uVar5 = 1;
  }
  return uVar5;
}

