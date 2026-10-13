/* Decompiled C draft; module arm9; ROM address 0214ef00. No matching claim. */
#include "types.h"
#include "deps/0214ef00_func_0214ef00.h"

bool func_0214ef00(void)

{
  int iVar1;
  
  iVar1 = Fifo_SendWord(9,uRam0214ef30,0);
  return -1 < iVar1;
}

