/* Decompiled C draft; module arm9; ROM address 0212f058. No matching claim. */
#include "types.h"
#include "deps/0212f058_func_0212f058.h"

void func_0212f058(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  uVar1 = param_1 + 0x14cU & 3;
  uVar2 = *(uint *)(param_1 + 0x14cU & 0xfffffffc);
  puVar3 = (undefined4 *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  if (puVar3 != (undefined4 *)0x0) {
    *puVar3 = 0;
    *(undefined4 *)(param_1 + 0x14c) = 0;
  }
  uVar1 = param_1 + 0x110U & 3;
  uVar2 = *(uint *)(param_1 + 0x110U & 0xfffffffc);
  *(uint *)(param_1 + 0x110) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xfffffffe;
  uVar1 = param_1 + 0x110U & 3;
  uVar2 = *(uint *)(param_1 + 0x110U & 0xfffffffc);
  *(uint *)(param_1 + 0x110) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xfffffffb;
  uVar1 = param_1 + 0x110U & 3;
  uVar2 = *(uint *)(param_1 + 0x110U & 0xfffffffc);
  *(uint *)(param_1 + 0x110) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xfffffffd;
  return;
}

