/* Decompiled C draft; module arm9; ROM address 02024fe8. No matching claim. */
#include "types.h"
#include "deps/02024fe8_func_02024fe8.h"

void func_02024fe8(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = param_1 + 0x3e0U & 3;
  uVar3 = *(uint *)(param_1 + 0x3e0U & 0xfffffffc);
  uVar5 = param_1 + 0x3e4U & 3;
  uVar4 = *(uint *)(param_1 + 0x3e4U & 0xfffffffc);
  uVar2 = func_0210bb74(3,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,
                        uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
  uVar1 = param_2 + 8U & 3;
  uVar5 = *(uint *)(param_2 + 8U & 0xfffffffc);
  func_02109078(param_1,uVar2,*(undefined1 *)(param_2 + 4),
                (int)((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) << 4) >> 0x10);
  return;
}

