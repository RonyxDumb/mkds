/* Decompiled C draft; module arm7; ROM address 037fa834. No matching claim. */
#include "types.h"
#include "deps/037fa834_FUN_037fa834.h"

void FUN_037fa834(void)

{
  undefined4 *puVar1;
  
  if (*DAT_037fa87c == 0) {
    *DAT_037fa87c = 1;
    FUN_037fa25c();
    puVar1 = DAT_037fa880;
    *DAT_037fa880 = 0;
    puVar1[1] = 0;
    FUN_037f8850(0x10);
  }
  return;
}

