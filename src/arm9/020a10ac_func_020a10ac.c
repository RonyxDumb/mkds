/* Decompiled C draft; module arm9; ROM address 020a10ac. No matching claim. */
#include "types.h"
#include "deps/020a10ac_func_020a10ac.h"

void func_020a10ac(int param_1,short param_2)

{
  int iVar1;
  
  iVar1 = (*(uint *)(uRam020a10d0 & 0xfffffffc) >> (uRam020a10d0 & 3) * 8 |
          *(uint *)(uRam020a10d0 & 0xfffffffc) << (uRam020a10d0 & 3) * -8 + 0x20) + 0x50;
  *(short *)(iVar1 + param_1 * 0x70) = *(short *)(iVar1 + param_1 * 0x70) + param_2;
  return;
}

