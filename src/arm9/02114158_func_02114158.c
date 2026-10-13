/* Decompiled C draft; module arm9; ROM address 02114158. No matching claim. */
#include "types.h"
#include "deps/02114158_func_02114158.h"

void func_02114158(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x02114168. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02114170)(*(ushort *)(*(int *)(*piRam0211416c + 4) + param_1 * 2) & 0xff);
  return;
}

