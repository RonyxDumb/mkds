/* Decompiled C draft; module arm9; ROM address 02118e30. No matching claim. */
#include "types.h"
#include "deps/02118e30_func_02118e30.h"

void func_02118e30(void)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = uRam02118e58;
  piVar1 = piRam02118e54;
  *puRam02118e5c = *(int *)(*piRam02118e54 + 0x44) * -0x10000 & uRam02118e58;
  *puRam02118e60 = *(int *)(*piVar1 + 0x48) * -0x10000 & uVar2;
  return;
}

