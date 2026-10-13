/* Decompiled C draft; module arm9_ov000; ROM address 02193f2c. No matching claim. */
#include "types.h"
#include "deps/02193f2c_FUN_02193f2c.h"

int * FUN_02193f2c(int *param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(*param_1 + DAT_02193f4c);
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return (int *)0x0;
    }
    if ((piVar1[3] == param_2) && (*piVar1 == 0x69)) break;
    piVar1 = (int *)piVar1[0xf];
  }
  return piVar1;
}

