/* Decompiled C draft; module arm9_ov003; ROM address 021d1f70. No matching claim. */
#include "types.h"
#include "deps/021d1f70_FUN_021d1f70.h"

undefined1 FUN_021d1f70(int param_1)

{
  int iVar1;
  
  if (param_1 == 1) {
    iVar1 = *DAT_021d1f84;
  }
  else {
    iVar1 = *DAT_021d1f84 + 0xc;
  }
  return *(undefined1 *)(iVar1 + 9);
}

