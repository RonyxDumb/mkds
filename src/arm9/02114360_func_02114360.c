/* Decompiled C draft; module arm9; ROM address 02114360. No matching claim. */
#include "types.h"
#include "deps/02114360_func_02114360.h"

void func_02114360(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x02114370. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02114378)(*(ushort *)(*(int *)(*piRam02114374 + 4) + param_1 * 2) & 0xff);
  return;
}

