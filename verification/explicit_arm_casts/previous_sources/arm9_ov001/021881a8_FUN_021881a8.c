/* Decompiled C draft; module arm9_ov001; ROM address 021881a8. No matching claim. */
#include "types.h"
#include "deps/021881a8_FUN_021881a8.h"

undefined4 FUN_021881a8(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  
  if ((((param_3 != 0) || (param_4 != 0)) &&
      ((param_3 == 0 || (iVar1 = FUN_02188f04(param_1,param_2), iVar1 != 0)))) &&
     ((param_4 == 0 ||
      (iVar1 = FUN_02188eac(param_1,*(undefined4 *)(param_1 + DAT_021881f0),param_2,param_4),
      iVar1 != 0)))) {
    return 1;
  }
  return 0;
}

