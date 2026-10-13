/* Decompiled C draft; module arm9; ROM address 0200442c. No matching claim. */
#include "types.h"
#include "deps/0200442c_Fs_File_ExecuteSyncOperation.h"

bool Fs_File_ExecuteSyncOperation(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = param_1 + 0x10U & 3;
  uVar4 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar2 = Fs_File_DoExecuteOperation(param_1,uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  Fs_File_ReleaseOperation((undefined4 *)(uintptr_t)(param_1),uVar2);
  uVar1 = param_1 + 8U & 3;
  uVar4 = *(uint *)(param_1 + 8U & 0xfffffffc);
  iVar3 = Fs_Archive_HandleNextOperation(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  if (iVar3 != 0) {
    Fs_File_ExecuteAsyncOperation();
  }
  uVar1 = param_1 + 0x14U & 3;
  uVar4 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  return uVar4 >> uVar1 * 8 == 0 && uVar4 << uVar1 * -8 + 0x20 == 0;
}

