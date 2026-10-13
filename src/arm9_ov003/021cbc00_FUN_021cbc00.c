/* Decompiled C draft; module arm9_ov003; ROM address 021cbc00. No matching claim. */
#include "types.h"
#include "deps/021cbc00_FUN_021cbc00.h"

void FUN_021cbc00(void)

{
  byte *pbVar1;
  int iVar2;
  int local_8 [2];
  
  pbVar1 = DAT_021cbc44;
  *DAT_021cbc44 = *DAT_021cbc44 + 1;
  if (0xb3 < *pbVar1) {
    FUN_021c20dc(0,local_8);
    iVar2 = FUN_021c20c0();
    if (((iVar2 != 0) && (iVar2 == 1)) && (local_8[0] != 0)) {
      FUN_021c212c(DAT_021cbc48);
      return;
    }
    FUN_021c212c(DAT_021cbc4c);
  }
  return;
}

