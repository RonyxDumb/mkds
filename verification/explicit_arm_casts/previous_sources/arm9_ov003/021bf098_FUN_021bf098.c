/* Decompiled C draft; module arm9_ov003; ROM address 021bf098. No matching claim. */
#include "types.h"
#include "deps/021bf098_FUN_021bf098.h"

void FUN_021bf098(undefined4 param_1)

{
  undefined1 auStack_10 [4];
  int local_c;
  
  FUN_021d1770(*(undefined4 *)(*DAT_021bf0d0 + 8),0,auStack_10,&local_c);
  local_c = local_c + 4;
  FUN_021bf258();
  if (0xbf < local_c) {
    FUN_021d34e0(param_1,DAT_021bf0d4);
  }
  return;
}

