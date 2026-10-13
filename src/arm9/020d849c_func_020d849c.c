/* Decompiled C draft; module arm9; ROM address 020d849c. No matching claim. */
#include "types.h"
#include "deps/020d849c_func_020d849c.h"

bool func_020d849c(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = param_1 + 0x5cU & 3;
  uVar4 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
  uVar2 = param_1 + 0x58U & 3;
  uVar3 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
  *(uint *)(param_1 + 0x5c) =
       (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) +
       (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  uVar1 = param_1 + 0x5cU & 3;
  uVar2 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
  return 0xffffff < (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
}

