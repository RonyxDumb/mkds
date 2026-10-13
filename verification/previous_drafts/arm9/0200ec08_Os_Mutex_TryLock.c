/* Decompiled C draft; module arm9; ROM address 0200ec08. No matching claim. */
#include "types.h"
#include "deps/0200ec08_Os_Mutex_TryLock.h"

undefined4 Os_Mutex_TryLock(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar5;
  uint uVar4;
  
  uVar1 = Os_DisableIrq();
  uVar2 = param_1 + 8U & 3;
  uVar3 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar4 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  uVar2 = iRam0200ec78 + 4U & 3;
  uVar3 = *(uint *)(iRam0200ec78 + 4U & 0xfffffffc);
  uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  if (uVar4 == 0) {
    *(uint *)(param_1 + 8) = uVar2;
    uVar3 = param_1 + 0xcU & 3;
    uVar4 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    *(uint *)(param_1 + 0xc) = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 1;
    Os_Mutex_EnqueueThread(uVar2,param_1);
    uVar5 = 1;
  }
  else if (uVar4 == uVar2) {
    uVar2 = param_1 + 0xcU & 3;
    uVar3 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    uVar5 = 1;
    *(uint *)(param_1 + 0xc) = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + 1;
  }
  else {
    uVar5 = 0;
  }
  Os_RestoreIrq(uVar1);
  return uVar5;
}

