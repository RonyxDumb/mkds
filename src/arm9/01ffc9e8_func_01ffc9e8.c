/* Decompiled C draft; module arm9; ROM address 01ffc9e8. No matching claim. */
#include "types.h"
#include "deps/01ffc9e8_func_01ffc9e8.h"

void func_01ffc9e8(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = param_1 + 0x7cU & 3;
  uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) & 1) == 0) {
    iVar4 = 2;
  }
  else {
    iVar4 = 3;
  }
  uVar3 = iRam01ffca44 + param_2 * 4;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  iVar2 = GetAED0PlayerUnk(*(undefined2 *)(param_1 + 0x74));
  func_0210ddf4(iRam01ffca48 + iVar4 * 8,iVar2 + (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20),
                uRam01ffca4c,param_1,param_2);
  return;
}

