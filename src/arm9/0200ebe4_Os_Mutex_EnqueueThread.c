/* Decompiled C draft; module arm9; ROM address 0200ebe4. No matching claim. */
#include "types.h"
#include "deps/0200ebe4_Os_Mutex_EnqueueThread.h"

void Os_Mutex_EnqueueThread(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 + 0x8cU & 3;
  uVar1 = *(uint *)(param_1 + 0x8cU & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 == 0) {
    *(int *)(param_1 + 0x88) = param_2;
  }
  else {
    *(int *)(uVar2 + 0x10) = param_2;
  }
  *(uint *)(param_2 + 0x14) = uVar2;
  *(undefined4 *)(param_2 + 0x10) = 0;
  *(int *)(param_1 + 0x8c) = param_2;
  return;
}

