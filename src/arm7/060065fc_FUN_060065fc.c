/* Decompiled C draft; module arm7; ROM address 060065fc. No matching claim. */
#include "types.h"
#include "deps/060065fc_FUN_060065fc.h"

void FUN_060065fc(void)

{
  undefined2 uVar1;
  
  uVar1 = *DAT_0600664c;
  if (*DAT_06006648 < *DAT_06006648) {
    uVar1 = *DAT_0600664c;
  }
  *DAT_06006650 = (short)(CONCAT22(uVar1,*DAT_06006648) * 2 + (uint)*DAT_06006644 * -0x7f >> 7);
  return;
}

