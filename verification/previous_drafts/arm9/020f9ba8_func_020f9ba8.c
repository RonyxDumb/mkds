/* Decompiled C draft; module arm9; ROM address 020f9ba8. No matching claim. */
#include "types.h"
#include "deps/020f9ba8_func_020f9ba8.h"

void func_020f9ba8(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x11cU & 3;
  uVar2 = *(uint *)(param_1 + 0x11cU & 0xfffffffc);
  if ((int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) < 0x12d) {
    return;
  }
  uVar1 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x8000) != 0) {
    uVar1 = param_1 + 0x120U & 3;
    uVar2 = *(uint *)(param_1 + 0x120U & 0xfffffffc);
    if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == uRam020f9c04) {
      func_020f7658(param_1,1);
      return;
    }
    return;
  }
  return;
}

