/* Decompiled C draft; module arm9; ROM address 02019df8. No matching claim. */
#include "types.h"
#include "deps/02019df8_func_02019df8.h"

void func_02019df8(int param_1)

{
  uint uVar1;
  ushort uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  
  uVar1 = param_1 + 0xcU & 3;
  uVar6 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar7 = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 4U & 3;
  uVar6 = *(uint *)(param_1 + 4U & 0xfffffffc);
  *puRam02019ed0 =
       (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) >> 3 | (uVar7 & 0xf) << 0x1a | 0x40000000 |
       ((uVar7 << 0x18) >> 0x1c) << 0x14 | ((uVar7 << 0x14) >> 0x1c) << 0x17 |
       ((uVar7 << 0x12) >> 0x1e) << 0x10 | ((uVar7 << 0x10) >> 0x1e) << 0x12 |
       ((uVar7 << 0xf) >> 0x1f) << 0x1d;
  puVar3 = puRam02019ed8;
  uVar1 = param_1 + 8U & 3;
  uVar6 = *(uint *)(param_1 + 8U & 0xfffffffc);
  *puRam02019ed4 =
       (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) >> (4 - ((uVar7 & 0xf) == 2) & 0xff);
  puVar4 = puRam02019edc;
  *puVar3 = 3;
  *puVar4 = 0;
  piVar5 = piRam02019ee0;
  uVar2 = *(ushort *)(param_1 + 0x12);
  *piRam02019ee0 = (uint)*(ushort *)(param_1 + 0x10) << 0xc;
  *piVar5 = (uint)uVar2 << 0xc;
  *piVar5 = 0;
  *puVar3 = 1;
  return;
}

