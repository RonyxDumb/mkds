/* Decompiled C draft; module arm9; ROM address 02043b04. No matching claim. */
#include "types.h"
#include "deps/02043b04_func_02043b04.h"

void func_02043b04(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = iRam02043b38;
  do {
    StructCY_SomeFn_1(iVar1);
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 0x5c;
  } while (iVar2 < 10);
  return;
}

