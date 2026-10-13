/* Decompiled C draft; module arm9; ROM address 02142224. No matching claim. */
#include "types.h"
#include "deps/02142224_func_02142224.h"

undefined4 func_02142224(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = param_1 + 5;
  uVar5 = iVar4 + param_2;
  uVar3 = iVar4 + param_2 & 3;
  uVar2 = *(uint *)(iVar4 + param_2 & 0xfffffffc);
  uVar3 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0xff;
  if (5 < uVar3) {
    return 1;
  }
  if (4 < uVar3) {
    uVar3 = param_1 + 4U & 3;
    uVar2 = *(uint *)(param_1 + 4U & 0xfffffffc);
    do {
      uVar5 = uVar5 + 1;
      if (iVar4 + ((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0xff) <= uVar5) {
        uVar3 = param_1 + param_2 + 4;
        uVar5 = uVar3 & 3;
        uVar3 = *(uint *)(uVar3 & 0xfffffffc);
        if (((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) & 1) == 0) {
          uVar1 = 0xffffffff;
        }
        else {
          uVar1 = 1;
        }
        return uVar1;
      }
    } while (((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
              *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) & 0xff) == 0);
    return 1;
  }
  return 0xffffffff;
}

