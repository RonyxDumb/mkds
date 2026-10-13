/* Decompiled C draft; module arm9; ROM address 0200fc8c. No matching claim. */
#include "types.h"
#include "deps/0200fc8c_Os_EnableIrq.h"

longlong Os_EnableIrq(void)

{
  char in_NG;
  char in_ZR;
  char in_CY;
  char in_OV;
  byte in_Q;
  
  return (ulonglong)((uint)(byte)(in_NG << 4 | in_ZR << 3 | in_CY << 2 | in_OV << 1 | in_Q) << 0x1b)
         << 0x20;
}

