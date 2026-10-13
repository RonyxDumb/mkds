/* Decompiled C draft; module arm9; ROM address 020e6ab8. No matching claim. */
#include "types.h"
#include "deps/020e6ab8_BillboardModel_SomeFn.h"

void BillboardModel_SomeFn(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = uRam020e6b10;
  uVar1 = param_1 + 0x10U & 3;
  uVar3 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  *(uint *)(param_1 + 0x10) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & uRam020e6b0c;
  uVar1 = param_1 + 0x10U & 3;
  uVar3 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  *(uint *)(param_1 + 0x10) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20 | uVar2;
  uVar1 = param_1 + 0x14U & 3;
  uVar2 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  *(uint *)(param_1 + 0x14) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xc0ffffff;
  uVar1 = param_1 + 0x14U & 3;
  uVar2 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  *(uint *)(param_1 + 0x14) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 0x3f000000;
  uVar1 = param_1 + 0x14U & 3;
  uVar2 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  *(uint *)(param_1 + 0x14) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xfffffff0;
  uVar1 = param_1 + 0x14U & 3;
  uVar2 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  *(uint *)(param_1 + 0x14) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 2;
  return;
}

