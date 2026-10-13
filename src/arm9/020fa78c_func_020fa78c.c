/* Decompiled C draft; module arm9; ROM address 020fa78c. No matching claim. */
#include "types.h"
#include "deps/020fa78c_func_020fa78c.h"

void func_020fa78c(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 uVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = param_1 * 0x210;
  uVar3 = (*(uint *)(uRam020fa8a4 & 0xfffffffc) >> (uRam020fa8a4 & 3) * 8 |
          *(uint *)(uRam020fa8a4 & 0xfffffffc) << (uRam020fa8a4 & 3) * -8 + 0x20) + iVar6 + 0x30;
  uVar5 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) != 0x13) {
    return;
  }
  uVar5 = *(uint *)(uRam020fa8a8 & 0xfffffffc) >> (uRam020fa8a8 & 3) * 8 |
          *(uint *)(uRam020fa8a8 & 0xfffffffc) << (uRam020fa8a8 & 3) * -8 + 0x20;
  uVar3 = param_1 * 0x30 + uVar5 + 0x70;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  if (uVar3 != 3) {
    uVar5 = uVar5 + 8;
    uVar1 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    if ((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) != 2) {
      uVar4 = 0;
      if ((uVar3 < 4) && ((1 << (uVar3 & 0xff) & 0xdU) != 0)) {
        uVar4 = 1;
      }
      uVar2 = GetDriverPlace();
      func_020f87a8((*(uint *)(uRam020fa8a4 & 0xfffffffc) >> (uRam020fa8a4 & 3) * 8 |
                    *(uint *)(uRam020fa8a4 & 0xfffffffc) << (uRam020fa8a4 & 3) * -8 + 0x20) + iVar6,
                    param_2,uVar2,uVar4);
      return;
    }
    uVar4 = 0;
    if ((uVar3 < 4) && ((1 << (uVar3 & 0xff) & 0xdU) != 0)) {
      uVar4 = 1;
    }
    uVar2 = func_020a1cd8();
    func_020f87a8((*(uint *)(uRam020fa8a4 & 0xfffffffc) >> (uRam020fa8a4 & 3) * 8 |
                  *(uint *)(uRam020fa8a4 & 0xfffffffc) << (uRam020fa8a4 & 3) * -8 + 0x20) + iVar6,
                  param_2,uVar2,uVar4);
    return;
  }
  return;
}

