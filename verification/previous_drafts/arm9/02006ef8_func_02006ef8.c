/* Decompiled C draft; module arm9; ROM address 02006ef8. No matching claim. */
#include "types.h"
#include "deps/02006ef8_func_02006ef8.h"

int func_02006ef8(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  for (iVar1 = GetGlobalGO_from_thumb(); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x28)) {
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}

