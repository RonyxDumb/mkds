/* Decompiled C draft; module arm9_ov003; ROM address 021c5f9c. No matching claim. */
#include "types.h"
#include "deps/021c5f9c_FUN_021c5f9c.h"

void FUN_021c5f9c(void)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = *DAT_021c6174;
  if (*(int *)(iVar2 + 0x38) == 0) {
    if (*(char *)(iVar2 + 0x55) != '\0') {
      *(char *)(iVar2 + 0x55) = *(char *)(iVar2 + 0x55) + -1;
    }
    uVar3 = FUN_021cce60();
    switch(uVar3) {
    case 1:
      *(undefined1 *)(*DAT_021c6174 + 0x57) = 1;
      FUN_021bf2d0();
      return;
    case 2:
      if (*(char *)(*DAT_021c6174 + 0x55) == '\0') {
        FUN_021bf698();
        iVar2 = FUN_021cce6c();
        sVar1 = func_0x02147d30(iVar2 * (uint)*(ushort *)(*DAT_021c6174 + 0x40),
                                *(undefined1 *)(*DAT_021c6174 + 0x53));
        *DAT_021c6178 = sVar1;
        FUN_021c5c68();
        *(undefined1 *)(*DAT_021c6174 + 0x55) = 4;
        return;
      }
      break;
    case 3:
      *(undefined1 *)(*DAT_021c6174 + 0x57) = 0;
      FUN_021bf2e0();
      iVar2 = FUN_021cce6c();
      sVar1 = func_0x02147d30(iVar2 * (uint)*(ushort *)(*DAT_021c6174 + 0x40),
                              *(undefined1 *)(*DAT_021c6174 + 0x53));
      *DAT_021c6178 = sVar1;
      FUN_021cdc10(0x13);
      FUN_021c5c68();
      iVar2 = func_0x02147cd8(*DAT_021c6178,0x1c);
      if (iVar2 == 0) {
        FUN_021c590c();
        return;
      }
      if (iVar2 < 0xe) {
        uVar3 = FUN_021d3544(0,DAT_021c617c,0,0x78);
        *(undefined4 *)(*DAT_021c6174 + 0x38) = uVar3;
        return;
      }
      uVar3 = FUN_021d3544(0,DAT_021c6180,0,0x78);
      *(undefined4 *)(*DAT_021c6174 + 0x38) = uVar3;
      return;
    case 4:
      if (*DAT_021c6178 != 0) {
        FUN_021cdc10(0x13);
        uVar3 = FUN_021d3544(0,DAT_021c617c,0,0x78);
        *(undefined4 *)(*DAT_021c6174 + 0x38) = uVar3;
        return;
      }
      if (*(char *)(*DAT_021c6174 + 0x58) == '\0') {
        FUN_021cdc10(9);
        *(undefined1 *)(*DAT_021c6174 + 0x58) = 1;
        return;
      }
      break;
    case 5:
    case 7:
      *(undefined1 *)(*DAT_021c6174 + 0x58) = 0;
      break;
    case 6:
      iVar2 = *DAT_021c6174;
      if ((4 < *(byte *)(iVar2 + 0x51)) && (*DAT_021c6178 != *(short *)(iVar2 + 0x40))) {
        FUN_021cdc10(0x13);
        uVar3 = FUN_021d3544(0,DAT_021c6180,0,0x78);
        *(undefined4 *)(*DAT_021c6174 + 0x38) = uVar3;
        return;
      }
      if (*(char *)(iVar2 + 0x58) == '\0') {
        FUN_021cdc10(9);
        *(undefined1 *)(*DAT_021c6174 + 0x58) = 1;
        return;
      }
    }
  }
  return;
}

