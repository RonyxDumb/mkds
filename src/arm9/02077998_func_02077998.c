/* Decompiled C draft; module arm9; ROM address 02077998. No matching claim. */
#include "types.h"
#include "deps/02077998_func_02077998.h"

void func_02077998(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  *puRam020779f4 = uRam020779f0;
  *puRam020779f8 = 1;
  uVar2 = 0;
  *puRam020779fc = 0;
  piVar1 = (int *)*piRam02077a00;
  if (piVar1[2] == 4) {
    uVar2 = (uint)*(byte *)((int)piVar1 + 0x36);
  }
  iVar3 = uVar2 * 0xc;
  *puRam02077a08 = *(undefined4 *)(iRam02077a04 + iVar3);
  *puRam02077a10 = *(undefined4 *)(iRam02077a0c + iVar3);
  *puRam02077a18 = *(undefined4 *)(iRam02077a14 + iVar3);
  if (*piVar1 == 0x13) {
    *puRam02077a20 = uRam02077a1c;
    return;
  }
  *puRam02077a20 = uRam02077a24;
  return;
}

