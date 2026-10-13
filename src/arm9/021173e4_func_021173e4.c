/* Decompiled C draft; module arm9; ROM address 021173e4. No matching claim. */
#include "types.h"
#include "deps/021173e4_func_021173e4.h"

void func_021173e4(void)

{
  *puRam0211740c = *(int *)(*piRam02117404 + 0x40) * -0x10000 & uRam02117408;
  *puRam02117410 = *puRam02117410 & uRam02117414;
  return;
}

