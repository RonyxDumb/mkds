/* Decompiled C draft; module arm9; ROM address 02058b38. No matching claim. */
#include "types.h"
#include "deps/02058b38_func_02058b38.h"

void func_02058b38(void)

{
  int iVar1;
  
  if ((int *)*piRam02058b68 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)*piRam02058b68;
  }
  if (iVar1 == 1) {
    *(byte *)(*piRam02058b68 + iRam02058b6c) = *(byte *)(*piRam02058b68 + 0x87) | 1;
  }
  *(undefined2 *)(*piRam02058b68 + iRam02058b70) = 0;
  return;
}

