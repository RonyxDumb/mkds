/* Decompiled C draft; module arm9; ROM address 0214c288. No matching claim. */
#include "types.h"
#include "deps/0214c288_func_0214c288.h"

void func_0214c288(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(uRam0214c2f0 & 0xfffffffc) >> (uRam0214c2f0 & 3) * 8 |
          *(uint *)(uRam0214c2f0 & 0xfffffffc) << (uRam0214c2f0 & 3) * -8 + 0x20;
  uVar1 = *(uint *)(uRam0214c2f4 & 0xfffffffc) >> (uRam0214c2f4 & 3) * 8 |
          *(uint *)(uRam0214c2f4 & 0xfffffffc) << (uRam0214c2f4 & 3) * -8 + 0x20;
  if (uVar2 != 0xffffffff) {
    func_0214c990(uVar2,param_1,uVar1,param_2,0,0);
    return;
  }
  Mem_CpuCopy32((undefined4 *)(uintptr_t)(param_1),(undefined4 *)(uintptr_t)(uVar1),param_2);
  return;
}

