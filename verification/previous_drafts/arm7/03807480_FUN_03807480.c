/* Decompiled C draft; module arm7; ROM address 03807480. No matching claim. */
#include "types.h"
#include "deps/03807480_FUN_03807480.h"

void FUN_03807480(void)

{
  ushort *puVar1;
  
  FUN_037f9a0c(DAT_038074c4);
  puVar1 = DAT_038074c8;
  while ((*puVar1 & 1) != 0) {
    thunk_FUN_038011a4(0x100);
  }
  FUN_037f999c(DAT_038074c4);
  return;
}

