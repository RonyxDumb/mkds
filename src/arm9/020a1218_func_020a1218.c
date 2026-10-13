/* Decompiled C draft; module arm9; ROM address 020a1218. No matching claim. */
#include "types.h"
#include "deps/020a1218_func_020a1218.h"

void func_020a1218(short param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(uRam020a1234 & 0xfffffffc) >> (uRam020a1234 & 3) * 8 |
          *(uint *)(uRam020a1234 & 0xfffffffc) << (uRam020a1234 & 3) * -8 + 0x20;
  *(short *)(uVar1 + 0x3a0) = *(short *)(uVar1 + 0x3a0) + param_1;
  return;
}

