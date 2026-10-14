/* Decompiled C draft; module arm9; ROM address 02016f2c. No matching claim. */
#include "types.h"
#include "deps/02016f2c_func_02016f2c.h"

bool func_02016f2c(uint param_1)

{
  int iVar1;
  
  iVar1 = (param_1 & uRam02016fac) << 3;
  if ((param_1 & uRam02016fa8) >> 0x10 == 0) {
    return (bool)2;
  }
  if ((int)param_1 < 0) {
    iVar1 = func_020169a4(uRam02016fb0,uRam02016fb4,iVar1);
  }
  else {
    iVar1 = func_020169a4(uRam02016fb8,uRam02016fb4,iVar1);
  }
  return iVar1 == 0;
}

