/* Decompiled C draft; module arm9_ov003; ROM address 021c8974. No matching claim. */
#include "types.h"
#include "deps/021c8974_FUN_021c8974.h"

void FUN_021c8974(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  
  iVar1 = FUN_021cdb6c();
  switch(param_1) {
  case 0:
  case 1:
    uVar3 = 0;
    uVar4 = 0;
    iVar1 = FUN_021c8904(0);
    if (iVar1 == 0) {
      uVar4 = 2;
    }
    break;
  case 2:
    if (*(char *)(iVar1 + 0xf5) == '\0') {
      uVar3 = 2;
      uVar2 = 3;
    }
    else {
      uVar3 = 1;
      uVar2 = 4;
    }
    uVar4 = *(char *)(*DAT_021c8a5c + 4) != '\0';
    FUN_021c8838(uVar2,*(char *)(*DAT_021c8a5c + 5) != '\0',param_2);
    break;
  case 3:
  case 4:
  case 5:
    uVar3 = 0;
    if (*(char *)(iVar1 + 0xf5) == '\0') {
      uVar4 = 0;
    }
    else {
      uVar4 = 2;
    }
    break;
  case 6:
    uVar4 = 0;
    if (*(char *)(iVar1 + 0xf6) == '\0') {
      if (*(char *)(iVar1 + 0xf5) == '\0') {
        uVar4 = 2;
      }
      uVar3 = 2;
      uVar2 = 3;
    }
    else {
      uVar3 = 1;
      uVar2 = 4;
    }
    if (*(char *)(*DAT_021c8a5c + 6) != '\0') {
      uVar4 = 1;
    }
    FUN_021c8838(uVar2,*(char *)(*DAT_021c8a5c + 7) != '\0',param_2);
    break;
  case 7:
  case 8:
    uVar3 = 0;
    if (*(char *)(iVar1 + 0xf6) == '\0') {
      uVar4 = 0;
    }
    else {
      uVar4 = 2;
    }
    break;
  default:
    uVar3 = 0;
    uVar4 = 2;
  }
  FUN_021c8838(uVar3,uVar4,param_2);
  return;
}

