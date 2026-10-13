/* Decompiled C draft; module arm9; ROM address 020ea5b0. No matching claim. */
#include "types.h"
#include "deps/020ea5b0_func_020ea5b0.h"

void func_020ea5b0(undefined4 param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int local_10;
  int local_c;
  int local_8;
  
  if (param_3 != 0) {
    local_10 = (int)(*(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
                    *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20) >> 4;
    uVar1 = param_3 + 4 & 3;
    uVar2 = *(uint *)(param_3 + 4 & 0xfffffffc);
    local_c = (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) >> 4;
    uVar1 = param_3 + 8 & 3;
    uVar2 = *(uint *)(param_3 + 8 & 0xfffffffc);
    local_8 = (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) >> 4;
    func_020e6854(param_1,(uint)(uintptr_t)(&local_10),1,param_2);
    return;
  }
  func_020e6854(param_1,0,0,param_2);
  return;
}

