/* Decompiled C draft; module arm9; ROM address 020d5114. No matching claim. */
#include "types.h"
#include "deps/020d5114_func_020d5114.h"

void func_020d5114(short param_1)

{
  int iVar1;
  
  iVar1 = (*(uint *)(uRam020d5140 & 0xfffffffc) >> (uRam020d5140 & 3) * 8 |
          *(uint *)(uRam020d5140 & 0xfffffffc) << (uRam020d5140 & 3) * -8 + 0x20) + 0x14;
  *(ushort *)(iVar1 + param_1 * 0x1c) = *(ushort *)(iVar1 + param_1 * 0x1c) | *puRam020d5144;
  return;
}

