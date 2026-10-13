/* Decompiled C draft; module arm9; ROM address 020636f8. No matching claim. */
#include "types.h"
#include "deps/020636f8_func_020636f8.h"

void func_020636f8(int param_1)

{
  uint uVar1;
  uint uVar3;
  uint uVar4;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar2;
  uint uVar5;
  
  uVar7 = param_1 + 0x80U & 3;
  uVar3 = *(uint *)(param_1 + 0x80U & 0xfffffffc);
  uVar4 = param_1 + 0x514U & 3;
  uVar1 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar2 = uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20;
  uVar4 = (*(uint *)(uRam020637c0 & 0xfffffffc) >> (uRam020637c0 & 3) * 8 |
          *(uint *)(uRam020637c0 & 0xfffffffc) << (uRam020637c0 & 3) * -8 + 0x20) + 0x754;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  *(short *)(uVar5 + 0xc) = (short)((int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) >> 10);
  uVar4 = param_1 + 0x84U & 3;
  uVar3 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  uVar7 = param_1 + 700U & 3;
  uVar1 = *(uint *)(param_1 + 700U & 0xfffffffc);
  *(short *)(uVar5 + 0xe) =
       (short)((int)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) -
                    (uVar1 >> uVar7 * 8 | uVar1 << uVar7 * -8 + 0x20)) >> 10);
  uVar4 = param_1 + 0x88U & 3;
  uVar7 = *(uint *)(param_1 + 0x88U & 0xfffffffc);
  *(short *)(uVar5 + 0x10) = (short)((int)(uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) >> 10);
  uVar4 = param_1 + 0x2a8U & 3;
  uVar7 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc);
  *(short *)(uVar5 + 0x12) = (short)((int)(uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) >> 2);
  *(undefined2 *)(uVar5 + 0x16) = *(undefined2 *)(param_1 + 0x236);
  uVar4 = param_1 + 0x44U & 3;
  uVar7 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  *(uint *)(uVar5 + 0x1c) = uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20;
  uVar4 = uVar2 + 0x98 & 3;
  uVar9 = *(uint *)(uVar2 + 0x98 & 0xfffffffc);
  uVar7 = uVar2 + 0x9c & 3;
  uVar6 = *(uint *)(uVar2 + 0x9c & 0xfffffffc);
  uVar1 = uVar2 + 0xa0 & 3;
  uVar8 = *(uint *)(uVar2 + 0xa0 & 0xfffffffc);
  uVar3 = uVar5 + 0x1c & 3;
  uVar10 = *(uint *)(uVar5 + 0x1c & 0xfffffffc);
  *(uint *)(uVar5 + 0x1c) =
       uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20 |
       ((int)(uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) >> 6) << 0x18 |
       ((int)(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) >> 6 & 0xffU) << 0x10 |
       ((int)(uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20) >> 6 & 0xffU) << 8;
  uVar4 = param_1 + 0x48U & 3;
  uVar7 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(uVar5 + 0x20) = uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20;
  uVar4 = uVar2 + 0x2c & 3;
  uVar7 = *(uint *)(uVar2 + 0x2c & 0xfffffffc);
  *(uint *)(uVar5 + 0x18) = uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20;
  *(undefined2 *)(uVar5 + 0x14) = *(undefined2 *)(param_1 + 0x388);
  return;
}

