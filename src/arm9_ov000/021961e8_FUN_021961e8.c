/* Decompiled C draft; module arm9_ov000; ROM address 021961e8. No matching claim. */
#include "types.h"
#include "deps/021961e8_FUN_021961e8.h"

int FUN_021961e8(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  int local_14;
  
  *(int *)(*param_1 + DAT_0219623c) = *(int *)(*param_1 + DAT_0219623c) + 1;
  iVar1 = FUN_021938cc(param_1,3,param_2,&local_14,param_3,param_4,param_5);
  if (((iVar1 == 0) && (iVar1 = FUN_021962d4((undefined4)(uintptr_t)(param_1),local_14), iVar1 == 0)) &&
     ((*(int *)(local_14 + 8) == 0 ||
      (iVar1 = FUN_0218f2e8(param_1,*(undefined4 *)(local_14 + 0x18)), iVar1 == 0)))) {
    iVar1 = 0;
  }
  return iVar1;
}

