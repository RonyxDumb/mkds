/* Decompiled C draft; module arm9; ROM address 02146600. No matching claim. */
#include "types.h"
#include "deps/02146600_CardIRQHandler.h"

void CardIRQHandler(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  code *pcVar10;
  
  uVar1 = uRam021466d4 + 0x28 & 3;
  uVar3 = *(uint *)(uRam021466d4 + 0x28 & 0xfffffffc);
  Mem_DmaStop(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  uVar7 = uRam021466d4;
  uVar1 = uRam021466d4 + 0x1c & 3;
  uVar9 = *(uint *)(uRam021466d4 + 0x1c & 0xfffffffc);
  uVar3 = uRam021466d4 + 0x20 & 3;
  uVar8 = *(uint *)(uRam021466d4 + 0x20 & 0xfffffffc);
  uVar2 = uRam021466d4 + 0x24 & 3;
  uVar5 = *(uint *)(uRam021466d4 + 0x24 & 0xfffffffc);
  iVar6 = (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) - 0x200;
  *(uint *)(uRam021466d4 + 0x1c) = (uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20) + 0x200;
  *(uint *)(uVar7 + 0x20) = (uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) + 0x200;
  *(int *)(uVar7 + 0x24) = iVar6;
  if (iVar6 != 0) {
    MaybeGamecardTransferSY();
    return;
  }
  Os_DisableIrqHandler(0x80000);
  SetIF(0x80000);
  uVar2 = uRam021466d4;
  *(undefined4 *)
   (*(uint *)(uRam021466d4 & 0xfffffffc) >> (uRam021466d4 & 3) * 8 |
   *(uint *)(uRam021466d4 & 0xfffffffc) << (uRam021466d4 & 3) * -8 + 0x20) = 0;
  uVar1 = uVar2 + 0x38 & 3;
  uVar3 = *(uint *)(uVar2 + 0x38 & 0xfffffffc);
  pcVar10 = (code *)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  uVar1 = uVar2 + 0x3c & 3;
  uVar5 = *(uint *)(uVar2 + 0x3c & 0xfffffffc);
  uVar4 = Os_DisableIrq();
  uVar3 = uVar2 + 0x114 & 3;
  uVar7 = *(uint *)(uVar2 + 0x114 & 0xfffffffc);
  *(uint *)(uVar2 + 0x114) = (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) & 0xffffffb3;
  Os_Thread_WakeUp(uVar2 + 0x10c);
  uVar3 = uVar2 + 0x114 & 3;
  uVar7 = *(uint *)(uVar2 + 0x114 & 0xfffffffc);
  if (((uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) & 0x10) != 0) {
    Os_Thread_WakeUpDirect(uVar2 + 0x44);
  }
  Os_RestoreIrq(uVar4);
  if (pcVar10 != (code *)0x0) {
    (*pcVar10)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20);
    return;
  }
  return;
}

