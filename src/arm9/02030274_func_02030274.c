/* Decompiled C draft; module arm9; ROM address 02030274. No matching claim. */
#include "types.h"
#include "deps/02030274_func_02030274.h"

undefined4 func_02030274(uint param_1,int param_2)

{
  ushort *puVar1;
  int iVar2;
  
  iVar2 = 0;
  puVar1 = (ushort *)(iRam0203029c + param_2 * 6);
  do {
    if (param_1 == *puVar1) {
      return 1;
    }
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  return 0;
}

