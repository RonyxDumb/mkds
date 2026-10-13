/* Decompiled C draft; module arm9; ROM address 020b3adc. No matching claim. */
#include "types.h"
#include "deps/020b3adc_func_020b3adc.h"

void func_020b3adc(void)

{
  *(undefined4 *)
   (*(uint *)(uRam020b3af0 & 0xfffffffc) >> (uRam020b3af0 & 3) * 8 |
   *(uint *)(uRam020b3af0 & 0xfffffffc) << (uRam020b3af0 & 3) * -8 + 0x20) = 0;
  return;
}

