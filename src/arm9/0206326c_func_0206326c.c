/* Decompiled C draft; module arm9; ROM address 0206326c. No matching claim. */
#include "types.h"
#include "deps/0206326c_func_0206326c.h"

void func_0206326c(void)

{
                    /* WARNING: Could not recover jumptable at 0x02063280. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02063288)(*(uint *)(uRam02063284 & 0xfffffffc) >> (uRam02063284 & 3) * 8 |
                   *(uint *)(uRam02063284 & 0xfffffffc) << (uRam02063284 & 3) * -8 + 0x20,
                   uRam0206328c,uRam02063290);
  return;
}

