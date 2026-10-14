/* Decompiled C draft; module arm9; ROM address 0200cb9c. No matching claim. */
#include "types.h"
#include "deps/0200cb9c_OSi_EnterDmaCallback.h"

void OSi_EnterDmaCallback(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = iRam0200cbe0;
  iVar3 = param_1 * 0xc;
  *(undefined4 *)(iRam0200cbdc + iVar3) = param_2;
  *(undefined4 *)(iVar1 + iVar3) = param_3;
  uVar2 = Os_EnableIrqHandler(1 << (param_1 + 8U & 0xff));
  *(uint *)(iRam0200cbe4 + iVar3) = uVar2 & 1 << (param_1 + 8U & 0xff);
  return;
}

