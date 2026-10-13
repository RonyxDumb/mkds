/* Decompiled C draft; module arm9_ov003; ROM address 021d1fd0. No matching claim. */
#include "types.h"
#include "deps/021d1fd0_FUN_021d1fd0.h"

void FUN_021d1fd0(int param_1)

{
  int iVar1;
  
  iVar1 = *DAT_021d1fec;
  if (param_1 == iVar1 + DAT_021d1ff0) {
    *(undefined1 *)(iVar1 + DAT_021d1ff4) = 1;
    return;
  }
  *(undefined1 *)(iVar1 + DAT_021d1ff8) = 1;
  return;
}

