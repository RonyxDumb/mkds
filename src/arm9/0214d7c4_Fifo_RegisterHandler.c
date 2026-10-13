/* Decompiled C draft; module arm9; ROM address 0214d7c4. No matching claim. */
#include "types.h"
#include "deps/0214d7c4_Fifo_RegisterHandler.h"

void Fifo_RegisterHandler(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  Os_DisableIrq();
  *(int *)(iRam0214d828 + param_1 * 4) = param_2;
  if (param_2 == 0) {
    uVar1 = iRam0214d82c + 0x388U & 3;
    uVar2 = *(uint *)(iRam0214d82c + 0x388U & 0xfffffffc);
    *(uint *)(iRam0214d82c + 0x388) =
         (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & ~(1 << (param_1 & 0xff));
  }
  else {
    uVar1 = iRam0214d82c + 0x388U & 3;
    uVar2 = *(uint *)(iRam0214d82c + 0x388U & 0xfffffffc);
    *(uint *)(iRam0214d82c + 0x388) =
         uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 1 << (param_1 & 0xff);
  }
  Os_RestoreIrq();
  return;
}

