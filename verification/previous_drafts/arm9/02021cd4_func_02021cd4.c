/* Decompiled C draft; module arm9; ROM address 02021cd4. No matching claim. */
#include "types.h"
#include "deps/02021cd4_func_02021cd4.h"

void func_02021cd4(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar5;
  uint uVar4;
  
  Sound_LockMutex();
  iVar5 = param_1 + param_2 * 8;
  uVar4 = iVar5 + 0x18U & 3;
  uVar3 = *(uint *)(iVar5 + 0x18U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if (uVar4 != 0) {
    if (param_3 == uVar4) {
      Sound_UnlockMutex();
      return;
    }
    uVar3 = uVar4 + 0x18 & 3;
    uVar1 = *(uint *)(uVar4 + 0x18 & 0xfffffffc);
    uVar3 = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20;
    uVar1 = param_1 + 0x18 + param_2 * 8;
    if (uVar1 == uVar3) {
      uVar3 = iVar5 + 0x1cU & 3;
      uVar1 = *(uint *)(iVar5 + 0x1cU & 0xfffffffc);
      *(uint *)(uVar4 + 0x18) = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20;
      uVar4 = iVar5 + 0x18U & 3;
      uVar3 = *(uint *)(iVar5 + 0x18U & 0xfffffffc);
      DC_SomeClean(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20,0x3c);
    }
    else {
      do {
        uVar4 = uVar3;
        if (uVar4 == 0) break;
        uVar3 = uVar4 + 4 & 3;
        uVar2 = *(uint *)(uVar4 + 4 & 0xfffffffc);
        uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      } while (uVar1 != uVar3);
      uVar3 = param_1 + param_2 * 8 + 0x1c;
      uVar1 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      *(uint *)(uVar4 + 4) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
      DC_SomeClean(uVar4,8);
    }
  }
  uVar4 = param_3 + 0x18 & 3;
  uVar3 = *(uint *)(param_3 + 0x18 & 0xfffffffc);
  *(int *)(param_3 + 0x18) = param_1 + 0x18 + param_2 * 8;
  iVar5 = param_1 + param_2 * 8;
  *(uint *)(iVar5 + 0x1c) = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  *(uint *)(iVar5 + 0x18) = param_3;
  Sound_UnlockMutex();
  DC_SomeClean(param_1,0x3c);
  DC_SomeClean(param_3,0x3c);
  return;
}

