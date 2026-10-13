/* Decompiled C draft; module arm9; ROM address 0200fb80. No matching claim. */
#include "types.h"
#include "deps/0200fb80_Os_SetAlarmTimer.h"

void Os_SetAlarmTimer(int param_1)

{
  undefined2 *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar7;
  uint uVar6;
  
  uVar7 = Os_GetTick();
  *puRam0200fc0c = 0;
  uVar2 = param_1 + 0xcU & 3;
  uVar5 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar6 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
  uVar2 = param_1 + 0x10U & 3;
  uVar5 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar4 = uVar6 - (uint)uVar7;
  iVar3 = (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) -
          ((int)((ulonglong)uVar7 >> 0x20) + (uint)(uVar6 < (uint)uVar7));
  Os_SetTimerIrqHandler(1,uRam0200fc10);
  puVar1 = puRam0200fc0c;
  uVar2 = uRam0200fc14;
  if ((-1 < iVar3) && (uVar2 = 0, iVar3 < (int)(uint)(uVar4 < 0x10000))) {
    uVar2 = ~uVar4 & 0xffff;
  }
  *puRam0200fc18 = (short)uVar2;
  *puVar1 = 0xc1;
  Os_EnableIrqHandler(0x10);
  return;
}

