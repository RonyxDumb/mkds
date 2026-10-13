/* Decompiled C draft; module arm9_ov003; ROM address 021c8a60. No matching claim. */
#include "types.h"
#include "deps/021c8a60_FUN_021c8a60.h"

void FUN_021c8a60(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_r5;
  undefined1 auStack_38 [40];
  
  iVar1 = FUN_021cdb6c();
  switch(param_1) {
  case 0:
    FUN_021c876c(iVar1 + 0x40,param_2);
    return;
  case 1:
    switch(*(byte *)(iVar1 + 0xe6) & 3) {
    case 0:
      return;
    case 1:
      unaff_r5 = 10;
      break;
    case 2:
      unaff_r5 = 0x1a;
      break;
    case 3:
      unaff_r5 = 0x20;
    }
    if (((uint)*(byte *)(iVar1 + 0xe6) << 0x18) >> 0x1a == 1) {
      unaff_r5 = func_0x02133068(unaff_r5,2);
    }
    func_0x0214d168(auStack_38,0,0x21);
    func_0x02134de0(auStack_38,0x2a,unaff_r5);
    FUN_021c876c(auStack_38,param_2);
    return;
  case 3:
    if (*(char *)(iVar1 + 0xf5) == '\0') {
      FUN_021c8718(iVar1 + 0xc0,param_2);
      return;
    }
    break;
  case 4:
    if (*(char *)(iVar1 + 0xf5) == '\0') {
      FUN_021c8718(iVar1 + 0xf0,param_2);
      return;
    }
    break;
  case 5:
    if (*(char *)(iVar1 + 0xf5) == '\0') {
      FUN_021c8718(iVar1 + 0xc4,param_2);
      return;
    }
    break;
  case 7:
    if (*(char *)(iVar1 + 0xf6) == '\0') {
      FUN_021c8718(iVar1 + 200,param_2);
      return;
    }
    break;
  case 8:
    if (*(char *)(iVar1 + 0xf6) == '\0') {
      FUN_021c8718(iVar1 + 0xcc,param_2);
    }
  }
  return;
}

