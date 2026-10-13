/* Decompiled C draft; module arm9; ROM address 020ab500. No matching claim. */
#include "types.h"
#include "deps/020ab500_func_020ab500.h"

undefined2 func_020ab500(void)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = func_020ab59c(iRam020ab524);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = func_020ab640(*(undefined2 *)(iRam020ab524 + 10));
  }
  return uVar1;
}

