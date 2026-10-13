/* Decompiled C draft; module arm9; ROM address 0203023c. No matching claim. */
#include "types.h"
#include "deps/0203023c_func_0203023c.h"

undefined4 func_0203023c(void)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = 1;
  iVar3 = *(int *)(*piRam02030270 + 0x48);
  if (iVar3 != 4) {
    bVar1 = false;
    iVar3 = *piRam02030270 + iVar3 * 0xc;
    if ((*(int *)(iVar3 + 0x58) != 0) && (*(int *)(iVar3 + 0x60) < 7)) {
      bVar1 = true;
    }
    if (!bVar1) {
      uVar2 = 0;
    }
  }
  return uVar2;
}

