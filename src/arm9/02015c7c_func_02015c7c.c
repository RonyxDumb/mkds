/* Decompiled C draft; module arm9; ROM address 02015c7c. No matching claim. */
#include "types.h"
#include "deps/02015c7c_func_02015c7c.h"

void func_02015c7c(int param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar7;
  uint uVar6;
  
  uVar2 = NNS_G3dGetResDataByName(param_1 + 0x3c);
  uVar1 = uRam02015d60;
  uVar3 = param_3 + 0x10U & 3;
  uVar7 = *(uint *)(param_3 + 0x10U & 0xfffffffc);
  if (((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
       *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) & 0x1c000000) == 0x14000000) {
    uVar6 = param_1 + 0x18U & 3;
    uVar5 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  }
  else {
    uVar6 = param_1 + 8U & 3;
    uVar5 = *(uint *)(param_1 + 8U & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  }
  uVar6 = uVar6 & uRam02015d58;
  *(uint *)(param_3 + 0x10) = (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) & uRam02015d5c;
  uVar3 = param_3 + 0x10U & 3;
  uVar7 = *(uint *)(param_3 + 0x10U & 0xfffffffc);
  *(uint *)(param_3 + 0x10) =
       uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20 |
       (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
       *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + uVar6;
  uVar7 = uRam02015d64;
  uVar3 = uVar2 + 4 & 3;
  uVar6 = *(uint *)(uVar2 + 4 & 0xfffffffc);
  *(ushort *)(param_3 + 0x2c) =
       ((ushort)(uVar6 >> uVar3 * 8) | (ushort)(uVar6 << uVar3 * -8 + 0x20)) & (ushort)uVar1;
  uVar3 = uVar2 + 4 & 3;
  uVar6 = *(uint *)(uVar2 + 4 & 0xfffffffc);
  *(short *)(param_3 + 0x2e) =
       (short)(((uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) & uVar7) >> 0xb);
  uVar3 = uVar2 + 4 & 3;
  uVar2 = *(uint *)(uVar2 + 4 & 0xfffffffc);
  uVar2 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar3 = uVar2 & uVar1;
  uVar1 = uVar1 & uVar2 >> 0xb;
  if (uVar3 == *(ushort *)(param_3 + 0x2c)) {
    uVar4 = 0x1000;
  }
  else {
    uVar4 = FX_Div(uVar3 << 0xc,(uint)*(ushort *)(param_3 + 0x2c) << 0xc);
  }
  *(undefined4 *)(param_3 + 0x30) = uVar4;
  if (uVar1 == *(ushort *)(param_3 + 0x2e)) {
    uVar4 = 0x1000;
  }
  else {
    uVar4 = FX_Div(uVar1 << 0xc,(uint)*(ushort *)(param_3 + 0x2e) << 0xc);
  }
  *(undefined4 *)(param_3 + 0x34) = uVar4;
  return;
}

