/* Decompiled C draft; module arm9_ov000; ROM address 021a574c. No matching claim. */
#include "types.h"
#include "deps/021a574c_FUN_021a574c.h"

void FUN_021a574c(void)

{
  int iVar1;
  
  if (*(char *)(*DAT_021a5784 + DAT_021a5788) == '\0') {
    *(char *)(*DAT_021a5784 + DAT_021a5788) = '\x01';
    iVar1 = func_0x02143dd0(DAT_021a578c);
    if (iVar1 != 2) {
      FUN_021a57fc(0xb);
      FUN_021a58a4(7,0,0,DAT_021a5790);
    }
  }
  return;
}

