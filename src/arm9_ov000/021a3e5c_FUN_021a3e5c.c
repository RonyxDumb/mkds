/* Decompiled C draft; module arm9_ov000; ROM address 021a3e5c. No matching claim. */
#include "types.h"
#include "deps/021a3e5c_FUN_021a3e5c.h"

undefined4 FUN_021a3e5c(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int extraout_r1;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = param_1;
  do {
    if (param_2 == *(int *)(iVar2 + 0xd8)) {
      return 1;
    }
    iVar2 = iVar2 + 4;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 10);
  func_0x02133068(*(int *)(param_1 + DAT_021a3eac) + 1,10);
  piVar1 = (int *)(param_1 + DAT_021a3eac);
  *piVar1 = extraout_r1;
  *(int *)(param_1 + *piVar1 * 4 + 0xd8) = param_2;
  return 0;
}

