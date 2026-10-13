/* Decompiled C draft; module arm9; ROM address 0214c778. No matching claim. */
#include "types.h"
#include "deps/0214c778_MIi_CheckDma0SourceAddress.h"

void MIi_CheckDma0SourceAddress(int param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  
  if (param_1 != 0) {
    return;
  }
  uVar1 = param_2 & 0xff000000;
  if (param_4 == 0) {
    param_2 = param_2 + param_3;
  }
  else if (param_4 == 0x800000) {
    param_2 = param_2 - param_3;
  }
  if ((((uVar1 != 0x4000000) && (uVar1 < 0x8000000)) && ((param_2 & 0xff000000) != 0x4000000)) &&
     ((param_2 & 0xff000000) < 0x8000000)) {
    return;
  }
  Os_Terminate();
  return;
}

