/* Decompiled C draft; module arm9; ROM address 02145a70. No matching claim. */
#include "types.h"
#include "deps/02145a70_Card_LockResource.h"

void Card_LockResource(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar2 = uRam02145b08;
  uVar3 = Os_DisableIrq();
  uVar1 = uVar2 + 8 & 3;
  uVar4 = *(uint *)(uVar2 + 8 & 0xfffffffc);
  if ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) == param_1) {
    uVar1 = uVar2 + 0x18 & 3;
    uVar4 = *(uint *)(uVar2 + 0x18 & 0xfffffffc);
    if ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) != param_2) {
      Os_Terminate();
    }
  }
  else {
    uVar1 = uVar2 + 8 & 3;
    uVar4 = *(uint *)(uVar2 + 8 & 0xfffffffc);
    if ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) != 0xfffffffd) {
      do {
        Os_Thread_Sleep(uVar2 + 0x10);
        uVar1 = uVar2 + 8 & 3;
        uVar4 = *(uint *)(uVar2 + 8 & 0xfffffffc);
      } while ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) != 0xfffffffd);
    }
    *(uint *)(uVar2 + 8) = param_1;
    *(uint *)(uVar2 + 0x18) = param_2;
  }
  uVar1 = uVar2 + 0xc & 3;
  uVar4 = *(uint *)(uVar2 + 0xc & 0xfffffffc);
  *(uint *)(uVar2 + 0xc) = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + 1;
  *(undefined4 *)
   (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
   *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) = 0;
  Os_RestoreIrq(uVar3);
  return;
}

