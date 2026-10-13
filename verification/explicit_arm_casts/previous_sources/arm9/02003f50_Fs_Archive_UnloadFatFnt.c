/* Decompiled C draft; module arm9; ROM address 02003f50. No matching claim. */
#include "types.h"
#include "deps/02003f50_Fs_Archive_UnloadFatFnt.h"

undefined4 Fs_Archive_UnloadFatFnt(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = Os_DisableIrq();
  uVar3 = param_1 + 0x1cU & 3;
  uVar4 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  if (((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) & 2) != 0) {
    uVar3 = param_1 + 0x1cU & 3;
    uVar4 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    iVar2 = Fs_Archive_Suspend(param_1,uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20);
    uVar3 = param_1 + 0x1cU & 3;
    uVar4 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    *(uint *)(param_1 + 0x1c) = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20 | 0x80;
    uVar3 = param_1 + 0x24U & 3;
    uVar4 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
    uVar3 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
    while (uVar3 != 0) {
      uVar4 = uVar3 + 4 & 3;
      uVar5 = *(uint *)(uVar3 + 4 & 0xfffffffc);
      Fs_File_ReleaseOperation(uVar3,3);
      uVar3 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    }
    *(undefined4 *)(param_1 + 0x24) = 0;
    if (iVar2 != 0) {
      Fs_Archive_Resume(param_1);
    }
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(undefined4 *)(param_1 + 0x30) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(undefined4 *)(param_1 + 0x38) = 0;
    *(undefined4 *)(param_1 + 0x40) = 0;
    uVar3 = param_1 + 0x40U & 3;
    uVar4 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
    *(uint *)(param_1 + 0x3c) = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
    uVar3 = param_1 + 0x1cU & 3;
    uVar4 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    *(uint *)(param_1 + 0x1c) = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) & 0xffffff5d;
  }
  Os_RestoreIrq(uVar1);
  return 1;
}

