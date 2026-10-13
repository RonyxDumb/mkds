/* Decompiled C draft; module arm9_ov000; ROM address 021898dc. No matching claim. */
#include "types.h"
#include "deps/021898dc_FUN_021898dc.h"

int FUN_021898dc(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_2 == 0x11) {
    return 0x11;
  }
  uVar3 = 0;
  uVar1 = (uint)*(byte *)(param_1 + DAT_02189984);
  if (uVar1 != 0) {
    do {
      if (*(char *)(param_1 + uVar3 * 4 + DAT_02189988) == '\0') break;
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < uVar1);
  }
  if (param_2 == 6) {
    if (uVar1 == uVar3) {
      if (uVar3 == 0) {
        FUN_02188508(5);
      }
      else {
        FUN_02188508(6);
      }
      return 0x11;
    }
  }
  else {
    if (uVar1 == 0) {
      return param_2;
    }
    if (uVar1 == uVar3) {
      return param_2;
    }
    if (*(byte *)(param_1 + uVar3 * 4 + DAT_0218998c) < 0x14) {
      return param_2;
    }
  }
  *(char *)(param_1 + DAT_02189990) = (char)uVar3;
  iVar2 = FUN_021a6024();
  if (iVar2 != 1) {
    *(char *)(param_1 + DAT_02189994) = (char)param_2;
    param_2 = 7;
  }
  return param_2;
}

