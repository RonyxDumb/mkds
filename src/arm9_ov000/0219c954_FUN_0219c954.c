/* Decompiled C draft; module arm9_ov000; ROM address 0219c954. No matching claim. */
#include "types.h"
#include "deps/0219c954_FUN_0219c954.h"

void FUN_0219c954(void)

{
  if (*(int *)(*DAT_0219c98c + 0x28) != 0) {
    FUN_02186474();
    FUN_02186430();
    FUN_021a3704(0,*(undefined4 *)(*DAT_0219c98c + 0x28),0);
    *(undefined4 *)(*DAT_0219c98c + 0x28) = 0;
  }
  *DAT_0219c98c = 0;
  return;
}

