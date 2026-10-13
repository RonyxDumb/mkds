/* Decompiled C draft; module arm9; ROM address 0201910c. No matching claim. */
#include "types.h"
#include "deps/0201910c_func_0201910c.h"

void func_0201910c(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  uint uVar5;
  uint uVar7;
  uint uVar6;
  
  uVar5 = param_1 + 0x40U & 3;
  uVar7 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  uVar7 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
  pcVar4 = (code *)0x0;
  uVar5 = uVar7 + 0x20;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar6 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
  uVar1 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
          *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
  uVar5 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if (-1 < (int)((uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) << 0xf)) {
    return;
  }
  uVar5 = uVar6 + 0x14 & 3;
  uVar2 = *(uint *)(uVar6 + 0x14 & 0xfffffffc);
  uVar1 = param_1 + 0x2cU & 3;
  uVar3 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
  func_02019df8((uint)*(byte *)((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) + 0xf) * 0x14 +
                (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20));
  uVar5 = uVar6 + 0x14 & 3;
  uVar1 = *(uint *)(uVar6 + 0x14 & 0xfffffffc);
  switch(((uint)*(ushort *)(uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) << 0x17) >> 0x1e) {
  case 0:
    pcVar4 = DAT_020191e4;
    break;
  case 1:
    pcVar4 = DAT_020191e8;
    break;
  case 2:
    pcVar4 = DAT_020191ec;
    break;
  case 3:
    pcVar4 = DAT_020191f0;
  }
  uVar7 = uVar7 + 0x14;
  uVar5 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar5 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
  if (uVar5 == 0) {
    return;
  }
  do {
    (*pcVar4)(param_1,uVar5);
    uVar5 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
            *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
  } while (uVar5 != 0);
  return;
}

