/* Decompiled C draft; module arm9; ROM address 01ffc5a0. No matching claim. */
#include "types.h"
#include "deps/01ffc5a0_func_01ffc5a0.h"

void func_01ffc5a0(int param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = uRam01ffc670;
  uVar2 = param_1 + 0x48U & 3;
  uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(param_1 + 0x48) = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & uRam01ffc66c;
  uVar2 = param_1 + 0x44U & 3;
  uVar3 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  *(uint *)(param_1 + 0x44) = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & uVar4;
  uVar2 = param_1 + 0x78U & 3;
  uVar4 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
  puVar1 = (uint *)(param_1 + 0x48);
  if ((*(ushort *)(iRam01ffc674 + (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) * 0x5c) & 1) !=
      0) {
    *puVar1 = *(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
              *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20 | 2;
  }
  uVar2 = param_1 + 0x78U & 3;
  uVar4 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
  if ((*(ushort *)(iRam01ffc674 + (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) * 0x5c) & 2) !=
      0) {
    uVar2 = param_1 + 0x48U & 3;
    uVar4 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    puVar1 = (uint *)(param_1 + 0x48);
    *(uint *)(param_1 + 0x48) = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20 | 4;
    uVar2 = param_1 + 0x48U & 3;
    uVar4 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    uVar2 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
    if (((uVar2 & 2) != 0) && ((uVar2 & uRam01ffc678) == 0)) {
      *puVar1 = (*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) & 0xfffffff9
      ;
      *puVar1 = *(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20 | 0x80;
    }
  }
  uVar2 = param_1 + 0x2a8U & 3;
  uVar4 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc);
  if ((int)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) < 0) {
    uVar2 = param_1 + 0x44U & 3;
    uVar4 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    *(uint *)(param_1 + 0x44) = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20 | 0x100;
  }
  return;
}

