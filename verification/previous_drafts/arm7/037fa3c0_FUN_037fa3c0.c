/* Decompiled C draft; module arm7; ROM address 037fa3c0. No matching claim. */
#include "types.h"
#include "deps/037fa3c0_FUN_037fa3c0.h"

void FUN_037fa3c0(void)

{
  undefined4 *puVar1;
  undefined2 *puVar2;
  
  if (*DAT_037fa43c == 0) {
    *DAT_037fa43c = 1;
    FUN_037fa25c(0);
    puVar1 = DAT_037fa440;
    *DAT_037fa440 = 0;
    puVar1[1] = 0;
    puVar2 = DAT_037fa444;
    *DAT_037fa444 = 0;
    *DAT_037fa448 = 0;
    *puVar2 = 0xc1;
    FUN_037f8944(8,DAT_037fa44c);
    FUN_037f888c(8);
    *DAT_037fa450 = 0;
  }
  return;
}

