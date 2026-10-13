/* Decompiled C draft; module arm9_ov003; ROM address 021cc6c4. No matching claim. */
#include "types.h"
#include "deps/021cc6c4_FUN_021cc6c4.h"

void FUN_021cc6c4(void)

{
  int iVar1;
  
  if ((*DAT_021cc6f4 == '\0') && (iVar1 = FUN_021bf334(), iVar1 == 0)) {
    *DAT_021cc6f4 = '\x02';
    FUN_021cdbd0();
    FUN_021cdc10(7);
    FUN_021c212c(DAT_021cc6f8);
  }
  return;
}

