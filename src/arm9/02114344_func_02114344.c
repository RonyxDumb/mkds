/* Decompiled C draft; module arm9; ROM address 02114344. No matching claim. */
#include "types.h"
#include "deps/02114344_func_02114344.h"

void func_02114344(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x02114354. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0211435c)(*(ushort *)(*(int *)(*piRam02114358 + 4) + param_1 * 2) & 0xff);
  return;
}

