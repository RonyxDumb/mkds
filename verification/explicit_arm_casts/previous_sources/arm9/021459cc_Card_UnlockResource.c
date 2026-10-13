/* Decompiled C draft; module arm9; ROM address 021459cc. No matching claim. */
#include "types.h"
#include "deps/021459cc_Card_UnlockResource.h"

void Card_UnlockResource(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar2 = uRam02145a6c;
  uVar3 = Os_DisableIrq();
  uVar1 = uVar2 + 8 & 3;
  uVar4 = *(uint *)(uVar2 + 8 & 0xfffffffc);
  if (((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) == param_1) &&
     (uVar1 = uVar2 + 0xc & 3, uVar4 = *(uint *)(uVar2 + 0xc & 0xfffffffc),
     uVar4 >> uVar1 * 8 != 0 || uVar4 << uVar1 * -8 + 0x20 != 0)) {
    uVar1 = uVar2 + 0x18 & 3;
    uVar4 = *(uint *)(uVar2 + 0x18 & 0xfffffffc);
    if ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) != param_2) {
      Os_Terminate();
    }
    uVar1 = uVar2 + 0xc & 3;
    uVar4 = *(uint *)(uVar2 + 0xc & 0xfffffffc);
    *(uint *)(uVar2 + 0xc) = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) - 1;
    uVar1 = uVar2 + 0xc & 3;
    uVar4 = *(uint *)(uVar2 + 0xc & 0xfffffffc);
    if (uVar4 >> uVar1 * 8 == 0 && uVar4 << uVar1 * -8 + 0x20 == 0) {
      *(undefined4 *)(uVar2 + 8) = 0xfffffffd;
      *(undefined4 *)(uVar2 + 0x18) = 0;
      Os_Thread_WakeUp(uVar2 + 0x10);
    }
  }
  else {
    Os_Terminate();
  }
  *(undefined4 *)
   (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
   *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) = 0;
  Os_RestoreIrq(uVar3);
  return;
}

