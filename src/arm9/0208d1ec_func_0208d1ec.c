/* Decompiled C draft; module arm9; ROM address 0208d1ec. No matching claim. */
#include "types.h"
#include "deps/0208d1ec_func_0208d1ec.h"

void func_0208d1ec(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = param_1 + 0x38U & 3;
  uVar3 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
  uVar4 = uVar3 >> uVar1 * 8;
  iVar2 = uVar3 << uVar1 * -8 + 0x20;
  if (uVar4 != 0 || iVar2 != 0) {
    if (uVar4 != 0 || iVar2 != 0) {
      uVar1 = param_1 + 0x74U & 3;
      uVar4 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
      (*(code *)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20))();
    }
    *(undefined4 *)(param_1 + 0x38) = 0;
    *(undefined2 *)(param_1 + 0x30) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(undefined2 *)(param_1 + 0x62) = 0;
    *(undefined4 *)(param_1 + 100) = 0;
    return;
  }
  return;
}

