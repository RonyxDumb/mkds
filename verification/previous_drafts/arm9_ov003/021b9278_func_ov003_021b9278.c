/* Decompiled C draft; module arm9_ov003; ROM address 021b9278. No matching claim. */
#include "types.h"
#include "deps/021b9278_func_ov003_021b9278.h"

undefined4 func_ov003_021b9278(byte *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_2) {
    do {
      bVar1 = *param_1;
      param_1 = param_1 + 1;
      if ((bVar1 < 0x20) || (0x7f < bVar1)) {
        return 0xffffffff;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_2);
  }
  return 0;
}

