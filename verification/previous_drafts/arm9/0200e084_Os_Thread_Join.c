/* Decompiled C draft; module arm9; ROM address 0200e084. No matching claim. */
#include "types.h"
#include "deps/0200e084_Os_Thread_Join.h"

void Os_Thread_Join(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = Os_DisableIrq();
  uVar1 = param_1 + 100U & 3;
  uVar3 = *(uint *)(param_1 + 100U & 0xfffffffc);
  if ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) != 2) {
    Os_Thread_Sleep(param_1 + 0x9c);
  }
  Os_RestoreIrq(uVar2);
  return;
}

