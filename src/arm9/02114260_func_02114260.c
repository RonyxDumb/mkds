/* Decompiled C draft; module arm9; ROM address 02114260. No matching claim. */
#include "types.h"
#include "deps/02114260_func_02114260.h"

void func_02114260(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x02114272. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02114278)(*(ushort *)(*(int *)(*piRam02114274 + 4) + param_1 * 2) & 0xff,0);
  return;
}

