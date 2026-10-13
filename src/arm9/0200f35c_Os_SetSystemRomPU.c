/* Decompiled C draft; module arm9; ROM address 0200f35c. No matching claim. */
#include "types.h"
#include "deps/0200f35c_Os_SetSystemRomPU.h"

void Os_SetSystemRomPU(undefined4 param_1)

{
  undefined4 in_cr1;
  undefined4 in_cr6;
  
  coprocessor_moveto(0xf,0,0,param_1,in_cr6,in_cr1);
  return;
}

