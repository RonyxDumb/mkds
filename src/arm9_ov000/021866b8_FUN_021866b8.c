/* Decompiled C draft; module arm9_ov000; ROM address 021866b8. No matching claim. */
#include "types.h"
#include "deps/021866b8_FUN_021866b8.h"

int FUN_021866b8(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  piVar2 = param_1;
  if (0 < param_2) {
    do {
      if (*piVar2 == 0) {
        return 0;
      }
      iVar1 = func_0x0213a074(param_3);
      if (iVar1 == 0) {
        return param_1[iVar3 * 2 + 1];
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 2;
    } while (iVar3 < param_2);
  }
  return 0;
}

