/* Decompiled C draft; module arm7; ROM address 037ff400. No matching claim. */
#include "types.h"
#include "deps/037ff400_FUN_037ff400.h"

void FUN_037ff400(int param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)(DAT_037ff43c + param_1 * 0x40);
  if (*(char *)(DAT_037ff43c + param_1 * 0x40) != '\0') {
    FUN_037fa564((undefined4 *)(void *)(puVar1 + 0x14));
    puVar1[1] = puVar1[1] + '\x01';
    *puVar1 = 0;
  }
  return;
}

