/* Decompiled C draft; module arm9_ov000; ROM address 0219dee0. No matching claim. */
#include "types.h"
#include "deps/0219dee0_FUN_0219dee0.h"

void FUN_0219dee0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 < 0x33) {
    if (0x31 < param_1) {
      FUN_021a4760(param_2,*(undefined4 *)(*DAT_0219dfd0 + DAT_0219dfd4));
      return;
    }
    if ((param_1 < 0xb) && (7 < param_1)) {
      if (param_1 == 8) {
        FUN_021a4760(param_2,*(undefined1 *)(*DAT_0219dfd0 + 0x14));
        return;
      }
      if (param_1 == 10) {
        FUN_021a4760(param_2,*(undefined1 *)(*DAT_0219dfd0 + 0x16));
        return;
      }
    }
  }
  else {
    switch(param_1) {
    case 0x33:
      FUN_021a4760(param_2,*(undefined1 *)(*DAT_0219dfd0 + 0x15));
      return;
    case 0x34:
      FUN_021a4760(param_2,*(undefined4 *)(*DAT_0219dfd0 + 0x20));
      return;
    case 0x35:
      FUN_021a4760(param_2,3);
      return;
    case 0x36:
      FUN_021a4760(param_2,1);
      return;
    }
  }
  iVar1 = (param_1 + -100) * 0xc;
  if (*(char *)(DAT_0219dfd8 + iVar1) != '\0') {
    if (*(char *)(DAT_0219dfdc + iVar1) != '\0') {
      FUN_021a471c(param_2,*(undefined4 *)(DAT_0219dfe0 + iVar1));
      return;
    }
    FUN_021a4760(param_2,**(undefined4 **)(DAT_0219dfe0 + iVar1));
  }
  return;
}

