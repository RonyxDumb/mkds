/* Decompiled C draft; module arm9; ROM address 0211430c. No matching claim. */
#include "types.h"
#include "deps/0211430c_func_0211430c.h"

void func_0211430c(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0211431c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02114324)(*(ushort *)(*(int *)(*piRam02114320 + 4) + param_1 * 2) & 0xff);
  return;
}

