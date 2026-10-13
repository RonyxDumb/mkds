/* Decompiled C draft; module arm9; ROM address 020d5dd0. No matching claim. */
#include "types.h"
#include "deps/020d5dd0_func_020d5dd0.h"

void func_020d5dd0(int param_1)

{
  ushort *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  
  func_020d859c(param_1 + 0xa4,0,1);
  func_020d8b18(param_1 + 0xa4,param_1 + 4,param_1 + 0x10);
  uVar7 = param_1 + 0xdcU & 3;
  uVar3 = *(uint *)(param_1 + 0xdcU & 0xfffffffc);
  *(uint *)(param_1 + 0xe0) = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
  puVar1 = puRam020d5f54;
  uVar7 = param_1 + 0xe0U & 3;
  uVar3 = *(uint *)(param_1 + 0xe0U & 0xfffffffc);
  if (uVar3 >> uVar7 * 8 != 0 || uVar3 << uVar7 * -8 + 0x20 != 0) {
    *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam020d5f50;
    *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puVar1;
  }
  *(undefined4 *)(param_1 + 0xe4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0xe8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 0xf4) = 1;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(undefined4 *)(param_1 + 0xfc) = 0;
  *(undefined4 *)(param_1 + 0x100) = 0;
  *(undefined4 *)(param_1 + 0x104) = 0;
  uVar7 = param_1 + 0xa0U & 3;
  uVar3 = *(uint *)(param_1 + 0xa0U & 0xfffffffc);
  *(uint *)(param_1 + 8) = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
  puVar2 = puRam020d5f58;
  *(undefined4 *)(param_1 + 0x14) = 0x8000;
  uVar4 = puVar2[1];
  uVar6 = puVar2[2];
  *(undefined4 *)(param_1 + 0x28) = *puVar2;
  *(undefined4 *)(param_1 + 0x2c) = uVar4;
  *(undefined4 *)(param_1 + 0x30) = uVar6;
  uVar4 = puRam020d5f5c[1];
  uVar6 = puRam020d5f5c[2];
  *(undefined4 *)(param_1 + 0x34) = *puRam020d5f5c;
  *(undefined4 *)(param_1 + 0x38) = uVar4;
  *(undefined4 *)(param_1 + 0x3c) = uVar6;
  uVar4 = puRam020d5f60[1];
  uVar6 = puRam020d5f60[2];
  *(undefined4 *)(param_1 + 0x40) = *puRam020d5f60;
  *(undefined4 *)(param_1 + 0x44) = uVar4;
  *(undefined4 *)(param_1 + 0x48) = uVar6;
  uVar7 = param_1 + 0x10cU & 3;
  uVar3 = *(uint *)(param_1 + 0x10cU & 0xfffffffc);
  uVar7 = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
  uVar3 = (uint)((ulonglong)uVar7 * 0x1e000) >> 0xc |
          (int)((ulonglong)uVar7 * 0x1e000 >> 0x20) * 0x100000;
  FX_DivAsync(0x1000,uVar3);
  *(uint *)(param_1 + 0x1c) = uVar7;
  *(uint *)(param_1 + 0x20) = uVar7;
  *(uint *)(param_1 + 0x24) = uVar7;
  *(uint *)(param_1 + 0x11c) = uVar3;
  *(uint *)(param_1 + 0x58) =
       (uint)((ulonglong)uVar7 * 0x1b000) >> 0xc |
       (int)((ulonglong)uVar7 * 0x1b000 >> 0x20) * 0x100000;
  if (-1 < *(short *)(param_1 + 100)) {
    uVar3 = param_1 + 0x58U & 3;
    uVar5 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
    func_020d5148((int)*(short *)(param_1 + 100),uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20);
  }
  uVar3 = param_1 + 0x98U & 3;
  uVar5 = *(uint *)(param_1 + 0x98U & 0xfffffffc);
  uVar3 = (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + 0x2c;
  uVar5 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
  *(uint *)(param_1 + 0x68) =
       (uint)((ulonglong)uVar7 * (ulonglong)uVar3) >> 0xc |
       (((int)uVar3 >> 0x1f) * uVar7 +
       uVar3 * ((int)uVar7 >> 0x1f) + (int)((ulonglong)uVar7 * (ulonglong)uVar3 >> 0x20)) * 0x100000
  ;
  uVar4 = FX_GetDivResult();
  *(undefined4 *)(param_1 + 0x118) = uVar4;
  return;
}

