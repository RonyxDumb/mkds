/* Decompiled C draft; module arm7; ROM address 038011d2. No matching claim. */
#include "types.h"
#include "deps/038011d2_FUN_038011d2.h"

longlong FUN_038011d2(uint param_1)

{
  software_interrupt(8);
  return (ulonglong)param_1 << 0x20;
}

