/* Decompiled C draft; module arm9; ROM address 0207a68c. No matching claim. */
#include "types.h"
#include "deps/0207a68c_func_0207a68c.h"

void func_0207a68c(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0207a6a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0207a6ac)(iRam0207a6a8 * param_1 +
                   (*(uint *)(uRam0207a6a4 & 0xfffffffc) >> (uRam0207a6a4 & 3) * 8 |
                   *(uint *)(uRam0207a6a4 & 0xfffffffc) << (uRam0207a6a4 & 3) * -8 + 0x20));
  return;
}

