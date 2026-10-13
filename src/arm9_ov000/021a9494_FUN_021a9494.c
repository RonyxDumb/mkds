/* Decompiled C draft; module arm9_ov000; ROM address 021a9494. No matching claim. */
#include "types.h"
#include "deps/021a9494_FUN_021a9494.h"

undefined4 FUN_021a9494(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0xc);
  FUN_021a9868();
  do {
    iVar1 = FUN_021a9d68(param_1);
    if (iVar1 == 9) {
      return 1;
    }
  } while ((iVar1 != 4) && ((char)piVar2[1] == '\0'));
  if ((char)piVar2[1] == '\0') {
    *(undefined4 *)(*piVar2 + 0x54) = *(undefined4 *)(param_1 + 0x1c);
    *(undefined2 *)(*piVar2 + 0x58) = *(undefined2 *)(param_1 + 0x18);
    FUN_021a9640(param_1);
    FUN_021aa7b4(piVar2);
    FUN_021aa5e0(piVar2);
    FUN_021a998c(param_1);
    iVar1 = FUN_021a9610(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  else {
    FUN_021aa5e0(piVar2);
    iVar1 = FUN_021a9610(param_1);
    if (iVar1 != 0) {
      return 1;
    }
    FUN_021a998c(param_1);
  }
  *(undefined1 *)((int)piVar2 + DAT_021a9530) = 8;
  return 0;
}

