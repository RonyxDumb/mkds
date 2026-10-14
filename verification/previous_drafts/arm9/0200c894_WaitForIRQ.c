/* Decompiled C draft; module arm9; ROM address 0200c894. No matching claim. */
#include "types.h"
#include "deps/0200c894_WaitForIRQ.h"

void WaitForIRQ(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  Os_DisableIrq();
  if (param_1 != 0) {
    uVar4 = iRam0200c908 + 0x3ff8U & 3;
    uVar3 = *(uint *)(iRam0200c908 + 0x3ff8U & 0xfffffffc);
    *(uint *)(iRam0200c908 + 0x3ff8) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & ~param_2;
  }
  Os_RestoreIrq();
  uVar1 = uRam0200c910;
  uVar4 = iRam0200c908 + 0x3ff8U & 3;
  uVar3 = *(uint *)(iRam0200c908 + 0x3ff8U & 0xfffffffc);
  if ((param_2 & (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20)) == 0) {
    uVar4 = iRam0200c908 + iRam0200c90c;
    do {
      Os_Thread_Sleep(uVar1);
      uVar3 = uVar4 & 3;
      uVar2 = *(uint *)(uVar4 & 0xfffffffc);
    } while ((param_2 & (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) == 0);
    return;
  }
  return;
}

