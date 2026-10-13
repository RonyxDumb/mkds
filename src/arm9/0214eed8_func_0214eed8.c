/* Decompiled C draft; module arm9; ROM address 0214eed8. No matching claim. */
#include "types.h"
#include "deps/0214eed8_func_0214eed8.h"

void func_0214eed8(void)

{
  do {
  } while ((*(uint *)(uRam0214eeec & 0xfffffffc) >> (uRam0214eeec & 3) * 8 |
           *(uint *)(uRam0214eeec & 0xfffffffc) << (uRam0214eeec & 3) * -8 + 0x20) == 1);
  return;
}

