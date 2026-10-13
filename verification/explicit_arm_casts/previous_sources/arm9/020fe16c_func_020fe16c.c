/* Decompiled C draft; module arm9; ROM address 020fe16c. No matching claim. */
#include "types.h"
#include "deps/020fe16c_func_020fe16c.h"

void func_020fe16c(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined1 auStack_c [4];
  
  uVar2 = param_1 + 0x130U & 3;
  uVar1 = *(uint *)(param_1 + 0x130U & 0xfffffffc);
  if (uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0) {
    uVar2 = param_1 + 0x134U & 3;
    uVar1 = *(uint *)(param_1 + 0x134U & 0xfffffffc);
    func_020f2df0(param_1,uRam020fe258,uRam020fe25c,uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20,
                  auStack_c);
  }
  else {
    func_020f2df0(param_1,uRam020fe24c,uRam020fe250,uRam020fe254,auStack_c);
  }
  uVar2 = param_1 + 0x74U & 3;
  uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x10) != 0) {
    func_020f91fc(param_1,0xe5);
  }
  uVar2 = param_1 + 0x74U & 3;
  uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if ((uVar2 & 8) != 0) {
    if ((uVar2 & 3) == 0) {
      uVar2 = param_1 + 0x130U & 3;
      uVar1 = *(uint *)(param_1 + 0x130U & 0xfffffffc);
      if (uVar1 >> uVar2 * 8 != 0 || uVar1 << uVar2 * -8 + 0x20 != 0) {
        uVar2 = param_1 + 0x60U & 3;
        uVar1 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
        *(uint *)(param_1 + 0x60) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) << 1;
      }
      func_02109060(param_1,0xda);
      func_020f6a6c(param_1,auStack_c);
      uVar2 = param_1 + 0x74U & 3;
      uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
      if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x180000) == 0) {
        *(undefined4 *)(param_1 + 0x120) = uRam020fe260;
      }
      *(undefined2 *)(param_1 + 0x194) = 1;
      *(undefined2 *)(param_1 + 0x196) = 1;
      return;
    }
    return;
  }
  return;
}

