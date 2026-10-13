/* Decompiled C draft; module arm9_ov000; ROM address 021a33e4. No matching claim. */
#include "types.h"
#include "deps/021a33e4_FUN_021a33e4.h"

undefined4 FUN_021a33e4(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (((param_2 == 1) && (iVar1 = FUN_0219bac8(), iVar1 == 0)) ||
     (iVar1 = FUN_0219b8bc(param_1), iVar1 == 0)) {
    return 0;
  }
  iVar1 = FUN_021a2fc8(param_1);
  if (iVar1 == 1) {
    return 0;
  }
  iVar1 = FUN_021a2d18(param_1);
  iVar2 = FUN_021a31d4(param_2);
  if (iVar2 <= iVar1) {
    return 1;
  }
  return 0;
}

