/* Decompiled C draft; module arm9_ov000; ROM address 021a8ab8. No matching claim. */
#include "types.h"
#include "deps/021a8ab8_FUN_021a8ab8.h"

int * FUN_021a8ab8(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  while( true ) {
    if (iVar1 == 0) {
      return (int *)0x0;
    }
    if (iVar1 == param_2) break;
    param_1 = (int *)(iVar1 + 0x7c);
    iVar1 = *(int *)(iVar1 + 0x7c);
  }
  return param_1;
}

