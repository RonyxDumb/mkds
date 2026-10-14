/* Decompiled C draft; module arm9; ROM address 02147cd8. No matching claim. */
#include "types.h"
#include "deps/02147cd8_func_02147cd8.h"

uint func_02147cd8(undefined4 param_1,undefined4 param_2)

{
  ushort *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = puRam02147d24;
  puVar1 = puRam02147d20;
  *puRam02147d20 = 0;
  puVar3 = puRam02147d28;
  *puVar2 = param_1;
  *puVar3 = param_2;
  puVar3[1] = 0;
  do {
  } while ((*puVar1 & 0x8000) != 0);
  return *(uint *)(uRam02147d2c & 0xfffffffc) >> (uRam02147d2c & 3) * 8 |
         *(uint *)(uRam02147d2c & 0xfffffffc) << (uRam02147d2c & 3) * -8 + 0x20;
}

