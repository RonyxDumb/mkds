/* Decompiled C draft; module arm9; ROM address 0212c078. No matching claim. */
#include "types.h"
#include "deps/0212c078_func_0212c078.h"

void func_0212c078(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = param_1 + 4U & 3;
  uVar3 = *(uint *)(param_1 + 4U & 0xfffffffc);
  func_02020ddc(*(undefined1 *)(param_1 + 0x3c));
  uVar2 = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + 0x1c;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar3 * 8 != 0 || uVar2 << uVar3 * -8 + 0x20 != 0) {
    func_02020c60(*(undefined1 *)(param_1 + 0x3c),uRam0212c0d0);
  }
  func_0212bf70(param_1);
  uVar1 = func_02021114();
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  *(undefined1 *)(param_1 + 0x2f) = 1;
  *(undefined1 *)(param_1 + 0x2c) = 1;
  return;
}

