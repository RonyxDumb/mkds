/* Decompiled C draft; module arm9_ov003; ROM address 021d0e9c. No matching claim. */
#include "types.h"
#include "deps/021d0e9c_FUN_021d0e9c.h"

void FUN_021d0e9c(undefined1 *param_1,undefined1 *param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = DAT_021d0ed8;
  piVar1 = DAT_021d0ed4;
  *param_1 = *(undefined1 *)(*DAT_021d0ed4 + DAT_021d0ed8);
  if (*(char *)(*piVar1 + iVar2) == *(char *)(*piVar1 + DAT_021d0edc)) {
    *param_2 = 0;
  }
  else {
    *param_2 = 1;
  }
  *(undefined1 *)(*DAT_021d0ed4 + DAT_021d0edc) = *(undefined1 *)(*DAT_021d0ed4 + DAT_021d0ed8);
  return;
}

