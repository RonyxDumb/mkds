/* Decompiled C draft; module arm9; ROM address 02021c34. No matching claim. */
#include "types.h"
#include "deps/02021c34_func_02021c34.h"

void func_02021c34(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar5;
  int iVar6;
  uint uVar4;
  
  Sound_LockMutex();
  uVar5 = param_1 + 0x18;
  iVar6 = 0;
  do {
    iVar2 = param_1 + iVar6 * 8;
    uVar1 = iVar2 + 0x18;
    uVar4 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    uVar1 = uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20;
    if (uVar1 != 0) {
      uVar4 = uVar1 + 0x18 & 3;
      uVar3 = *(uint *)(uVar1 + 0x18 & 0xfffffffc);
      uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      if (uVar5 == uVar4) {
        uVar4 = iVar2 + 0x1c;
        uVar3 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        *(uint *)(uVar1 + 0x18) = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
        DC_SomeClean(uVar1,0x3c);
      }
      else {
        do {
          uVar1 = uVar4;
          if (uVar1 == 0) break;
          uVar4 = uVar1 + 4 & 3;
          uVar3 = *(uint *)(uVar1 + 4 & 0xfffffffc);
          uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
        } while (uVar5 != uVar4);
        uVar4 = param_1 + iVar6 * 8 + 0x1c;
        uVar3 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        *(uint *)(uVar1 + 4) = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
        DC_SomeClean(uVar1,8);
      }
    }
    iVar6 = iVar6 + 1;
    uVar5 = uVar5 + 8;
    if (3 < iVar6) {
      Sound_UnlockMutex();
      return;
    }
  } while( true );
}

