/* Decompiled C draft; module arm9; ROM address 0200f8b8. No matching claim. */
#include "types.h"
#include "deps/0200f8b8_Os_Alarm_Cancel.h"

void Os_Alarm_Cancel(undefined4 *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar4;
  uint uVar3;
  
  uVar1 = Os_DisableIrq();
  if (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 != 0 ||
      *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 != 0) {
    uVar3 = (uint)(param_1 + 6) & 3;
    uVar2 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    if (uVar3 == 0) {
      uVar2 = (uint)(param_1 + 5) & 3;
      uVar4 = *(uint *)((uint)(param_1 + 5) & 0xfffffffc);
      puRam0200f94c[1] = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
    }
    else {
      uVar2 = (uint)(param_1 + 5) & 3;
      uVar4 = *(uint *)((uint)(param_1 + 5) & 0xfffffffc);
      *(uint *)(uVar3 + 0x14) = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
    }
    uVar2 = (uint)(param_1 + 5) & 3;
    uVar4 = *(uint *)((uint)(param_1 + 5) & 0xfffffffc);
    uVar2 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
    if (uVar2 == 0) {
      *puRam0200f94c = uVar3;
      if (uVar3 != 0) {
        Os_SetAlarmTimer();
      }
    }
    else {
      *(uint *)(uVar2 + 0x18) = uVar3;
    }
    *param_1 = 0;
    param_1[7] = 0;
    param_1[8] = 0;
    Os_RestoreIrq(uVar1);
    return;
  }
  Os_RestoreIrq();
  return;
}

