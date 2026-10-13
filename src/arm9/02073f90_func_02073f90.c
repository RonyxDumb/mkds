/* Decompiled C draft; module arm9; ROM address 02073f90. No matching claim. */
#include "types.h"
#include "deps/02073f90_func_02073f90.h"

void func_02073f90(void)

{
                    /* WARNING: Could not recover jumptable at 0x02073fa4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02073fac)(*(uint *)(uRam02073fa8 & 0xfffffffc) >> (uRam02073fa8 & 3) * 8 |
                   *(uint *)(uRam02073fa8 & 0xfffffffc) << (uRam02073fa8 & 3) * -8 + 0x20,0,0x1000);
  return;
}

