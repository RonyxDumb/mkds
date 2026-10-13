/* Decompiled C draft; module arm9_ov003; ROM address 021c4ae0. No matching claim. */
#include "types.h"
#include "deps/021c4ae0_FUN_021c4ae0.h"

void FUN_021c4ae0(void)

{
  int iVar1;
  
  if (((*DAT_021c4b64 == '\0') && (*DAT_021c4b68 != '\0')) || (iVar1 = FUN_021c27e4(), iVar1 != 0))
  {
    FUN_021d2168(0);
    FUN_021d272c(0,0x15);
    if (*DAT_021c4b68 == '\0') {
      FUN_021bf410();
      FUN_021d272c(1,1);
    }
    FUN_021c2120(0,1);
    if (*DAT_021c4b64 != '\0') {
      FUN_021c212c(DAT_021c4b6c);
      return;
    }
    if (*DAT_021c4b68 == '\0') {
      FUN_021d272c(1,1);
      FUN_021c212c(DAT_021c4b70);
      return;
    }
    FUN_021c212c(DAT_021c4b74);
  }
  return;
}

