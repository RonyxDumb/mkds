/* Decompiled C draft; module arm7; ROM address 037faf5c. No matching claim. */
#include "types.h"
#include "deps/037faf5c_FUN_037faf5c.h"

longlong FUN_037faf5c(void)

{
  char in_NG;
  char in_ZR;
  char in_CY;
  char in_OV;
  byte in_Q;
  
  return (ulonglong)((uint)(byte)(in_NG << 4 | in_ZR << 3 | in_CY << 2 | in_OV << 1 | in_Q) << 0x1b)
         << 0x20;
}

