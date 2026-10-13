/* Decompiled C draft; module arm9_ov003; ROM address 021d0810. No matching claim. */
#include "types.h"
#include "deps/021d0810_FUN_021d0810.h"

void FUN_021d0810(int param_1)

{
  int *piVar1;
  
  piVar1 = DAT_021d082c;
  *DAT_021d082c = param_1;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(*piVar1 + DAT_021d0830) = 0;
  *(undefined4 *)(*piVar1 + DAT_021d0834) = 0;
  *(undefined4 *)(*piVar1 + DAT_021d0838) = 0;
  return;
}

