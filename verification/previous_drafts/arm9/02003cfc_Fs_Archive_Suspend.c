/* Decompiled C draft; module arm9; ROM address 02003cfc. No matching claim. */
#include "types.h"
#include "deps/02003cfc_Fs_Archive_Suspend.h"

bool Fs_Archive_Suspend(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  bool bVar4;
  
  uVar2 = Os_DisableIrq();
  uVar1 = param_1 + 0x1cU & 3;
  uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  bVar4 = ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 8) == 0;
  if (bVar4) {
    uVar1 = param_1 + 0x1cU & 3;
    uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x10) == 0) {
      uVar1 = param_1 + 0x1cU & 3;
      uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
      *(uint *)(param_1 + 0x1c) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20 | 8;
    }
    else {
      uVar1 = param_1 + 0x1cU & 3;
      uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
      *(uint *)(param_1 + 0x1c) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20 | 0x40;
      do {
        Os_Thread_Sleep(param_1 + 0x14);
        uVar1 = param_1 + 0x1cU & 3;
        uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
      } while (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x40) != 0);
    }
  }
  Os_RestoreIrq(uVar2);
  return bVar4;
}

