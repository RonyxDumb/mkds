/* Decompiled C draft; module arm9_ov000; ROM address 02198584. No matching claim. */
#include "types.h"
#include "deps/02198584_FUN_02198584.h"

undefined4 FUN_02198584(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_021986ac();
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = FUN_021985ec(param_1,param_2);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = FUN_02198658(param_1,param_2);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = FUN_0219861c(param_1,param_2);
  if (iVar1 != 0) {
    return 1;
  }
  return 0;
}

