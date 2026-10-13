/* Decompiled C draft; module arm9_ov000; ROM address 021b0014. No matching claim. */
#include "types.h"
#include "deps/021b0014_FUN_021b0014.h"

undefined4 FUN_021b0014(short *param_1,short *param_2)

{
  short sVar1;
  short sVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    sVar1 = *param_1;
    param_1 = param_1 + 1;
    sVar2 = *param_2;
    param_2 = param_2 + 1;
    if (sVar1 != sVar2) {
      return 1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  return 0;
}

