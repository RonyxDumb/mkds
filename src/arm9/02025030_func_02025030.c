/* Decompiled C draft; module arm9; ROM address 02025030. No matching claim. */
#include "types.h"
#include "deps/02025030_func_02025030.h"

void func_02025030(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = param_2 + 8U & 3;
  uVar5 = *(uint *)(param_2 + 8U & 0xfffffffc);
  uVar2 = param_2 + 0x58U & 3;
  uVar4 = *(uint *)(param_2 + 0x58U & 0xfffffffc);
  iVar3 = func_02109078(param_1,uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20,
                        *(undefined1 *)(param_2 + 4),
                        (int)((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) << 4) >> 0x10);
  if (iVar3 != 0) {
    *(byte *)(iVar3 + 0x19) = *(byte *)(iVar3 + 0x19) | 0x80;
  }
  return;
}

