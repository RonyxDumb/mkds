/* Decompiled C draft; module arm9_ov003; ROM address 021c580c. No matching claim. */
#include "types.h"
#include "deps/021c580c_FUN_021c580c.h"

void FUN_021c580c(int param_1)

{
  byte bVar1;
  bool bVar2;
  byte *pbVar3;
  undefined4 uVar4;
  uint uVar5;
  
  pbVar3 = DAT_021c58fc;
  bVar2 = true;
  bVar1 = *DAT_021c58fc;
  switch((uint)bVar1) {
  case 0:
    if (param_1 == 1) {
      if (*DAT_021c5900 != 0) {
        FUN_021cdc10(0x13);
        uVar4 = FUN_021d3544(0,DAT_021c5904,0,0x78);
        *(undefined4 *)(*DAT_021c5908 + 0x38) = uVar4;
        return;
      }
      *DAT_021c58fc = 4;
    }
    else if (*(byte *)(*DAT_021c5908 + 0x51) < 2) {
      bVar2 = false;
    }
    else {
      *DAT_021c58fc = bVar1 + 1;
    }
    break;
  case 1:
  case 2:
    if (param_1 == 1) {
      *DAT_021c58fc = bVar1 - 1;
    }
    else {
      uVar5 = bVar1 + 1;
      if (uVar5 < *(byte *)(*DAT_021c5908 + 0x51)) {
        *DAT_021c58fc = (byte)uVar5;
      }
      else {
        bVar2 = false;
      }
    }
    break;
  case 3:
    if (param_1 != 1) {
      FUN_021c574c();
      return;
    }
    *DAT_021c58fc = bVar1 - 1;
    break;
  case 4:
    if (param_1 == 1) {
      bVar2 = false;
    }
    else {
      *DAT_021c5900 = 0;
      *pbVar3 = 0;
      FUN_021c5c68();
      thunk_FUN_021cca74(0);
    }
  }
  if (bVar2) {
    FUN_021cdc10(8);
    FUN_021c590c();
  }
  else if (*(char *)(*DAT_021c5908 + 0x59) == '\0') {
    FUN_021cdc10(9);
    *(undefined1 *)(*DAT_021c5908 + 0x59) = 1;
    return;
  }
  return;
}

