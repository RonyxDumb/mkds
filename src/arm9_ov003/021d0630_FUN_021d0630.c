/* Decompiled C draft; module arm9_ov003; ROM address 021d0630. No matching claim. */
#include "types.h"
#include "deps/021d0630_FUN_021d0630.h"

undefined4 FUN_021d0630(void)

{
  int *piVar1;
  int iVar2;
  
  if (*(int *)(*DAT_021d0678 + 0x40) - 4U < 3) {
    return 1;
  }
  iVar2 = func_0x02143bc4(DAT_021d067c);
  piVar1 = DAT_021d0678;
  if (iVar2 != 2) {
    FUN_021d079c();
    return 0;
  }
  *(undefined2 *)(*DAT_021d0678 + 0x50) = 0;
  *(undefined2 *)(*piVar1 + 0x52) = 1;
  return 1;
}

