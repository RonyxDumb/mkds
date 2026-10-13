/* Decompiled C draft; module arm9; ROM address 0205a71c. No matching claim. */
#include "types.h"
#include "deps/0205a71c_func_0205a71c.h"

void func_0205a71c(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0205a740. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0205a74c)((uint)*(byte *)((*(uint *)(uRam0205a744 & 0xfffffffc) >> (uRam0205a744 & 3) * 8 |
                                   *(uint *)(uRam0205a744 & 0xfffffffc) <<
                                   (uRam0205a744 & 3) * -8 + 0x20) + param_1 + 6) * 0x210 +
                   (*(uint *)(uRam0205a748 & 0xfffffffc) >> (uRam0205a748 & 3) * 8 |
                   *(uint *)(uRam0205a748 & 0xfffffffc) << (uRam0205a748 & 3) * -8 + 0x20));
  return;
}

