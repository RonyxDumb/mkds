/* Decompiled C draft; module arm9; ROM address 020f73fc. No matching claim. */
#include "types.h"
#include "deps/020f73fc_func_020f73fc.h"

void func_020f73fc(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x180000) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x120) = uRam020f7428;
  uVar1 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  *(uint *)(param_1 + 0x74) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | uRam020f742c;
  return;
}

