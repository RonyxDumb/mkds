/* Decompiled C draft; module arm9; ROM address 0210bc14. No matching claim. */
#include "types.h"
#include "deps/0210bc14_ClearGlobalVA.h"

void ClearGlobalVA(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0x17;
  puVar2 = puRam0210bc50;
  do {
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[6] = 0;
    puVar2[7] = 0;
    puVar2 = puVar2 + 8;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

