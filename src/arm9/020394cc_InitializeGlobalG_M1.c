/* Decompiled C draft; module arm9; ROM address 020394cc. No matching claim. */
#include "types.h"
#include "deps/020394cc_InitializeGlobalG_M1.h"

void InitializeGlobalG_M1(void)

{
  undefined2 *puVar1;
  
  puVar1 = puRam0203951c;
  *puRam0203951c = 0;
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

