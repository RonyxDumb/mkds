/* Decompiled C draft; module arm9; ROM address 0200f7a0. No matching claim. */
#include "types.h"
#include "deps/0200f7a0_Os_AlarmHandlerImpl.h"

void Os_AlarmHandlerImpl(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  code *pcVar6;
  uint uVar7;
  bool bVar8;
  undefined8 uVar9;
  
  *puRam0200f8ac = 0;
  Os_DisableIrqHandler(0x10);
  uVar3 = iRam0200f8b0 + 0x3ff8U & 3;
  uVar2 = *(uint *)(iRam0200f8b0 + 0x3ff8U & 0xfffffffc);
  *(uint *)(iRam0200f8b0 + 0x3ff8) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20 | 0x10;
  uVar9 = Os_GetTick();
  puVar1 = puRam0200f8b4;
  uVar3 = (uint)((ulonglong)uVar9 >> 0x20);
  puVar5 = (undefined4 *)
           (*(uint *)((uint)puRam0200f8b4 & 0xfffffffc) >> ((uint)puRam0200f8b4 & 3) * 8 |
           *(uint *)((uint)puRam0200f8b4 & 0xfffffffc) << ((uint)puRam0200f8b4 & 3) * -8 + 0x20);
  if (puVar5 == (undefined4 *)0x0) {
    return;
  }
  uVar2 = (uint)(puVar5 + 4) & 3;
  uVar4 = *(uint *)((uint)(puVar5 + 4) & 0xfffffffc);
  uVar4 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
  uVar2 = (uint)(puVar5 + 3) & 3;
  uVar7 = *(uint *)((uint)(puVar5 + 3) & 0xfffffffc);
  bVar8 = uVar4 <= uVar3;
  if (uVar3 == uVar4) {
    bVar8 = (uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) <= (uint)uVar9;
  }
  if (bVar8) {
    uVar3 = (uint)(puVar5 + 6) & 3;
    uVar2 = *(uint *)((uint)(puVar5 + 6) & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    if (uVar3 == 0) {
      puRam0200f8b4[1] = 0;
    }
    *puVar1 = uVar3;
    if (uVar3 != 0) {
      *(undefined4 *)(uVar3 + 0x14) = 0;
    }
    uVar3 = (uint)(puVar5 + 7) & 3;
    uVar7 = *(uint *)((uint)(puVar5 + 7) & 0xfffffffc);
    uVar2 = (uint)(puVar5 + 8) & 3;
    uVar4 = *(uint *)((uint)(puVar5 + 8) & 0xfffffffc);
    pcVar6 = (code *)(*(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
                     *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20);
    if ((uVar4 >> uVar2 * 8 == 0 && uVar4 << uVar2 * -8 + 0x20 == 0) &&
        (uVar7 >> uVar3 * 8 == 0 && uVar7 << uVar3 * -8 + 0x20 == 0)) {
      *puVar5 = 0;
    }
    if (pcVar6 != (code *)0x0) {
      uVar3 = (uint)(puVar5 + 1) & 3;
      uVar2 = *(uint *)((uint)(puVar5 + 1) & 0xfffffffc);
      (*pcVar6)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
    }
    uVar3 = (uint)(puVar5 + 7) & 3;
    uVar7 = *(uint *)((uint)(puVar5 + 7) & 0xfffffffc);
    uVar2 = (uint)(puVar5 + 8) & 3;
    uVar4 = *(uint *)((uint)(puVar5 + 8) & 0xfffffffc);
    if ((uVar4 >> uVar2 * 8 != 0 || uVar4 << uVar2 * -8 + 0x20 != 0) ||
        (uVar7 >> uVar3 * 8 != 0 || uVar7 << uVar3 * -8 + 0x20 != 0)) {
      *puVar5 = pcVar6;
      Os_InsertAlarm((int)(uintptr_t)(puVar5),0,0);
    }
    if (*(uint *)((uint)puRam0200f8b4 & 0xfffffffc) >> ((uint)puRam0200f8b4 & 3) * 8 != 0 ||
        *(uint *)((uint)puRam0200f8b4 & 0xfffffffc) << ((uint)puRam0200f8b4 & 3) * -8 + 0x20 != 0) {
      Os_SetAlarmTimer();
      return;
    }
    return;
  }
  Os_SetAlarmTimer((int)(uintptr_t)(puVar5));
  return;
}

