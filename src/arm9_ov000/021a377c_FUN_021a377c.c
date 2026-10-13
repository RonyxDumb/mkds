/* Decompiled C draft; module arm9_ov000; ROM address 021a377c. No matching claim. */
#include "types.h"
#include "deps/021a377c_FUN_021a377c.h"

undefined4 FUN_021a377c(void)

{
  int iVar1;
  
  iVar1 = *DAT_021a37d8;
  if (iVar1 == 0) {
    return 1;
  }
  if (*(short *)(iVar1 + 4) == 4) {
    *(undefined2 *)(iVar1 + 4) = 5;
  }
  else if (*(short *)(iVar1 + 4) != 5) {
    return 1;
  }
  iVar1 = FUN_021a86e8();
  if (iVar1 != 0) {
    return 0;
  }
  iVar1 = FUN_02188720();
  if (iVar1 != 0) {
    *DAT_021a37d8 = 0;
    return 1;
  }
  return 0;
}

