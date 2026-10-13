/* Decompiled C draft; module arm9; ROM address 0210140c. No matching claim. */
#include "types.h"
#include "deps/0210140c_func_0210140c.h"

void func_0210140c(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = param_1 + 0x74U & 3;
  uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x8000000) == 0) {
    uVar3 = 2;
  }
  else {
    uVar3 = 1;
  }
  func_02101618(param_1,0,uVar3);
  uVar2 = param_1 + 0x74U & 3;
  uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x8000000) == 0) {
    return;
  }
  uVar2 = param_1 + 0x24cU & 3;
  uVar1 = *(uint *)(param_1 + 0x24cU & 0xfffffffc);
  if (uVar1 >> uVar2 * 8 != 0 || uVar1 << uVar2 * -8 + 0x20 != 0) {
    return;
  }
  uVar2 = param_1 + 0x144U & 3;
  uVar1 = *(uint *)(param_1 + 0x144U & 0xfffffffc);
  if (uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0) {
    uVar2 = param_1 + 0x264U & 3;
    uVar1 = *(uint *)(param_1 + 0x264U & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    if (uVar2 == 0xffffffff) {
      return;
    }
    if ((uVar2 != 0) && (uVar2 != 7)) {
      return;
    }
    *(undefined4 *)(param_1 + 0x144) = 1;
    *(undefined4 *)(param_1 + 0x264) = 0xffffffff;
    return;
  }
  return;
}

