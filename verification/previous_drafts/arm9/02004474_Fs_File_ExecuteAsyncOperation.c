/* Decompiled C draft; module arm9; ROM address 02004474. No matching claim. */
#include "types.h"
#include "deps/02004474_Fs_File_ExecuteAsyncOperation.h"

void Fs_File_ExecuteAsyncOperation(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = param_1 + 8U & 3;
  uVar6 = *(uint *)(param_1 + 8U & 0xfffffffc);
  if (param_1 == 0) {
    return;
  }
  while( true ) {
    uVar3 = Os_DisableIrq();
    uVar2 = param_1 + 0xcU & 3;
    uVar5 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    *(uint *)(param_1 + 0xc) = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20 | 0x40;
    uVar2 = param_1 + 0xcU & 3;
    uVar5 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    if (((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) & 4) != 0) {
      Os_Thread_WakeUp((uint *)(uintptr_t)(param_1 + 0x18));
      Os_RestoreIrq(uVar3);
      return;
    }
    uVar2 = param_1 + 0xcU & 3;
    uVar5 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    *(uint *)(param_1 + 0xc) = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20 | 8;
    Os_RestoreIrq(uVar3);
    uVar2 = param_1 + 0x10U & 3;
    uVar5 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
    iVar4 = Fs_File_DoExecuteOperation(param_1,uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20);
    if (iVar4 == 6) break;
    param_1 = Fs_Archive_HandleNextOperation(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20);
    if (param_1 == 0) {
      return;
    }
  }
  return;
}

