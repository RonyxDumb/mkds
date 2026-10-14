/* Decompiled C draft; module arm9; ROM address 0214c214. No matching claim. */
#include "types.h"
#include "deps/0214c214_func_0214c214.h"

void func_0214c214(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(uRam0214c284 & 0xfffffffc) >> (uRam0214c284 & 3) * 8 |
          *(uint *)(uRam0214c284 & 0xfffffffc) << (uRam0214c284 & 3) * -8 + 0x20;
  iVar1 = (*(uint *)(uRam0214c280 & 0xfffffffc) >> (uRam0214c280 & 3) * 8 |
          *(uint *)(uRam0214c280 & 0xfffffffc) << (uRam0214c280 & 3) * -8 + 0x20) + 0x20000;
  if (uVar2 != 0xffffffff) {
    func_0214c990(uVar2,param_1,iVar1,param_2,0,0);
    return;
  }
  Mem_CpuCopy32((undefined4 *)(uintptr_t)(param_1),(undefined4 *)(uintptr_t)(iVar1),param_2);
  return;
}

