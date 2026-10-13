/* Decompiled C draft; module arm9; ROM address 02147d30. No matching claim. */
#include "types.h"
#include "deps/02147d30_Fx_DivS32.h"

uint Fx_DivS32(undefined4 param_1,undefined4 param_2)

{
  ushort *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = puRam02147d7c;
  puVar1 = puRam02147d78;
  *puRam02147d78 = 0;
  puVar3 = puRam02147d80;
  *puVar2 = param_1;
  *puVar3 = param_2;
  puVar3[1] = 0;
  do {
  } while ((*puVar1 & 0x8000) != 0);
  return *(uint *)(uRam02147d84 & 0xfffffffc) >> (uRam02147d84 & 3) * 8 |
         *(uint *)(uRam02147d84 & 0xfffffffc) << (uRam02147d84 & 3) * -8 + 0x20;
}

