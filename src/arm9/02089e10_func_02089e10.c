/* Decompiled C draft; module arm9; ROM address 02089e10. No matching claim. */
#include "types.h"
#include "deps/02089e10_func_02089e10.h"

void func_02089e10(int param_1)

{
  int iVar1;
  uint *puVar2;
  
  puVar2 = puRam02089e64;
  iVar1 = iRam02089e60;
  *puRam02089e64 =
       CONCAT22(*(undefined2 *)(iRam02089e60 + (param_1 * 3 + 1) * 2),
                *(undefined2 *)(iRam02089e60 + param_1 * 6));
  *puVar2 = (uint)*(ushort *)(iVar1 + (param_1 * 3 + 2) * 2);
  return;
}

