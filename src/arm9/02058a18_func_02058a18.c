/* Decompiled C draft; module arm9; ROM address 02058a18. No matching claim. */
#include "types.h"
#include "deps/02058a18_func_02058a18.h"

void func_02058a18(void)

{
  int *piVar1;
  
  piVar1 = piRam02058a34;
  *(undefined4 *)(*piRam02058a34 + iRam02058a38) = 0;
  *(byte *)(*piVar1 + iRam02058a3c) = *(byte *)(*piVar1 + iRam02058a3c) & 0xfd;
  return;
}

