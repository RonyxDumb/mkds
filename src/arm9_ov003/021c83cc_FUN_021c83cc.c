/* Decompiled C draft; module arm9_ov003; ROM address 021c83cc. No matching claim. */
#include "types.h"
#include "deps/021c83cc_FUN_021c83cc.h"

int FUN_021c83cc(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = func_0x02147d30(*DAT_021c83fc,0x1d);
  iVar2 = 0;
  do {
    if (iVar1 == param_1) {
      return iVar2;
    }
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 1;
  } while (iVar2 < 4);
  return -1;
}

