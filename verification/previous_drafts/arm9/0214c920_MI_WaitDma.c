/* Decompiled C draft; module arm9; ROM address 0214c920. No matching claim. */
#include "types.h"
#include "deps/0214c920_MI_WaitDma.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MI_WaitDma(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  Os_DisableIrq();
  uVar3 = uRam0214c98c;
  iVar2 = iRam0214c988;
  uVar5 = iRam0214c988 + (param_1 * 3 + 2) * 4;
  do {
    uVar1 = uVar5 & 3;
    uVar4 = *(uint *)(uVar5 & 0xfffffffc);
  } while (((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0x80000000) != 0);
  if (param_1 == 0) {
    _DAT_040000b0 = 0;
    *(undefined4 *)(iRam0214c988 + 4) = 0;
    *(undefined4 *)(iVar2 + 8) = uVar3;
  }
  Os_RestoreIrq();
  return;
}

