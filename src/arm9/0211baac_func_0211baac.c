/* Decompiled C draft; module arm9; ROM address 0211baac. No matching claim. */
#include "types.h"
#include "deps/0211baac_func_0211baac.h"

void func_0211baac(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = piRam0211bad4;
  *(undefined4 *)(*piRam0211bad4 + 0x34) = 2;
  *(undefined4 *)(*piVar1 + 0x38) = 0;
  iVar2 = *(int *)(*piVar1 + 0x2c);
  if ((iVar2 == 0) || (iVar2 == 1)) {
    func_02128374();
  }
  return;
}

