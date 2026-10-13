/* Decompiled C draft; module arm9_ov003; ROM address 021bb070. No matching claim. */
#include "types.h"
#include "deps/021bb070_FUN_021bb070.h"

undefined4 FUN_021bb070(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = *DAT_021bb0a4;
  if (*DAT_021bb0a8 == -1) {
    param_1[1] = 0xffffffff;
  }
  else {
    iVar1 = FUN_021bb354();
    param_1[1] = *DAT_021bb0a8 - iVar1;
  }
  param_1[2] = *DAT_021bb0ac;
  return 1;
}

