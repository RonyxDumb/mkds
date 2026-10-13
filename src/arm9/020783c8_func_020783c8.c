/* Decompiled C draft; module arm9; ROM address 020783c8. No matching claim. */
#include "types.h"
#include "deps/020783c8_func_020783c8.h"

void func_020783c8(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = (int)*(short *)(*piRam02078410 + iRam02078414);
  if (-1 < iVar3) {
    Animation_Update(*(undefined4 *)(*piRam02078410 + iVar3 * 0xb8 + 0x60));
    if (*(int *)(*piRam02078410 + *(short *)(*piRam02078410 + iRam02078418) * 0x34 + iRam0207841c)
        == 0) {
      uVar1 = func_0x021a2398();
      uVar2 = func_0x021a23ac();
      func_02078e4c(uVar1,uVar2);
    }
  }
  return;
}

