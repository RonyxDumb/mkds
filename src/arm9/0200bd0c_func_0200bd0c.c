/* Decompiled C draft; module arm9; ROM address 0200bd0c. No matching claim. */
#include "types.h"
#include "deps/0200bd0c_func_0200bd0c.h"

undefined4 func_0200bd0c(void)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = 0;
  bVar1 = false;
  iVar3 = *piRam0200bd30;
  if ((*(short *)(iVar3 + 0x1a) == 1) && (*(short *)(iVar3 + 0x20) == 0)) {
    bVar1 = true;
  }
  if ((bVar1) && (*(short *)(iVar3 + 0x1c) == 0)) {
    uVar2 = 1;
  }
  return uVar2;
}

