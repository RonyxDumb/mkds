/* Decompiled C draft; module arm9; ROM address 02003d8c. No matching claim. */
#include "types.h"
#include "deps/02003d8c_func_02003d8c.h"

uint func_02003d8c(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = param_1 + 0x1cU & 3;
  uVar2 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  uVar4 = 0;
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 2) != 0) {
    iVar3 = Fs_Archive_Suspend(param_1);
    uVar1 = param_1 + 0x1cU & 3;
    uVar2 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 4) != 0) {
      uVar1 = param_1 + 0x1cU & 3;
      uVar2 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
      *(uint *)(param_1 + 0x1c) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xfffffffb;
      uVar1 = param_1 + 0x44U & 3;
      uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
      uVar4 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
      *(undefined4 *)(param_1 + 0x44) = 0;
      uVar1 = param_1 + 0x3cU & 3;
      uVar2 = *(uint *)(param_1 + 0x3cU & 0xfffffffc);
      *(uint *)(param_1 + 0x2c) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
      uVar1 = param_1 + 0x40U & 3;
      uVar2 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
      *(uint *)(param_1 + 0x34) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
      uVar1 = param_1 + 0x48U & 3;
      uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
      *(uint *)(param_1 + 0x50) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    }
    if (iVar3 != 0) {
      Fs_Archive_Resume(param_1);
    }
  }
  return uVar4;
}

