/* Decompiled C draft; module arm9; ROM address 020eec48. No matching claim. */
#include "types.h"
#include "deps/020eec48_func_020eec48.h"

void func_020eec48(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar3;
  
  iVar1 = iRam020eecd8;
  uVar3 = param_1 + 0x20U & 3;
  uVar2 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (param_2 + 1 < (int)uVar3) {
    iVar5 = 0;
    iVar6 = 0;
    do {
      uVar3 = param_1 + (uVar3 - 1) * 4 + 0x14;
      uVar2 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
      func_020efa60(param_1,0);
      iVar5 = iVar5 + iVar1;
      if (0 < iVar6) {
        iVar4 = uVar3 + 0x5c;
        VecFx32_AddScale1(iVar5,uVar3 + 0xf0,iVar4,(int *)(uintptr_t)(iVar4));
      }
      uVar3 = param_1 + 0x20U & 3;
      uVar2 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
      uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      iVar6 = iVar6 + 1;
    } while (param_2 + 1 < (int)uVar3);
  }
  func_020efa48(param_1,param_3);
  return;
}

