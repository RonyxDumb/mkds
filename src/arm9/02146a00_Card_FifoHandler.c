/* Decompiled C draft; module arm9; ROM address 02146a00. No matching claim. */
#include "types.h"
#include "deps/02146a00_Card_FifoHandler.h"

void Card_FifoHandler(int param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = iRam02146a4c;
  if (param_1 != 0xb) {
    return;
  }
  if (param_3 != 0) {
    uVar1 = iRam02146a4c + 0x114U & 3;
    uVar3 = *(uint *)(iRam02146a4c + 0x114U & 0xfffffffc);
    *(uint *)(iRam02146a4c + 0x114) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0xffffffdf
    ;
    uVar1 = iVar2 + 0x104U & 3;
    uVar3 = *(uint *)(iVar2 + 0x104U & 0xfffffffc);
    Os_Thread_WakeUpDirect(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
    return;
  }
  return;
}

