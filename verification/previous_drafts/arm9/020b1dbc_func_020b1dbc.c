/* Decompiled C draft; module arm9; ROM address 020b1dbc. No matching claim. */
#include "types.h"
#include "deps/020b1dbc_func_020b1dbc.h"

uint func_020b1dbc(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020b1dcc & 0xfffffffc) >> (uRam020b1dcc & 3) * 8 |
          *(uint *)(uRam020b1dcc & 0xfffffffc) << (uRam020b1dcc & 3) * -8 + 0x20) + 0x828;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

