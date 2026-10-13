/* Decompiled C draft; module arm9; ROM address 02025e34. No matching claim. */
#include "types.h"
#include "deps/02025e34_func_02025e34.h"

int func_02025e34(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = piRam02025e5c;
  if (param_1 != 0x24) {
    do {
      if (param_1 == *piVar1) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar2 < 0x24);
  }
  return -1;
}

