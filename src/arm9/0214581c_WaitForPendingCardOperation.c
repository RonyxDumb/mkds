/* Decompiled C draft; module arm9; ROM address 0214581c. No matching claim. */
#include "types.h"
#include "deps/0214581c_WaitForPendingCardOperation.h"

bool WaitForPendingCardOperation(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = uRam02145874;
  uVar2 = Os_DisableIrq();
  uVar1 = uVar3 + 0x114 & 3;
  uVar4 = *(uint *)(uVar3 + 0x114 & 0xfffffffc);
  if (((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 4) != 0) {
    do {
      Os_Thread_Sleep(uVar3 + 0x10c);
      uVar1 = uVar3 + 0x114 & 3;
      uVar4 = *(uint *)(uVar3 + 0x114 & 0xfffffffc);
    } while (((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 4) != 0);
  }
  Os_RestoreIrq(uVar2);
  uVar3 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  return uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0;
}

