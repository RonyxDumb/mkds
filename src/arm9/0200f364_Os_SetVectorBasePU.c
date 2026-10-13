/* Decompiled C draft; module arm9; ROM address 0200f364. No matching claim. */
#include "types.h"
#include "deps/0200f364_Os_SetVectorBasePU.h"

void Os_SetVectorBasePU(undefined4 param_1)

{
  undefined4 in_cr2;
  undefined4 in_cr6;
  
  coprocessor_moveto(0xf,0,0,param_1,in_cr6,in_cr2);
  return;
}

