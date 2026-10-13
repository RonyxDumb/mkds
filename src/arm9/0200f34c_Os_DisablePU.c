/* Decompiled C draft; module arm9; ROM address 0200f34c. No matching claim. */
#include "types.h"
#include "deps/0200f34c_Os_DisablePU.h"

uint Os_DisablePU(void)

{
  uint uVar1;
  
  uVar1 = coproc_movefrom_Control();
  coproc_moveto_Control(uVar1 & 0xfffffffe);
  return uVar1 & 0xfffffffe;
}

