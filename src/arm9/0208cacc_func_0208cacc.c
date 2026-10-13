/* Decompiled C draft; module arm9; ROM address 0208cacc. No matching claim. */
#include "types.h"
#include "deps/0208cacc_func_0208cacc.h"

void func_0208cacc(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  
  if (param_2 != 0) {
    uVar6 = param_1 + 0x40U & 3;
    uVar2 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
    if (uVar2 >> uVar6 * 8 != 0 || uVar2 << uVar6 * -8 + 0x20 != 0) {
      uVar6 = 0;
      do {
        uVar2 = param_1 + uVar6 * 4 + 0x20;
        uVar3 = uVar2 & 3;
        uVar2 = *(uint *)(uVar2 & 0xfffffffc);
        func_0208b710(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
        uVar2 = param_1 + uVar6 * 4 + 0x28;
        uVar3 = uVar2 & 3;
        uVar2 = *(uint *)(uVar2 & 0xfffffffc);
        func_0208b710(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
        iVar5 = param_1 + uVar6 * 4;
        *(undefined4 *)(iVar5 + 0x20) = 0;
        uVar6 = uVar6 + 1 & 0xffff;
        *(undefined4 *)(iVar5 + 0x28) = 0;
      } while (uVar6 < 2);
    }
    uVar6 = 0;
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(undefined2 *)(param_1 + 0x48) = 0;
    uVar1 = uRam0208cb88;
    do {
      uVar2 = param_1 + 0x58U & 3;
      uVar3 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
      uVar4 = func_0208b7bc(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20,uVar1);
      *(undefined4 *)(param_1 + uVar6 * 4 + 0x20) = uVar4;
      uVar2 = param_1 + 0x5cU & 3;
      uVar3 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
      uVar4 = func_0208b7bc(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20,uVar1);
      iVar5 = uVar6 * 4;
      uVar6 = uVar6 + 1 & 0xffff;
      *(undefined4 *)(param_1 + iVar5 + 0x28) = uVar4;
    } while (uVar6 < 2);
    *(undefined4 *)(param_1 + 0x40) = 1;
    return;
  }
  return;
}

