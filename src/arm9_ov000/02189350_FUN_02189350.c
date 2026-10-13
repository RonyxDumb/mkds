/* Decompiled C draft; module arm9_ov000; ROM address 02189350. No matching claim. */
#include "types.h"
#include "deps/02189350_FUN_02189350.h"

int FUN_02189350(int param_1)

{
  int iVar1;
  
  if (*(byte *)(param_1 + 0x16) < 10) {
    if (*(char *)(param_1 + 0x14) == '\x03') {
      iVar1 = DAT_021893f4 - (uint)*(byte *)(param_1 + 0x15);
    }
    else if (*(char *)(param_1 + 0x14) == '\x04') {
      iVar1 = DAT_021893f8 - (uint)*(byte *)(param_1 + 0x15);
    }
    else {
      iVar1 = data_ov000_021893fc - (uint)*(byte *)(param_1 + 0x15);
    }
  }
  else if (*(byte *)(param_1 + 0x16) < 0xd) {
    iVar1 = DAT_02189400 - (uint)*(byte *)(param_1 + 0x15);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x10);
    if (iVar1 == 0) {
      iVar1 = DAT_02189404 - (uint)*(byte *)(param_1 + 0x15);
    }
    else if (iVar1 == -1) {
      iVar1 = DAT_02189408 - (uint)*(byte *)(param_1 + 0x15);
    }
    else if (iVar1 == -2) {
      iVar1 = DAT_0218940c - (uint)*(byte *)(param_1 + 0x15);
    }
    else if (iVar1 == -3) {
      iVar1 = data_ov000_02189410 - (uint)*(byte *)(param_1 + 0x15);
    }
    else if (iVar1 == -4) {
      iVar1 = DAT_02189414 - (uint)*(byte *)(param_1 + 0x15);
    }
    else if (iVar1 == -5) {
      iVar1 = DAT_02189418 - (uint)*(byte *)(param_1 + 0x15);
    }
    else if (iVar1 == -6) {
      iVar1 = DAT_0218941c - (uint)*(byte *)(param_1 + 0x15);
    }
  }
  return iVar1;
}

