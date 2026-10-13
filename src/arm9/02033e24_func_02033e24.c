/* Decompiled C draft; module arm9; ROM address 02033e24. No matching claim. */
#include "types.h"
#include "deps/02033e24_func_02033e24.h"

byte func_02033e24(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  bVar1 = 1;
  iVar4 = 0;
  iVar2 = *piRam02033e68;
  iVar3 = iVar2;
  if (0 < *(int *)(iVar2 + 0xd8)) {
    do {
      bVar1 = bVar1 & *(int *)(iVar3 + 0xe4) == 0;
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0xc;
    } while (iVar4 < *(int *)(iVar2 + 0xd8));
  }
  return bVar1;
}

