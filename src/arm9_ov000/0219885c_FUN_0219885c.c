/* Decompiled C draft; module arm9_ov000; ROM address 0219885c. No matching claim. */
#include "types.h"
#include "deps/0219885c_FUN_0219885c.h"

void FUN_0219885c(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = FUN_0219a28c();
  if (iVar1 == 0) {
    *(undefined4 *)(*param_2 + 0xc) = 0;
    *(undefined4 *)(*param_2 + 0x10) = 1;
  }
  return;
}

