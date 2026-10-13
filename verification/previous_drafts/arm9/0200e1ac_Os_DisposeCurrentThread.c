/* Decompiled C draft; module arm9; ROM address 0200e1ac. No matching claim. */
#include "types.h"
#include "deps/0200e1ac_Os_DisposeCurrentThread.h"

void Os_DisposeCurrentThread(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar4;
  code *pcVar3;
  
  uVar1 = *(uint *)(uRam0200e1ec & 0xfffffffc) >> (uRam0200e1ec & 3) * 8 |
          *(uint *)(uRam0200e1ec & 0xfffffffc) << (uRam0200e1ec & 3) * -8 + 0x20;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar4 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  uVar2 = uVar4 + 0xb4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  pcVar3 = (code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  if (pcVar3 != (code *)0x0) {
    *(undefined4 *)(uVar4 + 0xb4) = 0;
    (*pcVar3)();
    Os_DisableIrq();
  }
  Os_DisposeCurrentThreadImpl();
  return;
}

