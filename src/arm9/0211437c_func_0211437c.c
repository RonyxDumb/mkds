/* Decompiled C draft; module arm9; ROM address 0211437c. No matching claim. */
#include "types.h"
#include "deps/0211437c_func_0211437c.h"

void func_0211437c(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0211438c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02114394)(*(ushort *)(*(int *)(*piRam02114390 + 4) + param_1 * 2) & 0xff);
  return;
}

