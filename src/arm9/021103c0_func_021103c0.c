/* Decompiled C draft; module arm9; ROM address 021103c0. No matching claim. */
#include "types.h"
#include "deps/021103c0_func_021103c0.h"

void func_021103c0(void)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar4 = FX_Div(0x7f000,0x1e000);
  *puRam02110468 = uVar4;
  uVar4 = FX_Div(0x7f000,0x1e000);
  *puRam0211046c = uVar4;
  uVar4 = FX_Div(0x7f000,0x5a000);
  uVar1 = uRam02110470 & 3;
  uVar5 = *(uint *)(uRam02110470 & 0xfffffffc);
  puRam0211046c[1] = uVar4;
  uVar4 = FX_Div((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) << 0xc,0x23000);
  *puRam02110474 = uVar4;
  uVar4 = FX_Div(0x7f000,0x19000);
  puVar2 = puRam0211047c;
  uVar6 = uRam02110470;
  uVar1 = (uint)puRam02110468 & 3;
  uVar7 = *(uint *)((uint)puRam02110468 & 0xfffffffc);
  *puRam02110478 = uVar4;
  puVar3 = puRam02110480;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  *puVar2 = uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20;
  puVar2[1] = 0x7f000;
  *puVar3 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  return;
}

