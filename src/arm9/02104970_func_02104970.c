/* Decompiled C draft; module arm9; ROM address 02104970. No matching claim. */
#include "types.h"
#include "deps/02104970_func_02104970.h"

void func_02104970(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (*(int *)(*piRam02104998 + 8) == 2) {
    iVar3 = 0;
    puVar1 = puRam021049a0;
    puVar2 = puRam0210499c;
    do {
      *puVar2 = 0xffffffff;
      puVar2 = puVar2 + 1;
      *puVar1 = 0;
      puVar1 = puVar1 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 8);
  }
  return;
}

