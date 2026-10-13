/* Decompiled C draft; module arm9_ov000; ROM address 021a666c. No matching claim. */
#include "types.h"
#include "deps/021a666c_FUN_021a666c.h"

undefined4 FUN_021a666c(void)

{
  int iVar1;
  
  iVar1 = FUN_021a5b30();
  if ((*(int *)(iVar1 + DAT_021a6694) != 0) && (0xc < *(uint *)(iVar1 + DAT_021a6698))) {
    return *(undefined4 *)(*(int *)(iVar1 + DAT_021a6694) + 4);
  }
  return 0;
}

