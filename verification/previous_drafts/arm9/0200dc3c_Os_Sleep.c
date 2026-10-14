/* Decompiled C draft; module arm9; ROM address 0200dc3c. No matching claim. */
#include "types.h"
#include "deps/0200dc3c_Os_Sleep.h"

void Os_Sleep(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint local_3c;
  undefined1 auStack_38 [44];
  
  Os_Alarm_Create((undefined4 *)(void *)(auStack_38));
  uVar1 = *(uint *)(uRam0200dccc & 0xfffffffc) >> (uRam0200dccc & 3) * 8 |
          *(uint *)(uRam0200dccc & 0xfffffffc) << (uRam0200dccc & 3) * -8 + 0x20;
  uVar3 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  local_3c = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20;
  uVar2 = Os_DisableIrq();
  uVar3 = param_1 * iRam0200dcd0;
  *(undefined1 **)(local_3c + 0xb0) = auStack_38;
  Os_Alarm_Set((undefined4 *)(void *)(auStack_38),uVar3 >> 6,0,uRam0200dcd4,(undefined4)(uintptr_t)(&local_3c));
  while (local_3c != 0) {
    Os_Thread_Sleep(0);
  }
  Os_RestoreIrq(uVar2);
  return;
}

