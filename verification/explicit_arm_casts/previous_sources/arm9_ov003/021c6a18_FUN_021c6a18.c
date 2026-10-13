/* Decompiled C draft; module arm9_ov003; ROM address 021c6a18. No matching claim. */
#include "types.h"
#include "deps/021c6a18_FUN_021c6a18.h"

void FUN_021c6a18(void)

{
  undefined4 local_10;
  int local_c [3];
  
  FUN_021bf410();
  FUN_021d2f00(*(undefined4 *)(*DAT_021c6ab4 + 4));
  FUN_021d2168(0);
  FUN_021bf620(DAT_021c6ab8,DAT_021c6abc);
  FUN_021d272c(1,1);
  FUN_021d272c(0,0x15);
  FUN_021c20dc(&local_10,local_c);
  if (local_c[0] == 0) {
    FUN_021c2120(2,1);
    FUN_021c20f8(0,local_10);
    FUN_021c212c(DAT_021c6ac0);
  }
  else if (*(char *)(*DAT_021c6ab4 + 0x2a) == '\0') {
    FUN_021c2120(0,1);
    FUN_021c20f8(1,0);
    FUN_021c212c(DAT_021c6ac4);
  }
  else {
    FUN_021c2120(0,0);
    FUN_021c20f8(0,1);
    FUN_021c212c(DAT_021c6ac8);
  }
  FUN_021d2808(DAT_021c6ab4);
  return;
}

