/* Decompiled C draft; module arm9; ROM address 02003c80. No matching claim. */
#include "types.h"
#include "deps/02003c80_Fs_Archive_Resume.h"

bool Fs_Archive_Resume(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  
  iVar4 = 0;
  uVar2 = Os_DisableIrq();
  uVar1 = param_1 + 0x1cU & 3;
  uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  bVar5 = ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 8) == 0;
  if (!bVar5) {
    uVar1 = param_1 + 0x1cU & 3;
    uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    *(uint *)(param_1 + 0x1c) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0xfffffff7;
    iVar4 = Fs_Archive_HandleNextOperation(param_1);
  }
  Os_RestoreIrq(uVar2);
  if (iVar4 != 0) {
    Fs_File_ExecuteAsyncOperation(iVar4);
  }
  return bVar5;
}

