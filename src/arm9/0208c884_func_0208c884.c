/* Decompiled C draft; module arm9; ROM address 0208c884. No matching claim. */
#include "types.h"
#include "deps/0208c884_func_0208c884.h"

void func_0208c884(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  
  if (param_2 != 0) {
    uVar6 = param_1 + 0x44U & 3;
    uVar4 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    if (uVar4 >> uVar6 * 8 != 0 || uVar4 << uVar6 * -8 + 0x20 != 0) {
      uVar6 = 0;
      do {
        uVar4 = param_1 + uVar6 * 4 + 8;
        uVar2 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        func_0208b710(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
        iVar1 = uVar6 * 4;
        uVar6 = uVar6 + 1 & 0xffff;
        *(undefined4 *)(param_1 + iVar1 + 8) = 0;
      } while (uVar6 < 2);
    }
    uVar6 = 0;
    *(undefined4 *)(param_1 + 0x44) = 0;
    *(undefined2 *)(param_1 + 0x4a) = 0;
    uVar3 = uRam0208c92c;
    do {
      uVar5 = func_0208b7bc(0x7e,uVar3);
      iVar1 = uVar6 * 4;
      uVar6 = uVar6 + 1 & 0xffff;
      *(undefined4 *)(param_1 + iVar1 + 8) = uVar5;
    } while (uVar6 < 2);
    *(undefined4 *)(param_1 + 0x44) = 1;
    return;
  }
  return;
}

