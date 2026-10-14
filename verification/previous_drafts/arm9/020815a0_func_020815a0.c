/* Decompiled C draft; module arm9; ROM address 020815a0. No matching claim. */
#include "types.h"
#include "deps/020815a0_func_020815a0.h"

void func_020815a0(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = param_1 * 0x58 +
          (*(uint *)(uRam020815d8 & 0xfffffffc) >> (uRam020815d8 & 3) * 8 |
          *(uint *)(uRam020815d8 & 0xfffffffc) << (uRam020815d8 & 3) * -8 + 0x20);
  uVar2 = iVar3 + 0x2c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    func_0208b710();
    *(undefined4 *)(iVar3 + 0x2c) = 0;
    return;
  }
  return;
}

