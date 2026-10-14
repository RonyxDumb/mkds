/* Decompiled C draft; module arm9; ROM address 02148e34. No matching claim. */
#include "types.h"
#include "deps/02148e34_func_02148e34.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void func_02148e34(void)

{
  _DAT_04000000 = _DAT_04000000 & 0xbfffffff;
                    /* WARNING: Could not recover jumptable at 0x02148e4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02148e50)(uRam02148e54);
  return;
}

