/* Decompiled C draft; module arm9; ROM address 0200ecc4. No matching claim. */
#include "types.h"
#include "deps/0200ecc4_Os_Mutex_Unlock.h"

void Os_Mutex_Unlock(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = Os_DisableIrq();
  uVar1 = iRam0200ed30 + 4U & 3;
  uVar3 = *(uint *)(iRam0200ed30 + 4U & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 8U & 3;
  uVar4 = *(uint *)(param_1 + 8U & 0xfffffffc);
  if ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) == uVar3) {
    uVar1 = param_1 + 0xcU & 3;
    uVar4 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    *(uint *)(param_1 + 0xc) = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) - 1;
    uVar1 = param_1 + 0xcU & 3;
    uVar4 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    if (uVar4 >> uVar1 * 8 == 0 && uVar4 << uVar1 * -8 + 0x20 == 0) {
      Os_Mutex_DequeueThread(uVar3,param_1);
      *(undefined4 *)(param_1 + 8) = 0;
      Os_Thread_WakeUp((uint *)(uintptr_t)(param_1));
    }
  }
  Os_RestoreIrq(uVar2);
  return;
}

