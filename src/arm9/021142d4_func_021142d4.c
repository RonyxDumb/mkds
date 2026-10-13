/* Decompiled C draft; module arm9; ROM address 021142d4. No matching claim. */
#include "types.h"
#include "deps/021142d4_func_021142d4.h"

void func_021142d4(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x021142e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam021142ec)(*(ushort *)(*(int *)(*piRam021142e8 + 4) + param_1 * 2) & 0xff);
  return;
}

