/* Decompiled C draft; module arm9; ROM address 020d50ec. No matching claim. */
#include "types.h"
#include "deps/020d50ec_func_020d50ec.h"

void func_020d50ec(short param_1)

{
  int iVar1;
  
  iVar1 = (*(uint *)(uRam020d5110 & 0xfffffffc) >> (uRam020d5110 & 3) * 8 |
          *(uint *)(uRam020d5110 & 0xfffffffc) << (uRam020d5110 & 3) * -8 + 0x20) + 0x14;
  *(ushort *)(iVar1 + param_1 * 0x1c) = *(ushort *)(iVar1 + param_1 * 0x1c) & 0xfdff;
  return;
}

