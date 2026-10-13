/* Decompiled C draft; module arm9_ov003; ROM address 021cbe78. No matching claim. */
#include "types.h"
#include "deps/021cbe78_FUN_021cbe78.h"

void FUN_021cbe78(void)

{
  int iVar1;
  int local_14;
  undefined4 local_10 [4];
  
  local_10[0] = *DAT_021cbec8;
  local_10[1] = DAT_021cbec8[1];
  local_10[2] = DAT_021cbec8[2];
  iVar1 = FUN_021d1f70(1);
  if ((iVar1 == 0) && (iVar1 = FUN_021d1f70(0), iVar1 == 0)) {
    FUN_021c20dc(0,&local_14);
    FUN_021cefc0(local_10[local_14],1,1,0xffffffff,0);
    FUN_021c212c(DAT_021cbecc);
  }
  return;
}

