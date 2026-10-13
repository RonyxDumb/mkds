/* Decompiled C draft; module arm9; ROM address 021035ac. No matching claim. */
#include "types.h"
#include "deps/021035ac_func_021035ac.h"

void func_021035ac(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  if (param_1 !=
      *(char *)((*(uint *)(uRam02103654 & 0xfffffffc) >> (uRam02103654 & 3) * 8 |
                *(uint *)(uRam02103654 & 0xfffffffc) << (uRam02103654 & 3) * -8 + 0x20) + 0x62)) {
    return;
  }
  uVar6 = *(uint *)(uRam02103658 & 0xfffffffc) >> (uRam02103658 & 3) * 8 |
          *(uint *)(uRam02103658 & 0xfffffffc) << (uRam02103658 & 3) * -8 + 0x20;
  if (uVar6 == 0) {
    return;
  }
  uVar5 = *(uint *)(uRam0210365c & 0xfffffffc) >> (uRam0210365c & 3) * 8 |
          *(uint *)(uRam0210365c & 0xfffffffc) << (uRam0210365c & 3) * -8 + 0x20;
  iVar7 = 0;
  if ((int)(*(uint *)((uint)puRam02103660 & 0xfffffffc) >> ((uint)puRam02103660 & 3) * 8 |
           *(uint *)((uint)puRam02103660 & 0xfffffffc) << ((uint)puRam02103660 & 3) * -8 + 0x20) <
      (int)uVar5) {
    *puRam02103660 = uVar5;
  }
  uVar2 = uRam02103668;
  uVar1 = uRam02103664;
  uVar5 = uRam02103658;
  iVar8 = iVar7;
  if ((int)uVar6 < 1) {
    return;
  }
  do {
    uVar6 = uVar2 & 3;
    uVar3 = *(uint *)(uVar2 & 0xfffffffc);
    iVar4 = (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) + iVar7;
    uVar6 = iVar4 + 0x28;
    uVar3 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    if ((uVar6 >> uVar3 * 8 == 0 && uVar6 << uVar3 * -8 + 0x20 == 0) &&
       (uVar6 = iVar4 + 0x24, uVar3 = uVar6 & 3, uVar6 = *(uint *)(uVar6 & 0xfffffffc),
       (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) == uVar1)) {
      func_0210366c();
    }
    uVar6 = uVar5 & 3;
    uVar3 = *(uint *)(uVar5 & 0xfffffffc);
    iVar8 = iVar8 + 1;
    iVar7 = iVar7 + 0x34;
  } while (iVar8 < (int)(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20));
  return;
}

