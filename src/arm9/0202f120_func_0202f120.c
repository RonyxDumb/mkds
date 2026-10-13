/* Decompiled C draft; module arm9; ROM address 0202f120. No matching claim. */
#include "types.h"
#include "deps/0202f120_func_0202f120.h"

void func_0202f120(int param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(*piRam0202f148 + 0x28);
  if ((pcVar1 != (code *)0x0) &&
     ((param_1 != 1 || ((-1 < param_3 && (param_3 < *(int *)(*piRam0202f148 + 0x34))))))) {
    (*pcVar1)();
  }
  return;
}

