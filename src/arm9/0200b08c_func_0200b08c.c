/* Decompiled C draft; module arm9; ROM address 0200b08c. No matching claim. */
#include "types.h"
#include "deps/0200b08c_func_0200b08c.h"

void func_0200b08c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  code *pcVar6;
  
  while( true ) {
    uVar1 = Os_DisableIrq();
    iVar2 = *(int *)(param_1 + 0xc0);
    while (iVar2 == 0) {
      Os_Thread_SetPriority(param_1,0);
      Os_Thread_Sleep(0);
      iVar2 = *(int *)(param_1 + 0xc0);
    }
    puVar5 = *(undefined4 **)(param_1 + 0xc0);
    *(undefined4 *)(param_1 + 0xc0) = **(undefined4 **)(param_1 + 0xc0);
    Os_Thread_SetPriority(param_1,(uint)puVar5[1] >> 1);
    Os_RestoreIrq(uVar1);
    if ((code *)puVar5[2] != (code *)0x0) {
      (*(code *)puVar5[2])(puVar5);
    }
    uVar1 = Os_DisableIrq();
    pcVar6 = (code *)puVar5[3];
    uVar3 = Os_Thread_GetPriority(param_1);
    if (*(int *)(param_1 + 0xc0) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = uVar3;
      if (uVar3 < *(uint *)(*(int *)(param_1 + 0xc0) + 4) >> 1) {
        uVar4 = *(uint *)(*(int *)(param_1 + 0xc0) + 4) >> 1;
      }
    }
    if (uVar4 != uVar3) {
      Os_Thread_SetPriority(param_1);
    }
    *puVar5 = 0;
    puVar5[1] = puVar5[1] & 0xfffffffe;
    if (pcVar6 != (code *)0x0) {
      (*pcVar6)(puVar5);
    }
    if (puVar5 == (undefined4 *)(param_1 + 0xc4)) break;
    Os_RestoreIrq(uVar1);
  }
  Os_Thread_Exit();
  return;
}

