/* Decompiled C draft; module arm9; ROM address 02146300. No matching claim. */
#include "types.h"
#include "deps/02146300_task_fn.h"

void task_fn(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  code *pcVar8;
  
  uVar1 = uRam0214639c;
  iVar3 = GlobalSZ_SomeFn(uRam0214639c);
  if (iVar3 != 0) {
    (*(code *)(*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20))(uVar1);
  }
  uVar2 = uRam021463a0;
  *(undefined4 *)
   (*(uint *)(uRam021463a0 & 0xfffffffc) >> (uRam021463a0 & 3) * 8 |
   *(uint *)(uRam021463a0 & 0xfffffffc) << (uRam021463a0 & 3) * -8 + 0x20) = 0;
  uVar1 = uVar2 + 0x38 & 3;
  uVar7 = *(uint *)(uVar2 + 0x38 & 0xfffffffc);
  pcVar8 = (code *)(uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20);
  uVar1 = uVar2 + 0x3c & 3;
  uVar6 = *(uint *)(uVar2 + 0x3c & 0xfffffffc);
  uVar4 = Os_DisableIrq();
  uVar7 = uVar2 + 0x114 & 3;
  uVar5 = *(uint *)(uVar2 + 0x114 & 0xfffffffc);
  *(uint *)(uVar2 + 0x114) = (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) & 0xffffffb3;
  Os_Thread_WakeUp((uint *)(uintptr_t)(uVar2 + 0x10c));
  uVar7 = uVar2 + 0x114 & 3;
  uVar5 = *(uint *)(uVar2 + 0x114 & 0xfffffffc);
  if (((uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) & 0x10) != 0) {
    Os_Thread_WakeUpDirect(uVar2 + 0x44);
  }
  Os_RestoreIrq(uVar4);
  if (pcVar8 != (code *)0x0) {
    (*pcVar8)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20);
    return;
  }
  return;
}

