/* Decompiled C draft; module arm9; ROM address 02128374. No matching claim. */
#include "types.h"
#include "deps/02128374_func_02128374.h"

void func_02128374(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = func_02128294();
  if (iVar2 == 0) {
    *(undefined4 *)(*piRam021283ac + iRam021283b0) = 1;
  }
  else {
    *(undefined4 *)(*piRam021283ac + iRam021283b0) = 0;
  }
  piVar1 = piRam021283ac;
  *(undefined4 *)(*piRam021283ac + iRam021283b4) = 0;
  *(undefined4 *)(*piVar1 + iRam021283b8) = 0;
  return;
}

