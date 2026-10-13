/* Decompiled C draft; module arm9_ov003; ROM address 021c2cc8. No matching claim. */
#include "types.h"
#include "deps/021c2cc8_FUN_021c2cc8.h"

void FUN_021c2cc8(int param_1)

{
  int iVar1;
  
  if ((param_1 != 1) && (param_1 != 3)) {
    *DAT_021c2d04 = *DAT_021c2d04 ^ 1;
    FUN_021cdc10(8);
    iVar1 = (uint)*DAT_021c2d04 * 8;
    FUN_021bf6c8(*(undefined2 *)(DAT_021c2d08 + iVar1),*(undefined2 *)(DAT_021c2d0c + iVar1),
                 *(undefined2 *)(DAT_021c2d10 + iVar1),*(undefined2 *)(DAT_021c2d14 + iVar1));
  }
  return;
}

