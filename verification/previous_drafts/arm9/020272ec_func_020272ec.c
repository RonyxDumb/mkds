/* Decompiled C draft; module arm9; ROM address 020272ec. No matching claim. */
#include "types.h"
#include "deps/020272ec_func_020272ec.h"

void func_020272ec(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*psRam02027338 != 2) {
    iVar2 = *piRam0202733c;
    iVar3 = 0;
    *(undefined4 *)(*(int *)(iVar2 + 0x34) + iRam02027340) = 0;
    *(undefined4 *)(*(int *)(iVar2 + 0x34) + iRam02027344) = 1;
    iVar1 = iRam02027348;
    do {
      *(undefined2 *)(*(int *)(iVar2 + 0x34) + *(short *)(iVar1 + 2) * 0x40 + 4) = 0;
      *(undefined2 *)(*(int *)(iVar2 + 0x34) + *(short *)(iVar1 + 2) * 0x40 + 6) = 0;
      iVar1 = iVar1 + 8;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0xc);
  }
  return;
}

