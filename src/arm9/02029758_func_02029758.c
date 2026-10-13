/* Decompiled C draft; module arm9; ROM address 02029758. No matching claim. */
#include "types.h"
#include "deps/02029758_func_02029758.h"

void func_02029758(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  piVar2 = piRam020297b8;
  piVar1 = piRam020297b4;
  uVar5 = 0;
  do {
    iVar3 = func_02122794(uVar5);
    if (iVar3 != 0) {
      iVar3 = func_02122734(uVar5);
      iVar4 = uVar5 * 0x18;
      iVar3 = iVar3 * 0xc;
      *(undefined4 *)(*piVar2 + iVar3 + 0x20) = *(undefined4 *)(*piVar1 + iVar4);
      *(undefined4 *)(*piVar2 + iVar3 + 0x24) = *(undefined4 *)(*piVar1 + iVar4 + 4);
      *(undefined4 *)(*piVar2 + iVar3 + 0x28) = *(undefined4 *)(*piVar1 + iVar4 + 8);
    }
    uVar5 = uVar5 + 1 & 0xff;
  } while (uVar5 < 4);
  return;
}

