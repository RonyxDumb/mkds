/* Decompiled C draft; module arm9; ROM address 02114328. No matching claim. */
#include "types.h"
#include "deps/02114328_func_02114328.h"

void func_02114328(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x02114338. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02114340)(*(ushort *)(*(int *)(*piRam0211433c + 4) + param_1 * 2) & 0xff);
  return;
}

