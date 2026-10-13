/* Decompiled C draft; module arm9; ROM address 02039c7c. No matching claim. */
#include "types.h"
#include "deps/02039c7c_SomeVramInit.h"

void SomeVramInit(void)

{
  undefined4 *puVar1;
  
  puVar1 = puRam02039c94;
  *puRam02039c94 = 1;
  puVar1[1] = 0;
  return;
}

