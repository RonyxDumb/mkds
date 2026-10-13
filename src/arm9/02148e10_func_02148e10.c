/* Decompiled C draft; module arm9; ROM address 02148e10. No matching claim. */
#include "types.h"
#include "deps/02148e10_func_02148e10.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void func_02148e10(void)

{
  _DAT_04000000 = _DAT_04000000 & 0x7fffffff;
                    /* WARNING: Could not recover jumptable at 0x02148e28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02148e2c)(uRam02148e30);
  return;
}

