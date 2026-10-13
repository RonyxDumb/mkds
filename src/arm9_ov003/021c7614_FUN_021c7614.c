/* Decompiled C draft; module arm9_ov003; ROM address 021c7614. No matching claim. */
#include "types.h"
#include "deps/021c7614_FUN_021c7614.h"

void FUN_021c7614(void)

{
  int iVar1;
  
  iVar1 = FUN_021d1f70(1);
  if ((iVar1 == 0) && (iVar1 = FUN_021d1f70(0), iVar1 == 0)) {
    FUN_021c1cd8();
    FUN_021cdc10(0x14);
    if (*(char *)(*DAT_021c7670 + 0x14) == '\0') {
      FUN_021c1c90(0);
      FUN_021c1c70(0);
    }
    else {
      iVar1 = FUN_021c735c(0x1a);
      if (iVar1 != 0) {
        FUN_021c1c80(0);
      }
      FUN_021c1c70(0);
    }
    FUN_021c212c(DAT_021c7674);
  }
  return;
}

