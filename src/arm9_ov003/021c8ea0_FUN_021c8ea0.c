/* Decompiled C draft; module arm9_ov003; ROM address 021c8ea0. No matching claim. */
#include "types.h"
#include "deps/021c8ea0_FUN_021c8ea0.h"

void FUN_021c8ea0(void)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = *DAT_021c9048;
  if (*(int *)(iVar2 + 0x38) == 0) {
    if (*(char *)(iVar2 + 0x41) != '\0') {
      *(char *)(iVar2 + 0x41) = *(char *)(iVar2 + 0x41) + -1;
    }
    uVar3 = FUN_021cce60();
    switch(uVar3) {
    case 1:
      *(undefined1 *)(*DAT_021c9048 + 0x45) = 1;
      return;
    case 2:
      if (*(char *)(*DAT_021c9048 + 0x41) == '\0') {
        FUN_021bf698();
        iVar2 = FUN_021cce6c();
        sVar1 = func_0x02133068(iVar2 * 0x91,0x37);
        *DAT_021c904c = sVar1;
        FUN_021c8b94();
        *(undefined1 *)(*DAT_021c9048 + 0x41) = 4;
        return;
      }
      break;
    case 3:
      *(undefined1 *)(*DAT_021c9048 + 0x45) = 0;
      iVar2 = FUN_021cce6c();
      sVar1 = func_0x02133068(iVar2 * 0x91,0x37);
      *DAT_021c904c = sVar1;
      FUN_021cdc10(0x13);
      FUN_021c8b94();
      iVar2 = func_0x02147cd8(*DAT_021c904c,0x1d);
      if (iVar2 == 0) {
        FUN_021c812c();
        return;
      }
      if (iVar2 < 0x10) {
        uVar3 = FUN_021d3544(0,DAT_021c9050,0,0x78);
        *(undefined4 *)(*DAT_021c9048 + 0x38) = uVar3;
        return;
      }
      uVar3 = FUN_021d3544(0,DAT_021c9054,0,0x78);
      *(undefined4 *)(*DAT_021c9048 + 0x38) = uVar3;
      return;
    case 4:
      if (*DAT_021c904c != 0) {
        FUN_021cdc10(0x13);
        uVar3 = FUN_021d3544(0,DAT_021c9050,0,0x78);
        *(undefined4 *)(*DAT_021c9048 + 0x38) = uVar3;
        return;
      }
      if (*(char *)(*DAT_021c9048 + 0x46) == '\0') {
        FUN_021cdc10(9);
        *(undefined1 *)(*DAT_021c9048 + 0x46) = 1;
        return;
      }
      break;
    case 5:
    case 7:
      *(undefined1 *)(*DAT_021c9048 + 0x46) = 0;
      break;
    case 6:
      if (*DAT_021c904c != 0x91) {
        FUN_021cdc10(0x13);
        uVar3 = FUN_021d3544(0,DAT_021c9054,0,0x78);
        *(undefined4 *)(*DAT_021c9048 + 0x38) = uVar3;
        return;
      }
      if (*(char *)(*DAT_021c9048 + 0x46) == '\0') {
        FUN_021cdc10(9);
        *(undefined1 *)(*DAT_021c9048 + 0x46) = 1;
        return;
      }
    }
  }
  return;
}

