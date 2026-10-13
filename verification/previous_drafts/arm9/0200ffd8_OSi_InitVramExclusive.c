/* Decompiled C draft; module arm9; ROM address 0200ffd8. No matching claim. */
#include "types.h"
#include "deps/0200ffd8_OSi_InitVramExclusive.h"

void OSi_InitVramExclusive(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  *puRam02010004 = 0;
  iVar2 = iRam02010008;
  do {
    iVar1 = iVar3 * 2;
    iVar3 = iVar3 + 1;
    *(undefined2 *)(iVar2 + iVar1) = 0;
  } while (iVar3 < 9);
  return;
}

