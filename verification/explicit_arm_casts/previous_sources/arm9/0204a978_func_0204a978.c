/* Decompiled C draft; module arm9; ROM address 0204a978. No matching claim. */
#include "types.h"
#include "deps/0204a978_func_0204a978.h"

void func_0204a978(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if (uVar2 != 0) {
    uVar1 = param_1 + 0xc & 3;
    uVar3 = *(uint *)(param_1 + 0xc & 0xfffffffc);
    if (uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0) {
      if (uVar2 != 0) {
        Mem_CpuFill8(uVar2,0,uRam0204a9e0);
      }
      *(undefined4 *)(param_1 + 0xc) = 1;
    }
    *(undefined4 *)
     (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
     *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined2 *)(param_1 + 4) = 0;
    *(undefined2 *)(param_1 + 6) = 0;
    *(undefined4 *)(param_1 + 8) = 1;
    return;
  }
  return;
}

