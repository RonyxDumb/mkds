/* Decompiled C draft; module arm9; ROM address 02010fac. No matching claim. */
#include "types.h"
#include "deps/02010fac_func_02010fac.h"

void func_02010fac(int param_1,int param_2,int param_3,int param_4)

{
  *(uint *)(iRam02010fe0 + param_1 * 4) =
       uRam02010fdc & param_2 >> 3 | (uRam02010fdc & param_3 >> 3) << 10 |
       (uRam02010fdc & param_4 >> 3) << 0x14 | param_1 << 0x1e;
  return;
}

