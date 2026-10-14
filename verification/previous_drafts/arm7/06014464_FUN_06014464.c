/* Decompiled C draft; module arm7; ROM address 06014464. No matching claim. */
#include "types.h"
#include "deps/06014464_FUN_06014464.h"

void FUN_06014464(void)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = *(uint *)(DAT_0601454c & 0xfffffffc) >> (DAT_0601454c & 3) * 8 |
          *(uint *)(DAT_0601454c & 0xfffffffc) << (DAT_0601454c & 3) * -8 + 0x20;
  iVar4 = uVar2 + DAT_06014550;
  sVar1 = *(short *)(uVar2 + 0x350);
  if (sVar1 == 1) {
    FUN_060143cc(0,1);
    FUN_060143cc(1,0);
    FUN_060143cc(2,1);
    if (*(short *)(iVar4 + 0x3c) != 0) {
      *(undefined2 *)(iVar4 + 0x3c) = 0;
      *(short *)(iVar4 + 0x3e) = *(short *)(iVar4 + 0x3e) + -1;
      uVar2 = iVar4 + 0x90U & 3;
      uVar3 = *(uint *)(iVar4 + 0x90U & 0xfffffffc);
      FUN_060090b4((*(uint *)(DAT_0601454c & 0xfffffffc) >> (DAT_0601454c & 3) * 8 |
                   *(uint *)(DAT_0601454c & 0xfffffffc) << (DAT_0601454c & 3) * -8 + 0x20) + 0x188,
                   uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
    }
  }
  else if ((sVar1 == 2) || (sVar1 == 3)) {
    FUN_060143cc(0,1);
    FUN_060143cc(1,0);
    FUN_060143cc(2,0);
  }
  else {
    FUN_060143cc(0,0);
    FUN_060143cc(1,0);
    FUN_060143cc(2,0);
  }
  return;
}

