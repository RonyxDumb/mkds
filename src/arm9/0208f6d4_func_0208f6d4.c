/* Decompiled C draft; module arm9; ROM address 0208f6d4. No matching claim. */
#include "types.h"
#include "deps/0208f6d4_func_0208f6d4.h"

void func_0208f6d4(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = func_0207bfac();
  if (iVar2 == 0) {
    return;
  }
  uVar1 = param_2 + 0xb0U & 3;
  uVar3 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
  if (uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0) {
    return;
  }
  uVar1 = param_2 + 0xb8U & 3;
  uVar3 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
  if (iRam0208f750 <= (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20)) {
    return;
  }
  uVar1 = param_2 + 0xb4U & 3;
  uVar3 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
  if (uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0) {
    func_0207c614(param_1,param_2);
    return;
  }
  return;
}

