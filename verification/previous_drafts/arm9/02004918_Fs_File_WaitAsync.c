/* Decompiled C draft; module arm9; ROM address 02004918. No matching claim. */
#include "types.h"
#include "deps/02004918_Fs_File_WaitAsync.h"

uint Fs_File_WaitAsync(int param_1)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  bVar1 = false;
  uVar2 = Os_DisableIrq();
  uVar3 = param_1 + 0xcU & 3;
  uVar4 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  if (((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) & 1) != 0) {
    uVar3 = param_1 + 0xcU & 3;
    uVar4 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    uVar3 = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) & 0x44;
    bVar1 = uVar3 == 0;
    if (uVar3 == 0) {
      uVar3 = param_1 + 0xcU & 3;
      uVar4 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
      *(uint *)(param_1 + 0xc) = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20 | 4;
      do {
        Os_Thread_Sleep(param_1 + 0x18);
        uVar3 = param_1 + 0xcU & 3;
        uVar4 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
      } while (((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) & 0x40) == 0);
    }
    else {
      do {
        Os_Thread_Sleep(param_1 + 0x18);
        uVar3 = param_1 + 0xcU & 3;
        uVar4 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
      } while (((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) & 1) != 0);
    }
  }
  Os_RestoreIrq(uVar2);
  if (bVar1) {
    uVar3 = Fs_File_ExecuteSyncOperation(param_1);
    return uVar3;
  }
  uVar3 = param_1 + 0x14U & 3;
  uVar4 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  return (uint)(uVar4 >> uVar3 * 8 == 0 && uVar4 << uVar3 * -8 + 0x20 == 0);
}

