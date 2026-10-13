/* Decompiled C draft; module arm9; ROM address 0214df78. No matching claim. */
#include "types.h"
#include "deps/0214df78_Rtc_GetTime.h"

uint Rtc_GetTime(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = Rtc_GetTimeAsync(param_1,uRam0214dfb4,0);
  *(int *)(iRam0214dfb8 + 0x20) = iVar2;
  if (iVar2 == 0) {
    Rtc_WaitBusy();
  }
  uVar1 = iRam0214dfb8 + 0x20U & 3;
  uVar3 = *(uint *)(iRam0214dfb8 + 0x20U & 0xfffffffc);
  return uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
}

