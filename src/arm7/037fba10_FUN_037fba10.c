/* Decompiled C draft; module arm7; ROM address 037fba10. No matching claim. */
#include "types.h"
#include "deps/037fba10_FUN_037fba10.h"

void FUN_037fba10(void)

{
  int iVar1;
  
  FUN_037fba64();
  iVar1 = 0;
  do {
    FUN_037fbd0c(iVar1,1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x10);
  *DAT_037fba5c = 0;
  *DAT_037fba60 = 0;
  return;
}

