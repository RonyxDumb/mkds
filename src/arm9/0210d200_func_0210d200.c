/* Decompiled C draft; module arm9; ROM address 0210d200. No matching claim. */
#include "types.h"
#include "deps/0210d200_func_0210d200.h"

void func_0210d200(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar5;
  uint uVar4;
  
  iVar2 = iRam0210d2c8;
  uVar1 = uRam0210d2c4;
  uVar5 = *(uint *)(uRam0210d2c4 & 0xfffffffc) >> (uRam0210d2c4 & 3) * 8 |
          *(uint *)(uRam0210d2c4 & 0xfffffffc) << (uRam0210d2c4 & 3) * -8 + 0x20;
  if (uVar5 == 0) {
    return;
  }
  do {
    uVar4 = uVar5 + 0xc & 3;
    uVar3 = *(uint *)(uVar5 + 0xc & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    if (uVar4 != 0) {
      do {
        func_0212c6f0(uVar4,param_1);
        *(byte *)(uVar4 + 0x19) = *(byte *)(uVar4 + 0x19) & 0xfb;
        *(byte *)(uVar4 + 0x19) = *(byte *)(uVar4 + 0x19) & 0xf7;
        *(byte *)(uVar4 + 0x19) = *(byte *)(uVar4 + 0x19) & 0xfd;
        func_0210bc54(uVar5 + 0xc,uVar4);
        uVar4 = uVar5 + 0xc & 3;
        uVar3 = *(uint *)(uVar5 + 0xc & 0xfffffffc);
        uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      } while (uVar4 != 0);
    }
    uVar4 = uVar5 + 0x18 & 3;
    uVar3 = *(uint *)(uVar5 + 0x18 & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    if (uVar4 != 3) {
      func_0210bc54(uVar4 * 0xc + iVar2,uVar5);
      *(undefined4 *)(uVar5 + 0x18) = 3;
    }
    uVar5 = IntrusiveListWrapper_NextItem(uVar1,uVar5);
  } while (uVar5 != 0);
  return;
}

