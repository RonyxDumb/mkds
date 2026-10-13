/* Decompiled C draft; module arm9; ROM address 020f4f44. No matching claim. */
#include "types.h"
#include "deps/020f4f44_func_020f4f44.h"

void func_020f4f44(int param_1)

{
  uint uVar1;
  undefined1 auStack_c [4];
  uint uVar2;
  
  func_020f2df0(param_1,uRam020f4fc0,uRam020f4fc4,uRam020f4fc8,auStack_c);
  uVar2 = param_1 + 0x74U & 3;
  uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if ((uVar2 & 8) == 0) {
    return;
  }
  if ((uVar2 & 3) == 0) {
    func_02109060(param_1,0xda);
    func_020f6a6c(param_1,auStack_c);
    uVar2 = param_1 + 0x74U & 3;
    uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x180000) == 0) {
      *(undefined4 *)(param_1 + 0x120) = uRam020f4fcc;
    }
    return;
  }
  return;
}

