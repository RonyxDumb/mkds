/* Decompiled C draft; module arm9; ROM address 02134420. No matching claim. */
#include "types.h"
#include "deps/02134420_abs.h"

int abs(int __x)

{
  if (__x < 0) {
    __x = -__x;
  }
  return __x;
}

