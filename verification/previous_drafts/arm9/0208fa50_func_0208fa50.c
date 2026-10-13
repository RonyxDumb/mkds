/* Decompiled C draft; module arm9; ROM address 0208fa50. No matching claim. */
#include "types.h"
#include "deps/0208fa50_func_0208fa50.h"

void func_0208fa50(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  *(undefined4 *)(param_1 + 0x10) = 1;
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
  if (iRam0208faf4 <= (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20)) {
    return;
  }
  uVar1 = param_2 + 0xb4U & 3;
  uVar3 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
  if ((uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0) &&
     (uVar1 = param_2 + 0xbcU & 3, uVar3 = *(uint *)(param_2 + 0xbcU & 0xfffffffc),
     iRam0208faf8 < (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20))) {
    func_0207c548(param_1,param_2);
    return;
  }
  func_0207c47c(param_1,param_2);
  return;
}

