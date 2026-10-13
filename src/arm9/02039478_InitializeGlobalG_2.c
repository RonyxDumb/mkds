/* Decompiled C draft; module arm9; ROM address 02039478. No matching claim. */
#include "types.h"
#include "deps/02039478_InitializeGlobalG_2.h"

void InitializeGlobalG_2(void)

{
  undefined2 *puVar1;
  
  puVar1 = puRam020394c8;
  *puRam020394c8 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[7] = 0x14;
  puVar1[8] = 8;
  puVar1[9] = 0;
  puVar1[10] = 0;
  *(undefined4 *)(puVar1 + 0xc) = 0;
  *(undefined4 *)(puVar1 + 0xe) = 0;
  *(undefined4 *)(puVar1 + 0x10) = 0;
  *(undefined4 *)(puVar1 + 0x12) = 0;
  return;
}

