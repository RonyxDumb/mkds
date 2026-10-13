/* Decompiled C draft; module arm9_ov003; ROM address 021bf20c. No matching claim. */
#include "types.h"
#include "deps/021bf20c_FUN_021bf20c.h"

void FUN_021bf20c(undefined4 param_1)

{
  undefined1 auStack_10 [4];
  int local_c;
  
  FUN_021d1770(*(undefined4 *)(*DAT_021bf24c + 8),0,auStack_10,&local_c);
  local_c = local_c + -4;
  FUN_021bf258();
  if (local_c <= (int)(uint)*(ushort *)(DAT_021bf250 + 2)) {
    FUN_021bf258();
    FUN_021d34e0(param_1,DAT_021bf254);
  }
  return;
}

