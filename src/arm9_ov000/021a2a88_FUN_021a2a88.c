/* Decompiled C draft; module arm9_ov000; ROM address 021a2a88. No matching claim. */
#include "types.h"
#include "deps/021a2a88_FUN_021a2a88.h"

undefined4 FUN_021a2a88(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((*DAT_021a2acc != 0) && (iVar1 = FUN_0219c39c(), iVar1 == 0)) {
    iVar1 = FUN_0218b480(*(undefined4 *)(*DAT_021a2acc + 0xe4),param_1);
    if (iVar1 != 0) {
      param_3 = FUN_0218b2a8(iVar1,param_2,param_3);
    }
    return param_3;
  }
  return param_3;
}

