/* Decompiled C draft; module arm9; ROM address 0200ec7c. No matching claim. */
#include "types.h"
#include "deps/0200ec7c_Os_UnlockAllMutexes.h"

void Os_UnlockAllMutexes(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = param_1 + 0x88U & 3;
  uVar2 = *(uint *)(param_1 + 0x88U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    do {
      iVar3 = Os_MutexQueue_Pop((uint *)(uintptr_t)(param_1 + 0x88));
      *(undefined4 *)(iVar3 + 0xc) = 0;
      *(undefined4 *)(iVar3 + 8) = 0;
      Os_Thread_WakeUp();
      uVar1 = param_1 + 0x88U & 3;
      uVar2 = *(uint *)(param_1 + 0x88U & 0xfffffffc);
    } while (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0);
    return;
  }
  return;
}

