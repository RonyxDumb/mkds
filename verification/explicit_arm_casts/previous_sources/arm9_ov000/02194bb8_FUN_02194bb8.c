/* Decompiled C draft; module arm9_ov000; ROM address 02194bb8. No matching claim. */
#include "types.h"
#include "deps/02194bb8_FUN_02194bb8.h"

undefined4 FUN_02194bb8(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *param_1;
  if (0 < *(int *)(iVar5 + DAT_02194c8c)) {
    piVar2 = (int *)FUN_021a3690(*(int *)(iVar5 + DAT_02194c8c) << 2);
    if (piVar2 == (int *)0x0) {
      FUN_02196590(param_1,DAT_02194c90);
      return 1;
    }
    iVar1 = 0;
    for (piVar3 = *(int **)(iVar5 + DAT_02194c94); piVar3 != (int *)0x0; piVar3 = (int *)piVar3[8])
    {
      iVar4 = iVar1;
      if (((*piVar3 == 3) && (piVar3[5] != 5)) && (*(int *)(piVar3[1] + DAT_02194c98) == 0)) {
        if (*(int *)(iVar5 + DAT_02194c8c) <= iVar1) {
          func_0x0213442c(DAT_02194c9c,DAT_02194ca0,0,DAT_02194ca4);
        }
        iVar4 = iVar1 + 1;
        piVar2[iVar1] = (int)piVar3;
        *(undefined4 *)(piVar3[1] + DAT_02194c98) = 1;
      }
      iVar1 = iVar4;
    }
    iVar5 = 0;
    piVar3 = piVar2;
    if (0 < iVar1) {
      do {
        iVar4 = FUN_02194cac(param_1,*piVar3);
        if (iVar4 != 0) {
          *(int *)(*piVar3 + 0x1c) = iVar4;
        }
        iVar5 = iVar5 + 1;
        piVar3 = piVar3 + 1;
      } while (iVar5 < iVar1);
    }
    iVar5 = 0;
    piVar3 = piVar2;
    if (0 < iVar1) {
      do {
        iVar4 = *(int *)(*piVar3 + 4);
        *(undefined4 *)(iVar4 + DAT_02194c98) = 0;
        if (*(int *)(iVar4 + DAT_02194ca8) != 0) {
          FUN_02193818(param_1,*piVar3);
        }
        iVar5 = iVar5 + 1;
        piVar3 = piVar3 + 1;
      } while (iVar5 < iVar1);
    }
    FUN_021a3668(piVar2);
  }
  return 0;
}

