/* Decompiled C draft; module arm9; ROM address 0214c544. No matching claim. */
#include "types.h"
#include "deps/0214c544_func_0214c544.h"

void func_0214c544(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(uRam0214c698 & 0xfffffffc) >> (uRam0214c698 & 3) * 8 |
          *(uint *)(uRam0214c698 & 0xfffffffc) << (uRam0214c698 & 3) * -8 + 0x20;
  if (uVar4 == 0) {
    iVar2 = (*(uint *)(uRam0214c69c & 0xfffffffc) >> (uRam0214c69c & 3) * 8 |
            *(uint *)(uRam0214c69c & 0xfffffffc) << (uRam0214c69c & 3) * -8 + 0x20) + param_2;
  }
  else {
    uVar3 = *(uint *)(uRam0214c6a0 & 0xfffffffc) >> (uRam0214c6a0 & 3) * 8 |
            *(uint *)(uRam0214c6a0 & 0xfffffffc) << (uRam0214c6a0 & 3) * -8 + 0x20;
    if (param_2 + param_3 < uVar3) {
      iVar2 = (*(uint *)(uRam0214c69c & 0xfffffffc) >> (uRam0214c69c & 3) * 8 |
              *(uint *)(uRam0214c69c & 0xfffffffc) << (uRam0214c69c & 3) * -8 + 0x20) + param_2;
    }
    else {
      if (param_2 < uVar3) {
        uVar1 = *(uint *)(uRam0214c6a4 & 0xfffffffc) >> (uRam0214c6a4 & 3) * 8 |
                *(uint *)(uRam0214c6a4 & 0xfffffffc) << (uRam0214c6a4 & 3) * -8 + 0x20;
        uVar3 = uVar3 - param_2;
        iVar2 = (*(uint *)(uRam0214c69c & 0xfffffffc) >> (uRam0214c69c & 3) * 8 |
                *(uint *)(uRam0214c69c & 0xfffffffc) << (uRam0214c69c & 3) * -8 + 0x20) + param_2;
        if ((uVar1 == 0xffffffff) || (uVar3 < 0x31)) {
          Mem_CpuCopy32((undefined4 *)(uintptr_t)(param_1),(undefined4 *)(uintptr_t)(iVar2),uVar3);
        }
        else {
          MI_DmaCopy32(uVar1,param_1,iVar2,uVar3);
        }
        uVar1 = *(uint *)(uRam0214c6a4 & 0xfffffffc) >> (uRam0214c6a4 & 3) * 8 |
                *(uint *)(uRam0214c6a4 & 0xfffffffc) << (uRam0214c6a4 & 3) * -8 + 0x20;
        if (uVar1 == 0xffffffff) {
          Mem_CpuCopy32((undefined4 *)(uintptr_t)(param_1 + uVar3),(undefined4 *)(uintptr_t)(uVar4),param_3 - uVar3);
          return;
        }
        func_0214c990(uVar1,param_1 + uVar3,uVar4,param_3 - uVar3,0,0);
        return;
      }
      iVar2 = (uVar4 + param_2) - uVar3;
    }
  }
  uVar4 = *(uint *)(uRam0214c6a4 & 0xfffffffc) >> (uRam0214c6a4 & 3) * 8 |
          *(uint *)(uRam0214c6a4 & 0xfffffffc) << (uRam0214c6a4 & 3) * -8 + 0x20;
  if (uVar4 == 0xffffffff) {
    Mem_CpuCopy32((undefined4 *)(uintptr_t)(param_1),(undefined4 *)(uintptr_t)(iVar2),param_3);
    return;
  }
  func_0214c990(uVar4,param_1,iVar2,param_3,0,0);
  return;
}

