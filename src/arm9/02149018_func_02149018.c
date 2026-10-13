/* Decompiled C draft; module arm9; ROM address 02149018. No matching claim. */
#include "types.h"
#include "deps/02149018_func_02149018.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void func_02149018(void)

{
  _DAT_04000000 = _DAT_04000000 & 0x7fffffff;
                    /* WARNING: Could not recover jumptable at 0x02149030. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02149034)(uRam02149038);
  return;
}

