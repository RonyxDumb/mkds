/* Decompiled C draft; module arm9; ROM address 020849f8. No matching claim. */
#include "types.h"
#include "deps/020849f8_func_020849f8.h"

void func_020849f8(int param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  
  local_20 = 0x1e;
  func_01ff9048(0x14,(undefined4)(uintptr_t)(&local_20),1);
  func_01ff9048(0x19,param_2,0xc);
  if (param_3 != 0) {
    uVar1 = param_3 + 8 & 3;
    uVar2 = *(uint *)(param_3 + 8 & 0xfffffffc);
    local_14 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    uVar1 = param_3 + 4 & 3;
    uVar2 = *(uint *)(param_3 + 4 & 0xfffffffc);
    local_18 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    local_1c = *(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
               *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20;
    func_01ff9048(0x1b,(undefined4)(uintptr_t)(&local_1c),3);
  }
  uVar1 = param_1 + 0x58U & 3;
  uVar2 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
  uVar1 = iRam02084a84 + (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) * 4;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  (*(code *)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20))(param_1);
  return;
}

