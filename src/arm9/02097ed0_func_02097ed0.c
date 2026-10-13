/* Decompiled C draft; module arm9; ROM address 02097ed0. No matching claim. */
#include "types.h"
#include "deps/02097ed0_func_02097ed0.h"

bool func_02097ed0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  *(undefined4 *)(param_1 + 0xa0) = 0;
  uVar1 = param_1 + 0xa4U & 3;
  uVar2 = *(uint *)(param_1 + 0xa4U & 0xfffffffc);
  iVar3 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) * 0xc;
  uVar1 = param_1 + 0xec0U & 3;
  uVar2 = *(uint *)(param_1 + 0xec0U & 0xfffffffc);
  iVar3 = func_020eafc4(param_2,param_1 + 4,
                        (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) * 0x30 + param_1 + 0xa8,
                        iRam020980cc + iVar3,iRam020980c8 + iVar3,param_3,0);
  if (iVar3 == 0) {
    uVar1 = param_1 + 0xa4U & 3;
    uVar2 = *(uint *)(param_1 + 0xa4U & 0xfffffffc);
    iVar3 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) * 0xc;
    uVar1 = param_1 + 0xec0U & 3;
    uVar2 = *(uint *)(param_1 + 0xec0U & 0xfffffffc);
    iVar3 = func_020eafc4(param_2,param_1 + 4,
                          (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) * 0x30 + param_1 + 0xa8,
                          iRam020980dc + iVar3,iRam020980d8 + iVar3,param_3,0);
    if (iVar3 == 0) {
      uVar1 = param_1 + 0xec0U & 3;
      uVar2 = *(uint *)(param_1 + 0xec0U & 0xfffffffc);
      iVar3 = func_020ead80(param_2,param_1 + 4,
                            (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) * 0x30 +
                            param_1 + 0xa8,0x32000,0x3c000,0,param_3,(uint *)(uintptr_t)(param_4));
    }
    else {
      uVar1 = param_1 + 0xa4U & 3;
      uVar2 = *(uint *)(param_1 + 0xa4U & 0xfffffffc);
      iVar3 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) * 0xc;
      uVar1 = param_1 + 0xec0U & 3;
      uVar2 = *(uint *)(param_1 + 0xec0U & 0xfffffffc);
      iVar3 = func_020eafc4(param_2,param_1 + 4,
                            (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) * 0x30 +
                            param_1 + iRam020980e4,iRam020980e8 + iVar3,iRam020980e0 + iVar3,param_3
                            ,(uint *)(uintptr_t)(param_4));
      if ((iVar3 == 4) ||
         (uVar1 = param_1 + 0xeccU & 3, uVar2 = *(uint *)(param_1 + 0xeccU & 0xfffffffc),
         uVar1 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20, uVar1 == 3)) {
        *(undefined4 *)(param_1 + 0xa0) = 0xffffffff;
      }
      else if (uVar1 == 2) {
        *(undefined4 *)(param_1 + 0xa0) = 1;
      }
    }
  }
  else {
    uVar1 = param_1 + 0xa4U & 3;
    uVar2 = *(uint *)(param_1 + 0xa4U & 0xfffffffc);
    iVar3 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) * 0xc;
    uVar1 = param_1 + 0xec0U & 3;
    uVar2 = *(uint *)(param_1 + 0xec0U & 0xfffffffc);
    iVar3 = func_020eafc4(param_2,param_1 + 4,
                          (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) * 0x30 + param_1 + 0xa8,
                          iRam020980d4 + iVar3,iRam020980d0 + iVar3,param_3,(uint *)(uintptr_t)(param_4));
    if ((iVar3 == 4) ||
       (uVar1 = param_1 + 0xeccU & 3, uVar2 = *(uint *)(param_1 + 0xeccU & 0xfffffffc),
       uVar1 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20, uVar1 == 2)) {
      *(undefined4 *)(param_1 + 0xa0) = 1;
    }
    else if (uVar1 == 3) {
      *(undefined4 *)(param_1 + 0xa0) = 0xffffffff;
    }
  }
  return iVar3 != 0;
}

