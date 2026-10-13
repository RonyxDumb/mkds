/* Decompiled C draft; module arm9; ROM address 02004b98. No matching claim. */
#include "types.h"
#include "deps/02004b98_Fs_File_DoRead.h"

int Fs_File_DoRead(int param_1,undefined4 param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar5;
  uint uVar4;
  
  uVar1 = param_1 + 0x2cU & 3;
  uVar3 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
  uVar4 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x28U & 3;
  uVar3 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
  *(undefined4 *)(param_1 + 0x30) = param_2;
  iVar2 = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) - uVar4;
  iVar5 = param_3;
  if (iVar2 < param_3) {
    iVar5 = iVar2;
  }
  if (iVar5 < 0) {
    iVar5 = 0;
  }
  *(int *)(param_1 + 0x34) = param_3;
  *(int *)(param_1 + 0x38) = iVar5;
  if (param_4 == 0) {
    uVar1 = param_1 + 0xcU & 3;
    uVar3 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    *(uint *)(param_1 + 0xc) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20 | 4;
  }
  Fs_File_SendOperation(param_1,0);
  if (param_4 == 0) {
    iVar5 = Fs_File_WaitAsync(param_1);
    if (iVar5 == 0) {
      iVar5 = -1;
    }
    else {
      uVar1 = param_1 + 0x2cU & 3;
      uVar3 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
      iVar5 = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) - uVar4;
    }
  }
  return iVar5;
}

