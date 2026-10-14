/* Decompiled C draft; module arm9; ROM address 02021784. No matching claim. */
#include "types.h"
#include "deps/02021784_Sound_InitializeAlarms.h"

void Sound_InitializeAlarms(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  puVar1 = puRam020217b0;
  do {
    *puVar1 = 0;
    puVar1[1] = 0;
    iVar2 = iVar2 + 1;
    *(undefined1 *)(puVar1 + 2) = 0;
    puVar1 = puVar1 + 3;
  } while (iVar2 < 8);
  return;
}

