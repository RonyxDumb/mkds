/* Decompiled C draft; module arm9; ROM address 021423f8. No matching claim. */
#include "types.h"
#include "deps/021423f8_Semihost_Op7.h"

undefined8 Semihost_Op7(void)

{
  software_interrupt(0x123456);
  return 7;
}

