/* Decompiled C draft; module arm9; ROM address 01ffcc50. No matching claim. */
#include "types.h"
#include "deps/01ffcc50_func_01ffcc50.h"

void func_01ffcc50(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xa0) != 0) {
    func_020732d8();
    return;
  }
  func_01ffca50();
  func_01ffbe70(param_1);
  func_02067488(param_1);
  func_01ffbe04(param_1);
  func_01ffbd9c(param_1);
  func_01ffc6c0(param_1);
  func_01ff9d18(param_1);
  uVar1 = param_1 + 0x48U & 3;
  uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x10000) != 0) {
    func_020708a4(param_1);
    return;
  }
  func_01ffb130(param_1);
  return;
}

