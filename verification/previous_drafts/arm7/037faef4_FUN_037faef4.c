/* Decompiled C draft; module arm7; ROM address 037faef4. No matching claim. */
#include "types.h"
#include "deps/037faef4_FUN_037faef4.h"

void FUN_037faef4(void)

{
  undefined4 *puVar1;
  
  if (*DAT_037faf4c == 0) {
    *DAT_037faf4c = 1;
    puVar1 = DAT_037faf50;
    *DAT_037faf50 = 0;
    puVar1[1] = 0;
    FUN_037f8850(4);
    *DAT_037faf54 = 0;
    *DAT_037faf58 = 0;
  }
  return;
}

