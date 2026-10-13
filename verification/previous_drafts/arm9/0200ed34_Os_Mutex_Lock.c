/* Decompiled C draft; module arm9; ROM address 0200ed34. No matching claim. */
#include "types.h"
#include "deps/0200ed34_Os_Mutex_Lock.h"

void Os_Mutex_Lock(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = Os_DisableIrq();
  uVar4 = iRam0200edbc + 4U & 3;
  uVar3 = *(uint *)(iRam0200edbc + 4U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  do {
    uVar3 = param_1 + 8U & 3;
    uVar2 = *(uint *)(param_1 + 8U & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    if (uVar3 == 0) {
      *(uint *)(param_1 + 8) = uVar4;
      uVar3 = param_1 + 0xcU & 3;
      uVar2 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
      *(uint *)(param_1 + 0xc) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 1;
      Os_Mutex_EnqueueThread(uVar4,param_1);
LAB_0200eda8:
      Os_RestoreIrq(uVar1);
      return;
    }
    if (uVar3 == uVar4) {
      uVar4 = param_1 + 0xcU & 3;
      uVar3 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
      *(uint *)(param_1 + 0xc) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 1;
      goto LAB_0200eda8;
    }
    *(int *)(uVar4 + 0x84) = param_1;
    Os_Thread_Sleep(param_1);
    *(undefined4 *)(uVar4 + 0x84) = 0;
  } while( true );
}

