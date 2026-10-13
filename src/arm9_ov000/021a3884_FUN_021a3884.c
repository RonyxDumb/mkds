/* Decompiled C draft; module arm9_ov000; ROM address 021a3884. No matching claim. */
#include "types.h"
#include "deps/021a3884_FUN_021a3884.h"

void FUN_021a3884(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *DAT_021a38d4;
  if ((iVar3 != 0) && (*(short *)(iVar3 + 4) == 2)) {
    uVar2 = FUN_021887cc();
    *(undefined4 *)*DAT_021a38d4 = uVar2;
    return;
  }
  if ((iVar3 != 0) &&
     (((*(short *)(iVar3 + 4) == 4 && (*(short *)(iVar3 + 6) != 0)) &&
      (iVar3 = FUN_021a5bfc(), piVar1 = DAT_021a38d4, iVar3 != 9)))) {
    *(undefined2 *)(*DAT_021a38d4 + 6) = 0;
    *(undefined2 *)(*piVar1 + 4) = 6;
  }
  return;
}

