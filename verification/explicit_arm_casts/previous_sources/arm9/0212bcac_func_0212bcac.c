/* Decompiled C draft; module arm9; ROM address 0212bcac. No matching claim. */
#include "types.h"
#include "deps/0212bcac_func_0212bcac.h"

void func_0212bcac(int param_1,undefined1 param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 + 4U & 3;
  uVar1 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 != 0) {
    IntrusiveListWrapper_RemoveItem(uVar2,param_1);
    *(undefined4 *)(param_1 + 4) = 0;
  }
  IntrusiveListWrapper_RemoveItem(uRam0212bd0c,param_1);
  *(undefined1 *)(param_1 + 0x3d) = param_2;
  if (uVar2 != 0) {
    func_0212bf14(uVar2,param_1);
  }
  func_0212beb4(param_1);
  return;
}

