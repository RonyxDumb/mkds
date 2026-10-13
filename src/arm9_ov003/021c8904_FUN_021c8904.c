/* Decompiled C draft; module arm9_ov003; ROM address 021c8904. No matching claim. */
#include "types.h"
#include "deps/021c8904_FUN_021c8904.h"

undefined4 FUN_021c8904(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_021cdb6c();
  uVar2 = 1;
  switch(param_1) {
  case 0:
  case 1:
    if ((byte)(*(char *)(iVar1 + 0xe7) - 1U) < 2) {
      uVar2 = 0;
    }
    break;
  case 4:
  case 5:
  case 6:
    if (*(char *)(iVar1 + 0xf5) != '\0') {
      uVar2 = 0;
    }
    break;
  case 7:
    if (*(char *)(iVar1 + 0xf5) == '\0') {
      uVar2 = 0;
    }
    break;
  case 9:
  case 10:
    if (*(char *)(iVar1 + 0xf6) != '\0') {
      uVar2 = 0;
    }
  }
  return uVar2;
}

