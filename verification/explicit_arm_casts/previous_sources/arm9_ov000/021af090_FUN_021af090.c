/* Decompiled C draft; module arm9_ov000; ROM address 021af090. No matching claim. */
#include "types.h"
#include "deps/021af090_FUN_021af090.h"

int * FUN_021af090(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = *(int *)(DAT_021af0d8 + 8);
  while( true ) {
    if (iVar2 == 0) {
      return (int *)0x0;
    }
    piVar3 = *(int **)(iVar2 + 0xa4);
    if (((piVar3 != (int *)0x0) && (*piVar3 != 0)) &&
       (iVar1 = FUN_021af0dc(param_1,param_2,piVar3), iVar1 != 0)) break;
    iVar2 = *(int *)(iVar2 + 0x68);
  }
  return piVar3;
}

