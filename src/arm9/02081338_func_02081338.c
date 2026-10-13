/* Decompiled C draft; module arm9; ROM address 02081338. No matching claim. */
#include "types.h"
#include "deps/02081338_func_02081338.h"

void func_02081338(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = param_1 * 0x58 +
          (*(uint *)(uRam02081370 & 0xfffffffc) >> (uRam02081370 & 3) * 8 |
          *(uint *)(uRam02081370 & 0xfffffffc) << (uRam02081370 & 3) * -8 + 0x20);
  uVar2 = iVar3 + 0x28;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    func_0208b710();
    *(undefined4 *)(iVar3 + 0x28) = 0;
    return;
  }
  return;
}

