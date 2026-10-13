/* Decompiled C draft; module arm9; ROM address 0209753c. No matching claim. */
#include "types.h"
#include "deps/0209753c_func_0209753c.h"

undefined4 func_0209753c(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = func_02100138(uRam02097568);
  iVar2 = func_0209bc5c(uVar1,param_1);
  *(undefined4 *)(iVar2 + 0xebc) = 0xaa;
  return 1;
}

