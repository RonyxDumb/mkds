/* Decompiled C draft; module arm9; ROM address 0214903c. No matching claim. */
#include "types.h"
#include "deps/0214903c_func_0214903c.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void func_0214903c(void)

{
  _DAT_04000000 = _DAT_04000000 & 0xbfffffff;
                    /* WARNING: Could not recover jumptable at 0x02149054. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02149058)(uRam0214905c);
  return;
}

