/* Decompiled C draft; module arm9; ROM address 0200bcd8. No matching claim. */
#include "types.h"
#include "deps/0200bcd8_func_0200bcd8.h"

void func_0200bcd8(int param_1)

{
  short sVar1;
  
  if ((((*(short *)(param_1 + 2) == 0) && (sVar1 = *(short *)(param_1 + 4), sVar1 != 7)) &&
      (sVar1 != 9)) && ((sVar1 == 0x15 && (*(code **)*puRam0200bd08 != (code *)0x0)))) {
    (**(code **)*puRam0200bd08)(9);
  }
  return;
}

