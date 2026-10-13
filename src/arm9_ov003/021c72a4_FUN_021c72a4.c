/* Decompiled C draft; module arm9_ov003; ROM address 021c72a4. No matching claim. */
#include "types.h"
#include "deps/021c72a4_FUN_021c72a4.h"

void FUN_021c72a4(void)

{
  int iVar1;
  
  iVar1 = FUN_021c1c5c();
  if (iVar1 == 0) {
    if (*(char *)(*DAT_021c7304 + 0x15) == '\0') {
      FUN_021c212c(DAT_021c7308);
      return;
    }
    if (*(char *)(*DAT_021c7304 + 0x15) == '\x02') {
      FUN_021cefc0(0x2f,3,1,0xffffffff,0);
      FUN_021c212c(DAT_021c730c);
      return;
    }
    FUN_021cefc0(0x9b,2,1,0xffffffff,0);
    FUN_021c212c(DAT_021c7310);
  }
  return;
}

