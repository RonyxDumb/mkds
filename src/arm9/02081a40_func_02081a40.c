/* Decompiled C draft; module arm9; ROM address 02081a40. No matching claim. */
#include "types.h"
#include "deps/02081a40_func_02081a40.h"

void func_02081a40(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  
  iVar2 = iRam02081ab4;
  iVar7 = param_1 * 0xc +
          (*(uint *)(uRam02081ab0 & 0xfffffffc) >> (uRam02081ab0 & 3) * 8 |
          *(uint *)(uRam02081ab0 & 0xfffffffc) << (uRam02081ab0 & 3) * -8 + 0x20);
  uVar6 = 0;
  do {
    uVar3 = iVar7 + uVar6 * 4;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if (uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0) {
      func_0208b710();
    }
    iVar4 = GetDriverEntry(param_1);
    uVar3 = iVar2 + uVar6 * 4;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar5 = func_0208b7bc(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,iVar4 + 0x1d8);
    *(undefined4 *)(iVar7 + uVar6 * 4) = uVar5;
    uVar6 = uVar6 + 1 & 0xffff;
  } while (uVar6 < 3);
  return;
}

