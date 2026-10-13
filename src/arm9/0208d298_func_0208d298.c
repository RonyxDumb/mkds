/* Decompiled C draft; module arm9; ROM address 0208d298. No matching claim. */
#include "types.h"
#include "deps/0208d298_func_0208d298.h"

void func_0208d298(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  do {
    uVar3 = param_1 + uVar4 * 4 + 0x10;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    func_0208b710(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
    iVar1 = uVar4 * 4;
    uVar4 = uVar4 + 1 & 0xffff;
    *(undefined4 *)(param_1 + iVar1 + 0x10) = 0;
  } while (uVar4 < 2);
  return;
}

