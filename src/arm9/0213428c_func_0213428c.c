/* Decompiled C draft; module arm9; ROM address 0213428c. No matching claim. */
#include "types.h"
#include "deps/0213428c_func_0213428c.h"

void func_0213428c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5,uint param_6)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  
  iVar1 = GetGammaFuncsRef();
  if ((param_6 & 0xc00000) == 0) {
    uVar2 = ChangeSomeAlphaFlags(0,0);
    param_6 = param_6 | uVar2 & 0xc00000;
  }
  uVar2 = param_6 & 0x7c000000;
  if (uVar2 < 0x10000001) {
    if (0xfffffff < uVar2) {
      uVar2 = iVar1 + 0xcU & 3;
      uVar3 = *(uint *)(iVar1 + 0xcU & 0xfffffffc);
      pcVar4 = (code *)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
      goto LAB_02134344;
    }
    if (uVar2 < 0x4000001) {
      if (uVar2 == 0x4000000) {
        uVar2 = iVar1 + 4U & 3;
        uVar3 = *(uint *)(iVar1 + 4U & 0xfffffffc);
        pcVar4 = (code *)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
        goto LAB_02134344;
      }
    }
    else if (uVar2 == 0x8000000) {
      uVar2 = iVar1 + 8U & 3;
      uVar3 = *(uint *)(iVar1 + 8U & 0xfffffffc);
      pcVar4 = (code *)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
      goto LAB_02134344;
    }
  }
  else if (uVar2 < 0x20000001) {
    if (uVar2 == 0x20000000) {
      uVar2 = iVar1 + 0x10U & 3;
      uVar3 = *(uint *)(iVar1 + 0x10U & 0xfffffffc);
      pcVar4 = (code *)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
      goto LAB_02134344;
    }
  }
  else if (uVar2 == 0x40000000) {
    uVar2 = iVar1 + 0x14U & 3;
    uVar3 = *(uint *)(iVar1 + 0x14U & 0xfffffffc);
    pcVar4 = (code *)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
    goto LAB_02134344;
  }
  pcVar4 = (code *)0x0;
LAB_02134344:
  if (pcVar4 == (code *)0x0) {
    func_02139e20(2);
  }
  (*pcVar4)(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}

