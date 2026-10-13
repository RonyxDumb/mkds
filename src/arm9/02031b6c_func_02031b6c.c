/* Decompiled C draft; module arm9; ROM address 02031b6c. No matching claim. */
#include "types.h"
#include "deps/02031b6c_func_02031b6c.h"

void func_02031b6c(void)

{
  int *piVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = piRam02031b9c;
  iVar3 = *piRam02031b9c;
  iVar4 = 0;
  puVar2 = puRam02031ba0;
  do {
    *(uint *)(*(int *)(iVar3 + 0x3c) + (uint)*puVar2 * 0x40) =
         (uint)(iVar4 == *(int *)(*piVar1 + 0x74));
    puVar2 = puVar2 + 1;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 8);
  return;
}

