/* Decompiled C draft; module arm9; ROM address 0214e1e0. No matching claim. */
#include "types.h"
#include "deps/0214e1e0_Rtc_DateTime_GetSeconds.h"

int Rtc_DateTime_GetSeconds(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
  uVar3 = Rtc_Date_GetDays();
  if ((int)uVar3 == -1) {
    return -1;
  }
  iVar1 = Rtc_Time_GetSeconds(param_2,(int)((ulonglong)uVar3 >> 0x20));
  iVar2 = -1;
  if (iVar1 != -1) {
    iVar2 = iVar1 + iRam0214e254 * (int)uVar3;
  }
  return iVar2;
}

