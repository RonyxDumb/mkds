/* Decompiled C draft; module arm9; ROM address 0210e03c. No matching claim. */
#include "types.h"
#include "deps/0210e03c_func_0210e03c.h"

void func_0210e03c(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < (int)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
               *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20)) {
    do {
      uVar1 = param_1 + 4 & 3;
      uVar2 = *(uint *)(param_1 + 4 & 0xfffffffc);
      *(undefined4 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + iVar3 * 0x10) = 0xffffffff
      ;
      uVar1 = param_1 + 4 & 3;
      uVar2 = *(uint *)(param_1 + 4 & 0xfffffffc);
      *(undefined4 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + iVar3 * 0x10 + 4) = 0;
      uVar1 = param_1 + 4 & 3;
      uVar2 = *(uint *)(param_1 + 4 & 0xfffffffc);
      *(undefined4 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + iVar3 * 0x10 + 8) = 0;
      uVar1 = param_1 + 4 & 3;
      uVar2 = *(uint *)(param_1 + 4 & 0xfffffffc);
      *(undefined4 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + iVar3 * 0x10 + 0xc) = 0;
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20));
    return;
  }
  return;
}

