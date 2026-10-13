/* Decompiled C draft; module arm9; ROM address 020817b8. No matching claim. */
#include "types.h"
#include "deps/020817b8_func_020817b8.h"

void func_020817b8(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = 0;
  iVar6 = param_1 * 0xc +
          (*(uint *)(uRam02081818 & 0xfffffffc) >> (uRam02081818 & 3) * 8 |
          *(uint *)(uRam02081818 & 0xfffffffc) << (uRam02081818 & 3) * -8 + 0x20);
  do {
    uVar4 = iVar6 + uVar5 * 4;
    uVar2 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar4 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
    iVar1 = uVar5 * 4;
    if (uVar4 != 0) {
      uVar2 = uVar4 + 0x24 & 3;
      uVar3 = *(uint *)(uVar4 + 0x24 & 0xfffffffc);
      *(uint *)(uVar4 + 0x24) = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0xfffffffe | 1;
    }
    uVar5 = uVar5 + 1 & 0xffff;
    if (uVar4 != 0) {
      *(undefined4 *)(iVar6 + iVar1) = 0;
    }
  } while (uVar5 < 3);
  return;
}

