/* Decompiled C draft; module arm9; ROM address 021142f0. No matching claim. */
#include "types.h"
#include "deps/021142f0_func_021142f0.h"

void func_021142f0(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x02114300. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02114308)(*(ushort *)(*(int *)(*piRam02114304 + 4) + param_1 * 2) & 0xff);
  return;
}

