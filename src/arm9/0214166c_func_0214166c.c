/* Decompiled C draft; module arm9; ROM address 0214166c. No matching claim. */
#include "types.h"
#include "deps/0214166c_func_0214166c.h"

bool func_0214166c(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  uVar5 = param_1 + 5U & 3;
  uVar4 = *(uint *)(param_1 + 5U & 0xfffffffc);
  uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0xff;
  if (uVar5 == 0) {
    uVar5 = param_2 + 5U & 3;
    uVar4 = *(uint *)(param_2 + 5U & 0xfffffffc);
    return ((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0xff) == 0;
  }
  uVar4 = param_2 + 5U & 3;
  uVar3 = *(uint *)(param_2 + 5U & 0xfffffffc);
  if (((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xff) != 0) {
    if (*(short *)(param_1 + 2) != *(short *)(param_2 + 2)) {
      return false;
    }
    uVar5 = param_1 + 4U & 3;
    uVar4 = *(uint *)(param_1 + 4U & 0xfffffffc);
    uVar3 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0xff;
    uVar5 = param_2 + 4U & 3;
    uVar4 = *(uint *)(param_2 + 4U & 0xfffffffc);
    iVar7 = 0;
    uVar4 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0xff;
    uVar5 = uVar3;
    if (uVar4 < uVar3) {
      uVar5 = uVar4;
    }
    if (uVar5 != 0) {
      do {
        uVar4 = param_1 + iVar7 + 5;
        uVar1 = uVar4 & 3;
        uVar6 = *(uint *)(uVar4 & 0xfffffffc);
        uVar4 = param_2 + iVar7 + 5;
        uVar2 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        if (((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) & 0xff) !=
            ((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) & 0xff)) {
          return false;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < (int)uVar5);
    }
    if (uVar5 == uVar3) {
      param_1 = param_2;
    }
    uVar5 = param_1 + 4U & 3;
    uVar4 = *(uint *)(param_1 + 4U & 0xfffffffc);
    if (iVar7 < (int)((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0xff)) {
      do {
        uVar5 = param_1 + iVar7 + 5;
        uVar4 = uVar5 & 3;
        uVar5 = *(uint *)(uVar5 & 0xfffffffc);
        if (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0xff) != 0) {
          return false;
        }
        iVar7 = iVar7 + 1;
        uVar5 = param_1 + 4U & 3;
        uVar4 = *(uint *)(param_1 + 4U & 0xfffffffc);
      } while (iVar7 < (int)((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0xff));
    }
    return true;
  }
  return uVar5 == 0;
}

