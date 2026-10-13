/* Decompiled C draft; module arm9; ROM address 020df3f8. No matching claim. */
#include "types.h"
#include "deps/020df3f8_func_020df3f8.h"

void func_020df3f8(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  *puRam020df414 = 0;
  *puRam020df418 = 0;
  uVar1 = uRam020df41c;
  *puRam020df420 = uRam020df41c;
  puVar2 = puRam020df424;
  *puRam020df424 = uVar1;
  puVar2[1] = uVar1;
  puVar2[2] = uVar1;
  return;
}

