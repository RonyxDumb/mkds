/* Decompiled C draft; module arm9; ROM address 0200b02c. No matching claim. */
#include "types.h"
#include "deps/0200b02c_InitializeSetGlobalAN_from_thumb.h"

void InitializeSetGlobalAN_from_thumb(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = Os_DisableIrq();
  if (*piRam0200b084 == 0) {
    *piRam0200b084 = param_1;
    StructANN_Create_from_thumb(param_1 + 0xc4);
    *(undefined4 *)(param_1 + 0xc0) = 0;
    uVar2 = param_2 - 0xe4U & 0xfffffffc;
    Os_Thread_Create(param_1,uRam0200b088,param_1,param_1 + 0xe4 + uVar2,uVar2,0);
    Os_Thread_WakeUpDirect(param_1);
  }
  Os_RestoreIrq(uVar1);
  return;
}

