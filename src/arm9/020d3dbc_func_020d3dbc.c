/* Decompiled C draft; module arm9; ROM address 020d3dbc. No matching claim. */
#include "types.h"
#include "deps/020d3dbc_func_020d3dbc.h"

undefined2 func_020d3dbc(void)

{
  undefined2 uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(uRam020d3dd4 & 0xfffffffc) >> (uRam020d3dd4 & 3) * 8 |
          *(uint *)(uRam020d3dd4 & 0xfffffffc) << (uRam020d3dd4 & 3) * -8 + 0x20;
  if (uVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined2 *)(uVar2 + 0x2c);
  }
  return uVar1;
}

