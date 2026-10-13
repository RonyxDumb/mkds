/* Decompiled C draft; module arm9; ROM address 0211e4e8. No matching claim. */
#include "types.h"
#include "deps/0211e4e8_func_0211e4e8.h"

void func_0211e4e8(void)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = uRam0211e510;
  piVar1 = piRam0211e50c;
  *puRam0211e514 = *(int *)(*piRam0211e50c + 0x3c) * -0x10000 & uRam0211e510;
  *puRam0211e518 = *(int *)(*piVar1 + 0x40) * -0x10000 & uVar2;
  return;
}

