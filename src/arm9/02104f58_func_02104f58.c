/* Decompiled C draft; module arm9; ROM address 02104f58. No matching claim. */
#include "types.h"
#include "deps/02104f58_func_02104f58.h"

void func_02104f58(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x138U & 3;
  uVar2 = *(uint *)(param_1 + 0x138U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    uVar1 = param_1 + 0x134U & 3;
    uVar2 = *(uint *)(param_1 + 0x134U & 0xfffffffc);
    *(undefined2 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0xb0) = 1;
  }
  uVar1 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x180000) == 0) {
    *(undefined4 *)(param_1 + 0x120) = uRam02104f80;
  }
  return;
}

