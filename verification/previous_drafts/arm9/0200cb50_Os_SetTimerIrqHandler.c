/* Decompiled C draft; module arm9; ROM address 0200cb50. No matching claim. */
#include "types.h"
#include "deps/0200cb50_Os_SetTimerIrqHandler.h"

void Os_SetTimerIrqHandler(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = iRam0200cb94;
  iVar2 = param_1 * 0xc;
  *(undefined4 *)(iRam0200cb90 + iVar2) = param_2;
  *(undefined4 *)(iVar1 + iVar2) = param_3;
  Os_EnableIrqHandler(1 << (param_1 + 3U & 0xff));
  *(undefined4 *)(iRam0200cb98 + iVar2) = 1;
  return;
}

