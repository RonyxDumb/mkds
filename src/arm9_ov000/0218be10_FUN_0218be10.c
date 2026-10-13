/* Decompiled C draft; module arm9_ov000; ROM address 0218be10. No matching claim. */
#include "types.h"
#include "deps/0218be10_FUN_0218be10.h"

undefined4 FUN_0218be10(undefined4 param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  
  if (param_3 < 6) {
    return 4;
  }
  iVar1 = FUN_0218d2a8(param_1,*param_2,*(undefined2 *)(param_2 + 1));
  if (iVar1 != -1) {
    FUN_0218d238(param_1);
  }
  return 0;
}

