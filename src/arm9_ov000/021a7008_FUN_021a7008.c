/* Decompiled C draft; module arm9_ov000; ROM address 021a7008. No matching claim. */
#include "types.h"
#include "deps/021a7008_FUN_021a7008.h"

undefined4 FUN_021a7008(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = (int)*(char *)(param_2 + 0xd);
  }
  iVar1 = func_0x0200eae8(param_1,param_2,iVar1);
  if (iVar1 != 0) {
    return 0;
  }
  FUN_021a7048(param_2);
  return 0xffffffd6;
}

