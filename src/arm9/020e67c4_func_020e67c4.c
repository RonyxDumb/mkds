/* Decompiled C draft; module arm9; ROM address 020e67c4. No matching claim. */
#include "types.h"
#include "deps/020e67c4_func_020e67c4.h"

void func_020e67c4(undefined4 param_1,int param_2,uint param_3,undefined4 param_4,undefined2 param_5
                  )

{
  uint uVar1;
  uint uVar2;
  undefined4 local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  local_28 = 0x1e;
  func_01ff9048(0x14,(undefined4)(uintptr_t)(&local_28),1);
  func_01ff9048(0x19,param_2,0xc);
  if (param_3 != 0) {
    uVar1 = param_3 + 8 & 3;
    uVar2 = *(uint *)(param_3 + 8 & 0xfffffffc);
    local_1c = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    uVar1 = param_3 + 4 & 3;
    uVar2 = *(uint *)(param_3 + 4 & 0xfffffffc);
    local_20 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    local_24 = *(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
               *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20;
    func_01ff9048(0x1b,(undefined4)(uintptr_t)(&local_24),3);
  }
  func_020e6854(param_1,param_2 + 0x24,param_4,param_5);
  return;
}

