/* Decompiled C draft; module arm9; ROM address 020ce784. No matching claim. */
#include "types.h"
#include "deps/020ce784_func_020ce784.h"

bool func_020ce784(void)

{
  short *psVar1;
  
  psVar1 = (short *)GetBootIndicatorPointer_2();
  return *psVar1 == 2;
}

