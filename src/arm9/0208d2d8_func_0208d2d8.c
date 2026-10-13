/* Decompiled C draft; module arm9; ROM address 0208d2d8. No matching claim. */
#include "types.h"
#include "deps/0208d2d8_func_0208d2d8.h"

void func_0208d2d8(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  do {
    uVar2 = param_1 + uVar4 * 4 + 0x10;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    func_0208b710(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
    uVar2 = param_1 + uVar4 * 4 + 0x18;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    func_0208b710(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
    iVar3 = param_1 + uVar4 * 4;
    *(undefined4 *)(iVar3 + 0x10) = 0;
    uVar4 = uVar4 + 1 & 0xffff;
    *(undefined4 *)(iVar3 + 0x18) = 0;
  } while (uVar4 < 2);
  return;
}

