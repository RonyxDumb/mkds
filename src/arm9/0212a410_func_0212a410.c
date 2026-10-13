/* Decompiled C draft; module arm9; ROM address 0212a410. No matching claim. */
#include "types.h"
#include "deps/0212a410_func_0212a410.h"

void func_0212a410(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  Mem_CpuFill8((uint *)(uintptr_t)(*piRam0212a444 + 0x5c),0,0xd);
  piVar1 = piRam0212a444;
  iVar3 = 0;
  iVar2 = 0;
  do {
    *(char *)(*piVar1 + iVar3 + 0x5c) = (char)*(undefined2 *)(*piVar1 + iVar2 + 0x2c);
    iVar2 = iVar2 + 2;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0xc);
  return;
}

