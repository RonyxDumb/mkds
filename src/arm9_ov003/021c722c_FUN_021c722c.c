/* Decompiled C draft; module arm9_ov003; ROM address 021c722c. No matching claim. */
#include "types.h"
#include "deps/021c722c_FUN_021c722c.h"

void FUN_021c722c(void)

{
  int local_8 [2];
  
  FUN_021bf410();
  FUN_021d2f00((uint *)(uintptr_t)(*(undefined4 *)(*DAT_021c7294 + 4)));
  FUN_021d2168(0);
  FUN_021bf620(DAT_021c7298,DAT_021c729c);
  FUN_021d272c(1,1);
  FUN_021d272c(0,0x15);
  FUN_021c20dc(local_8,0);
  if (2 < local_8[0]) {
    local_8[0] = local_8[0] + 1;
  }
  FUN_021c2120(2,1);
  FUN_021c20f8(0,local_8[0] + 3);
  FUN_021c212c(DAT_021c72a0);
  FUN_021d2808(DAT_021c7294);
  return;
}

