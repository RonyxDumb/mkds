/* Decompiled C draft; module arm9; ROM address 021400a0. No matching claim. */
#include "types.h"
#include "deps/021400a0_copysign.h"

double copysign(double __x,double __y)

{
  undefined4 in_r0;
  uint in_r1;
  uint in_r3;
  
  return (double)CONCAT44(in_r1 & 0x7fffffff | in_r3 & 0x80000000,in_r0);
}

