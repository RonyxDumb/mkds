/* Decompiled C draft; module arm9_ov001; ROM address 02183780. No matching claim. */
#include "types.h"
#include "deps/02183780_FUN_02183780.h"

undefined4 FUN_02183780(ushort *param_1)

{
  int iVar1;
  
  if ((*param_1 == DAT_02183820) &&
     ((iVar1 = func_0x0209b620(*(undefined4 *)((int)param_1 + DAT_02183824)), iVar1 == 2 ||
      (iVar1 = func_0x0209b620(*(undefined4 *)((int)param_1 + DAT_02183824)), iVar1 == 3)))) {
    FUN_02187af4((int)(uintptr_t)(param_1));
    FUN_021872e0((int)(uintptr_t)(param_1),DAT_02183834,0,0,0,DAT_02183828,DAT_0218382c,DAT_02183830,0);
    FUN_021872e0((int)(uintptr_t)(param_1),DAT_02183834,0,0,0,DAT_02183828,DAT_0218382c,DAT_02183838,0);
    FUN_021872e0((int)(uintptr_t)(param_1),DAT_02183834,0,0,0,DAT_0218383c,DAT_0218382c,DAT_02183840,0);
    func_0x020d2774((int)(uintptr_t)(param_1),DAT_02183844);
  }
  iVar1 = func_0x02061fec();
  if (iVar1 == 1) {
    FUN_02183b9c((int)(uintptr_t)(param_1));
  }
  return 0;
}

