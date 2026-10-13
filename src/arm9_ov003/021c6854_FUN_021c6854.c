/* Decompiled C draft; module arm9_ov003; ROM address 021c6854. No matching claim. */
#include "types.h"
#include "deps/021c6854_FUN_021c6854.h"

void FUN_021c6854(void)

{
  int iVar1;
  uint *puVar2;
  int local_10 [4];
  
  local_10[0] = *DAT_021c68b4;
  local_10[1] = DAT_021c68b4[1];
  iVar1 = FUN_021cef6c();
  if (iVar1 == 0) {
    if (*(char *)(*DAT_021c68b8 + 0x2a) == '\0') {
      puVar2 = *(uint **)(*DAT_021c68b8 + 4);
      *puVar2 = *puVar2 & DAT_021c68bc;
      FUN_021c212c(DAT_021c68c0);
      return;
    }
    FUN_021c20dc(local_10 + 2,0);
    (*(code *)local_10[local_10[2]])(*DAT_021c68b8 + 8);
    FUN_021c212c(DAT_021c68c4);
  }
  return;
}

