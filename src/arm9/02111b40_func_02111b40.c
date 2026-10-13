/* Decompiled C draft; module arm9; ROM address 02111b40. No matching claim. */
#include "types.h"
#include "deps/02111b40_func_02111b40.h"

void func_02111b40(void)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = uRam02111b88;
  uVar2 = uRam02111b84;
  piVar1 = piRam02111b80;
  *puRam02111b8c =
       -*(int *)(*piRam02111b80 + 0x58) & uRam02111b84 |
       *(int *)(*piRam02111b80 + 0x5c) * -0x10000 & uRam02111b88;
  *puRam02111b90 = -*(int *)(*piVar1 + 0x60) & uVar2 | *(int *)(*piVar1 + 100) * -0x10000 & uVar3;
  func_02111428();
  return;
}

