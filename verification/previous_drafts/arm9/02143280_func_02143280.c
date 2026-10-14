/* Decompiled C draft; module arm9; ROM address 02143280. No matching claim. */
#include "types.h"
#include "deps/02143280_func_02143280.h"

undefined2 func_02143280(void)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = Wm_CheckInitialized();
  if (iVar2 == 0) {
    uVar1 = *puRam021432a8;
  }
  else {
    uVar1 = 0x8000;
  }
  return uVar1;
}

