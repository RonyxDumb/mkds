/* Decompiled C draft; module arm9; ROM address 0200de50. No matching claim. */
#include "types.h"
#include "deps/0200de50_Os_RescheduleThread.h"

void Os_RescheduleThread(void)

{
  undefined2 *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  code *pcVar7;
  
  puVar1 = puRam0200df30;
  if (*(uint *)(uRam0200df2c & 0xfffffffc) >> (uRam0200df2c & 3) * 8 != 0 ||
      *(uint *)(uRam0200df2c & 0xfffffffc) << (uRam0200df2c & 3) * -8 + 0x20 != 0) {
    return;
  }
  if ((puRam0200df30[1] != 0) || (iVar3 = Arm_GetProcessorMode(), iVar3 == 0x12)) {
    *puVar1 = 1;
    return;
  }
  uVar4 = *(uint *)(uRam0200df34 & 0xfffffffc) >> (uRam0200df34 & 3) * 8 |
          *(uint *)(uRam0200df34 & 0xfffffffc) << (uRam0200df34 & 3) * -8 + 0x20;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = Os_FindReadyThread();
  if (uVar4 == uVar5) {
    return;
  }
  if (uVar5 != 0) {
    uVar2 = uVar4 + 100 & 3;
    uVar6 = *(uint *)(uVar4 + 100 & 0xfffffffc);
    if (((uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) != 2) &&
       (iVar3 = Arm_Context_Save(uVar4), iVar3 != 0)) {
      return;
    }
    pcVar7 = (code *)(*(uint *)(uRam0200df38 & 0xfffffffc) >> (uRam0200df38 & 3) * 8 |
                     *(uint *)(uRam0200df38 & 0xfffffffc) << (uRam0200df38 & 3) * -8 + 0x20);
    if (pcVar7 != (code *)0x0) {
      (*pcVar7)(uVar4,uVar5);
    }
    puVar1 = puVar1 + 6;
    uVar2 = (uint)puVar1 & 3;
    uVar6 = *(uint *)((uint)puVar1 & 0xfffffffc);
    pcVar7 = (code *)(uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20);
    if (pcVar7 != (code *)0x0) {
      (*pcVar7)(uVar4,uVar5);
    }
    *(uint *)(puRam0200df30 + 2) = uVar5;
    Arm_Context_Load(uVar5);
    return;
  }
  return;
}

