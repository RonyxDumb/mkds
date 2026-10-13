/* Decompiled C draft; module arm9; ROM address 0208cf5c. No matching claim. */
#include "types.h"
#include "deps/0208cf5c_func_0208cf5c.h"

void func_0208cf5c(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar3 = param_1 + 0x3cU & 3;
  uVar2 = *(uint *)(param_1 + 0x3cU & 0xfffffffc);
  if (uVar2 >> uVar3 * 8 != 0 || uVar2 << uVar3 * -8 + 0x20 != 0) {
    uVar3 = 0;
    do {
      uVar2 = param_1 + uVar3 * 4;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      uVar4 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
      uVar2 = uVar4 + 0x24;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      uVar3 = uVar3 + 1 & 0xffff;
      *(uint *)(uVar4 + 0x24) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 8;
    } while (uVar3 < 2);
  }
  uVar3 = param_1 + 0x40U & 3;
  uVar2 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  if (uVar2 >> uVar3 * 8 != 0 || uVar2 << uVar3 * -8 + 0x20 != 0) {
    uVar3 = 0;
    do {
      iVar5 = param_1 + uVar3 * 4;
      uVar2 = iVar5 + 0x20;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      uVar4 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
      uVar2 = uVar4 + 0x24;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      *(uint *)(uVar4 + 0x24) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 8;
      uVar2 = iVar5 + 0x28;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      uVar4 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
      uVar3 = uVar3 + 1 & 0xffff;
      uVar2 = uVar4 + 0x24;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      *(uint *)(uVar4 + 0x24) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 8;
    } while (uVar3 < 2);
  }
  uVar3 = param_1 + 0x44U & 3;
  uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  if (uVar2 >> uVar3 * 8 != 0 || uVar2 << uVar3 * -8 + 0x20 != 0) {
    uVar3 = 0;
    do {
      uVar2 = param_1 + uVar3 * 4 + 8;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      uVar4 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
      uVar2 = uVar4 + 0x24;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      uVar3 = uVar3 + 1 & 0xffff;
      *(uint *)(uVar4 + 0x24) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 8;
    } while (uVar3 < 2);
    return;
  }
  return;
}

