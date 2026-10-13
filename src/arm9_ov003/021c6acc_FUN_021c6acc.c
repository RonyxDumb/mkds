/* Decompiled C draft; module arm9_ov003; ROM address 021c6acc. No matching claim. */
#include "types.h"
#include "deps/021c6acc_FUN_021c6acc.h"

void FUN_021c6acc(void)

{
  int iVar1;
  int local_14 [5];
  
  local_14[0] = *DAT_021c6b44;
  local_14[1] = DAT_021c6b44[1];
  iVar1 = FUN_021c0ca8();
  if (iVar1 == 0) {
    if (*(char *)(*DAT_021c6b48 + 0x2a) == '\0') {
      FUN_021c212c(DAT_021c6b4c);
      return;
    }
    if (*(char *)(*DAT_021c6b48 + 0x2a) == '\x02') {
      FUN_021cefc0(0x2f,3,1,0xffffffff,0);
      FUN_021c212c(DAT_021c6b50);
      return;
    }
    FUN_021c20dc(0,local_14 + 2);
    FUN_021cefc0(local_14[local_14[2]],2,1,0xffffffff,0);
    FUN_021c212c(DAT_021c6b54);
  }
  return;
}

