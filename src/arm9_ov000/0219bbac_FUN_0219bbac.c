/* Decompiled C draft; module arm9_ov000; ROM address 0219bbac. No matching claim. */
#include "types.h"
#include "deps/0219bbac_FUN_0219bbac.h"

undefined4 FUN_0219bbac(undefined4 param_1)

{
  int iVar1;
  
  if (((*DAT_0219bbf8 != 0) && (iVar1 = FUN_0219c39c(), iVar1 == 0)) &&
     ((*(int *)(*DAT_0219bbf8 + 0x24) == 5 || (*(int *)(*DAT_0219bbf8 + 0x24) == 6)))) {
    iVar1 = FUN_0219b9d4(param_1);
    if (iVar1 == 0) {
      return 0xfffffffe;
    }
    FUN_02198908();
    return 0;
  }
  return 0xffffffff;
}

