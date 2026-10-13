/* Decompiled C draft; module arm9_ov000; ROM address 021a6558. No matching claim. */
#include "types.h"
#include "deps/021a6558_FUN_021a6558.h"

void FUN_021a6558(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_021a5b30();
  piVar2 = *(int **)(iVar1 + DAT_021a65d0);
  if (((param_1 != 0) && (piVar2 != (int *)0x0)) && (0xc < *(uint *)(iVar1 + DAT_021a65d4))) {
    for (iVar1 = piVar2[1]; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
      if (iVar1 == param_1) {
        if (*(int *)(iVar1 + 8) == 0) {
          piVar2[1] = *(int *)(iVar1 + 0xc);
        }
        else {
          *(undefined4 *)(*(int *)(iVar1 + 8) + 0xc) = *(undefined4 *)(iVar1 + 0xc);
        }
        if (*(int *)(iVar1 + 0xc) == 0) {
          piVar2[2] = *(int *)(iVar1 + 8);
        }
        else {
          *(undefined4 *)(*(int *)(iVar1 + 0xc) + 8) = *(undefined4 *)(iVar1 + 8);
        }
        break;
      }
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(int *)(param_1 + 8) = piVar2[2];
    piVar2[2] = param_1;
    if (*(int *)(param_1 + 8) == 0) {
      piVar2[1] = param_1;
    }
    else {
      *(int *)(*(int *)(param_1 + 8) + 0xc) = param_1;
    }
    if (iVar1 == 0) {
      *(int *)(param_1 + 4) = *piVar2;
      *piVar2 = *piVar2 + 1;
    }
  }
  return;
}

