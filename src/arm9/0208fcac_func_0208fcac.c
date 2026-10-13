/* Decompiled C draft; module arm9; ROM address 0208fcac. No matching claim. */
#include "types.h"
#include "deps/0208fcac_func_0208fcac.h"

void func_0208fcac(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_2 + 0xb0U & 3;
  uVar2 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
    return;
  }
  uVar1 = param_2 + 0xb8U & 3;
  uVar2 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
  if ((int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) < iRam0208fd1c) {
    uVar1 = param_2 + 0xb4U & 3;
    uVar2 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    if ((uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) &&
       (uVar1 = param_2 + 0xbcU & 3, uVar2 = *(uint *)(param_2 + 0xbcU & 0xfffffffc),
       iRam0208fd20 < (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20))) {
      func_0207c548();
      return;
    }
    func_0207c47c();
    return;
  }
  return;
}

