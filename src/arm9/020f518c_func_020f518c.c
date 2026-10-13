/* Decompiled C draft; module arm9; ROM address 020f518c. No matching claim. */
#include "types.h"
#include "deps/020f518c_func_020f518c.h"

void func_020f518c(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined1 auStack_c [4];
  
  uVar2 = param_1 + 0x130U & 3;
  uVar1 = *(uint *)(param_1 + 0x130U & 0xfffffffc);
  if (uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0) {
    func_020f2df0(param_1,uRam020f5238,uRam020f523c,0,auStack_c);
  }
  else {
    func_020f2df0(param_1,0x1ec,uRam020f5234,0,auStack_c);
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
      func_020f6a6c(param_1,(undefined4)(uintptr_t)(auStack_c));
      return;
    }
    return;
  }
  return;
}

