/* Decompiled C draft; module arm9; ROM address 02019b28. No matching claim. */
#include "types.h"
#include "deps/02019b28_func_02019b28.h"

void func_02019b28(uint *param_1,uint param_2,uint param_3)

{
  undefined2 uVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  param_1[8] = param_2;
  param_1[9] = 0;
  uVar3 = uRam02019df0;
  uVar5 = (uint)(param_1 + 8) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar2 = (undefined2)uRam02019dec;
  uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 4;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  param_1[10] = (*(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
                *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20) +
                (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20);
  uVar5 = (uint)(param_1 + 8) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
  uVar6 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar4 = param_3 + 4 & 3;
  uVar7 = *(uint *)(param_3 + 4 & 0xfffffffc);
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar5 = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 8;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  param_1[0xb] = (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) +
                 (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20);
  uVar5 = (uint)(param_1 + 8) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
  uVar6 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar4 = param_3 + 8 & 3;
  uVar7 = *(uint *)(param_3 + 8 & 0xfffffffc);
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar5 = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 0xc;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  param_1[0xc] = (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) +
                 (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20);
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0xf] = 0;
  uVar5 = (uint)(param_1 + 0xf) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 0xf) & 0xfffffffc);
  param_1[0xe] = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = (uint)(param_1 + 0xe) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 0xe) & 0xfffffffc);
  param_1[0xd] = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  *(undefined2 *)(param_1 + 0x13) = 0;
  *(undefined2 *)((int)param_1 + 0x4e) = 0;
  uVar5 = (uint)(param_1 + 8) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar1 = *(undefined2 *)(uVar5 + 0x1e);
  *(undefined2 *)(param_1 + 0x14) = *(undefined2 *)(uVar5 + 0x1c);
  *(undefined2 *)((int)param_1 + 0x52) = uVar1;
  *(undefined2 *)(param_1 + 0x15) = *(undefined2 *)(uVar5 + 0x20);
  uVar5 = (uint)(param_1 + 8) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(undefined2 *)((int)param_1 + 0x56) =
       *(undefined2 *)((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x38);
  uVar5 = (uint)(param_1 + 8) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x10;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  param_1[0x16] = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  uVar5 = (uint)(param_1 + 8) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x14;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  param_1[0x17] = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  uVar5 = (uint)(param_1 + 8) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x18;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  param_1[0x18] = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  uVar5 = (uint)(param_1 + 8) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x24;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  param_1[0x19] = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  uVar5 = (uint)(param_1 + 8) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x28;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  param_1[0x1a] = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  uVar5 = (uint)(param_1 + 8) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x2c;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  param_1[0x1b] = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  uVar5 = (uint)(param_1 + 8) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(undefined2 *)(param_1 + 0x1c) =
       *(undefined2 *)((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x3e);
  *(undefined2 *)((int)param_1 + 0x72) = uVar2;
  uVar5 = (uint)(param_1 + 8) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(undefined1 *)(param_1 + 0x20) =
       *(undefined1 *)((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x44);
  uVar5 = (uint)(param_1 + 8) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(undefined1 *)((int)param_1 + 0x81) =
       *(undefined1 *)((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x45);
  uVar5 = (uint)(param_1 + 0x20) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 0x20) & 0xfffffffc);
  param_1[0x20] = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0xfff8ffff;
  uVar5 = (uint)(param_1 + 0x20) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 0x20) & 0xfffffffc);
  param_1[0x20] = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & uVar3;
  param_1[0x1d] = 0x80000000;
  uVar5 = (uint)(param_1 + 8) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x48;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *(short *)(param_1 + 0x1e) =
       (short)(0x1000 << (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) << 6) >> 0x1e));
  uVar5 = (uint)(param_1 + 8) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x48;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *(short *)((int)param_1 + 0x7a) =
       (short)(0x1000 << (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) << 4) >> 0x1e));
  uVar5 = (uint)(param_1 + 8) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x4c;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if ((int)((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) << 0x1f) < 0) {
    *(short *)(param_1 + 0x1e) = -(short)param_1[0x1e];
  }
  uVar5 = (uint)(param_1 + 8) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x4c;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if ((int)((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) << 0x1e) < 0) {
    *(short *)((int)param_1 + 0x7a) = -*(short *)((int)param_1 + 0x7a);
  }
  uVar5 = (uint)(param_1 + 8) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
  uVar6 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar4 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
          *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if ((int)((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) << 0xf) < 0) {
    uVar5 = uVar6 + 0x14 & 3;
    uVar4 = *(uint *)(uVar6 + 0x14 & 0xfffffffc);
    uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x10;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(short *)(param_1 + 0x1f) =
         (short)(0x1000 << ((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 3));
    uVar5 = (uint)(param_1 + 8) & 3;
    uVar4 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
    uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x14;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + 0x10;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(short *)((int)param_1 + 0x7e) =
         (short)(0x1000 << (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) << 0x1c) >> 0x1e));
    uVar5 = (uint)(param_1 + 8) & 3;
    uVar4 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
    uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x14;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + 0x10;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    if ((int)((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) << 0x1b) < 0) {
      *(short *)(param_1 + 0x1f) = -(short)param_1[0x1f];
    }
    uVar5 = (uint)(param_1 + 8) & 3;
    uVar4 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
    uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x14;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + 0x10;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    if ((int)((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) << 0x1a) < 0) {
      *(short *)((int)param_1 + 0x7e) = -*(short *)((int)param_1 + 0x7e);
    }
  }
  param_1[1] = 0;
  uVar5 = (uint)(param_1 + 1) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  *param_1 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  param_1[5] = 0;
  uVar5 = (uint)(param_1 + 5) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 5) & 0xfffffffc);
  param_1[2] = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  param_1[6] = 0;
  uVar5 = (uint)(param_1 + 6) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
  param_1[3] = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  return;
}

