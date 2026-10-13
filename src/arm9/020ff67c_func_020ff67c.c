/* Decompiled C draft; module arm9; ROM address 020ff67c. No matching claim. */
#include "types.h"
#include "deps/020ff67c_func_020ff67c.h"

void func_020ff67c(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  
  puVar2 = puRam020ff6d0;
  uVar4 = puRam020ff6d0[1];
  uVar5 = puRam020ff6d0[2];
  uVar6 = puRam020ff6d0[3];
  puVar7 = puRam020ff6d0 + 4;
  *(undefined4 *)(param_1 + 0x94) = *puRam020ff6d0;
  *(undefined4 *)(param_1 + 0x98) = uVar4;
  *(undefined4 *)(param_1 + 0x9c) = uVar5;
  *(undefined4 *)(param_1 + 0xa0) = uVar6;
  uVar4 = puVar2[5];
  uVar5 = puVar2[6];
  uVar6 = puVar2[7];
  *(undefined4 *)(param_1 + 0xa4) = *puVar7;
  *(undefined4 *)(param_1 + 0xa8) = uVar4;
  *(undefined4 *)(param_1 + 0xac) = uVar5;
  *(undefined4 *)(param_1 + 0xb0) = uVar6;
  uVar1 = (uint)(puVar2 + 8) & 3;
  uVar3 = *(uint *)((uint)(puVar2 + 8) & 0xfffffffc);
  *(uint *)(param_1 + 0xb4) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x140U & 3;
  uVar3 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
  func_021053e4(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  uVar1 = param_1 + 0x140U & 3;
  uVar3 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
  *(undefined2 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0xb0) = 2;
  uVar1 = param_1 + 0x140U & 3;
  uVar3 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
  func_021052f0(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,uRam020ff6d4,param_1);
  return;
}

