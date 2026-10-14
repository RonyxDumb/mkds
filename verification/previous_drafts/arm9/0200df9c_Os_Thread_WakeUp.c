/* Decompiled C draft; module arm9; ROM address 0200df9c. No matching claim. */
#include "types.h"
#include "deps/0200df9c_Os_Thread_WakeUp.h"

void Os_Thread_WakeUp(uint *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = Os_DisableIrq();
  uVar1 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8;
  iVar3 = *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  if (uVar1 != 0 || iVar3 != 0) {
    if (uVar1 != 0 || iVar3 != 0) {
      do {
        iVar3 = Os_ThreadQueue_Pop(param_1);
        *(undefined4 *)(iVar3 + 100) = 1;
        *(undefined4 *)(iVar3 + 0x78) = 0;
        *(undefined4 *)(iVar3 + 0x80) = 0;
        uVar1 = iVar3 + 0x80U & 3;
        uVar4 = *(uint *)(iVar3 + 0x80U & 0xfffffffc);
        *(uint *)(iVar3 + 0x7c) = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
      } while (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 != 0 ||
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 != 0);
    }
    param_1[1] = 0;
    uVar1 = (uint)(param_1 + 1) & 3;
    uVar4 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
    *param_1 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
    Os_RescheduleThread();
  }
  Os_RestoreIrq(uVar2);
  return;
}

