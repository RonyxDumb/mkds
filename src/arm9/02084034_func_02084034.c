/* Decompiled C draft; module arm9; ROM address 02084034. No matching claim. */
#include "types.h"
#include "deps/02084034_func_02084034.h"

void func_02084034(int param_1,undefined4 param_2)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  iVar4 = func_02061818();
  if (iVar4 == 0) {
    GetGlobalHD5();
    uVar6 = *(uint *)((uint)piRam020840b0 & 0xfffffffc) >> ((uint)piRam020840b0 & 3) * 8 |
            *(uint *)((uint)piRam020840b0 & 0xfffffffc) << ((uint)piRam020840b0 & 3) * -8 + 0x20;
    if (uVar6 != 0) {
      uVar1 = uVar6 + 0x24 & 3;
      uVar5 = *(uint *)(uVar6 + 0x24 & 0xfffffffc);
      *(uint *)(uVar6 + 0x24) = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) & 0xfffffffe | 1;
    }
    uVar6 = iRam020840b4 + param_1 * 4;
    uVar1 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    iVar4 = func_0208b7bc(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20,uRam020840b8);
    *(undefined4 *)(iVar4 + 0x98) = 0;
    uVar3 = uRam020840bc;
    *(undefined4 *)(iVar4 + 0x94) = param_2;
    piVar2 = piRam020840b0;
    *(undefined4 *)(iVar4 + 0x90) = uVar3;
    *piVar2 = iVar4;
    return;
  }
  return;
}

