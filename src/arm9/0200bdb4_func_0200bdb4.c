/* Decompiled C draft; module arm9; ROM address 0200bdb4. No matching claim. */
#include "types.h"
#include "deps/0200bdb4_func_0200bdb4.h"

void func_0200bdb4(undefined2 *param_1)

{
  code *pcVar1;
  int *piVar2;
  undefined2 local_8;
  short local_6;
  
  piVar2 = piRam0200bdf8;
  *(undefined2 *)(*piRam0200bdf8 + 0x1c) = 0;
  local_6 = param_1[1];
  if (local_6 == 0) {
    pcVar1 = *(code **)*piVar2;
    if (pcVar1 != (code *)0x0) {
      (*pcVar1)(0xf);
    }
  }
  else {
    local_8 = *param_1;
    piVar2 = (int *)*piVar2;
    if (*piVar2 != 0) {
      (*(code *)*piVar2)(uRam0200bdfc,&local_8);
      return;
    }
  }
  return;
}

