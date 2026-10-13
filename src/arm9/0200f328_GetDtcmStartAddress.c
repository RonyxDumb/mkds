/* Decompiled C draft; module arm9; ROM address 0200f328. No matching claim. */
#include "types.h"
#include "deps/0200f328_GetDtcmStartAddress.h"

uint GetDtcmStartAddress(void)

{
  uint uVar1;
  undefined4 in_cr1;
  undefined4 in_cr9;
  
  uVar1 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr1);
  return uVar1 & uRam0200f338;
}

