/* Decompiled C draft; module arm9; ROM address 0202506c. No matching claim. */
#include "types.h"
#include "deps/0202506c_func_0202506c.h"

void func_0202506c(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = param_2 + 8 & 3;
  uVar3 = *(uint *)(param_2 + 8 & 0xfffffffc);
  iVar2 = func_02109078(param_1,*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                                *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20,
                        *(undefined1 *)(param_2 + 4),
                        (int)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) << 4) >> 0x10);
  if (iVar2 != 0) {
    *(byte *)(iVar2 + 0x19) = *(byte *)(iVar2 + 0x19) | 0x80;
  }
  return;
}

