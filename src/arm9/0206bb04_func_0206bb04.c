/* Decompiled C draft; module arm9; ROM address 0206bb04. No matching claim. */
#include "types.h"
#include "deps/0206bb04_func_0206bb04.h"

void func_0206bb04(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = param_1 + 0x4cU & 3;
  uVar3 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0x20) != 0) {
    return;
  }
  uVar2 = param_1 + 0x48U & 3;
  uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(param_1 + 0x48) = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20 | 0x44000;
  *(undefined2 *)(param_1 + 0x23a) = 10;
  *(undefined4 *)(param_1 + 0x180) = 0;
  uVar2 = param_1 + 0x4cU & 3;
  uVar3 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  *(uint *)(param_1 + 0x4c) = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0xffffffcf;
  uVar2 = param_1 + 0x48U & 3;
  uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(param_1 + 0x48) = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0xfffdffff;
  DriverContext_UpdateCharacterAnimation(param_1,0,1);
  uVar2 = param_1 + 0x44U & 3;
  uVar3 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  *(uint *)(param_1 + 0x44) = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20 | 0x80000000;
  uVar2 = param_1 + 0x7cU & 3;
  uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 2) == 0) {
    return;
  }
  uVar3 = *(uint *)(uRam0206bbb0 & 0xfffffffc) >> (uRam0206bbb0 & 3) * 8 |
          *(uint *)(uRam0206bbb0 & 0xfffffffc) << (uRam0206bbb0 & 3) * -8 + 0x20;
  uVar2 = uVar3 + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) != 2) {
    return;
  }
  uVar3 = uVar3 + 0x18;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if (uVar3 >> uVar2 * 8 == 0 && uVar3 << uVar2 * -8 + 0x20 == 0) {
    uVar2 = param_1 + 0x310U & 3;
    uVar3 = *(uint *)(param_1 + 0x310U & 0xfffffffc);
    func_02088c7c(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
    return;
  }
  return;
}

