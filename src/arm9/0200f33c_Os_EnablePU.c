/* Decompiled C draft; module arm9; ROM address 0200f33c. No matching claim. */
#include "types.h"
#include "deps/0200f33c_Os_EnablePU.h"

uint Os_EnablePU(void)

{
  uint uVar1;
  
  uVar1 = coproc_movefrom_Control();
  coproc_moveto_Control(uVar1 | 1);
  return uVar1 | 1;
}

