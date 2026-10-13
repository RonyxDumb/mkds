/* Decompiled C draft; module arm9; ROM address 0211427c. No matching claim. */
#include "types.h"
#include "deps/0211427c_func_0211427c.h"

void func_0211427c(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0211428e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02114294)(*(ushort *)(*(int *)(*piRam02114290 + 4) + param_1 * 2) & 0xff,1);
  return;
}

