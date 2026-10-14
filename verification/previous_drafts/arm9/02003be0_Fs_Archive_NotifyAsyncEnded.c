/* Decompiled C draft; module arm9; ROM address 02003be0. No matching claim. */
#include "types.h"
#include "deps/02003be0_Fs_Archive_NotifyAsyncEnded.h"

void Fs_Archive_NotifyAsyncEnded(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  
  uVar1 = param_1 + 0x1cU & 3;
  uVar2 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x100) == 0) {
    uVar1 = param_1 + 0x24U & 3;
    uVar2 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
    uVar5 = Os_DisableIrq();
    *(undefined4 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x14) = param_2;
    uVar1 = param_1 + 0x1cU & 3;
    uVar2 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    *(uint *)(param_1 + 0x1c) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xfffffdff;
    Os_Thread_WakeUp((uint *)(uintptr_t)(param_1 + 0xc));
    Os_RestoreIrq(uVar5);
    return;
  }
  uVar1 = param_1 + 0x1cU & 3;
  uVar6 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  uVar2 = param_1 + 0x24U & 3;
  uVar3 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
  *(uint *)(param_1 + 0x1c) = (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) & 0xfffffeff;
  Fs_File_ReleaseOperation(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  iVar4 = Fs_Archive_HandleNextOperation(param_1);
  if (iVar4 != 0) {
    Fs_File_ExecuteAsyncOperation();
    return;
  }
  return;
}

