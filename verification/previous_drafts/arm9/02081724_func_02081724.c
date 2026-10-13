/* Decompiled C draft; module arm9; ROM address 02081724. No matching claim. */
#include "types.h"
#include "deps/02081724_func_02081724.h"

void func_02081724(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = param_1 * 0x58 +
          (*(uint *)(uRam02081760 & 0xfffffffc) >> (uRam02081760 & 3) * 8 |
          *(uint *)(uRam02081760 & 0xfffffffc) << (uRam02081760 & 3) * -8 + 0x20);
  uVar2 = iVar4 + 0x2c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    func_0208b710();
  }
  uVar3 = func_0208b7bc(99,uRam02081764);
  *(undefined4 *)(iVar4 + 0x2c) = uVar3;
  return;
}

