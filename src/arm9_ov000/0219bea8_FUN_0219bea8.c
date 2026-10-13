/* Decompiled C draft; module arm9_ov000; ROM address 0219bea8. No matching claim. */
#include "types.h"
#include "deps/0219bea8_FUN_0219bea8.h"

void FUN_0219bea8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = FUN_0219c39c();
  piVar1 = DAT_0219bf08;
  if (iVar2 == 0) {
    if (*(int *)(*DAT_0219bf08 + 0x24) == 0) {
      *(undefined4 *)(*DAT_0219bf08 + 0x5c) = param_3;
      *(undefined4 *)(*piVar1 + 0x60) = param_4;
      *(undefined4 *)(*piVar1 + 0x94) = param_1;
      *(undefined4 *)(*piVar1 + 0x98) = param_2;
      iVar2 = FUN_021a3810();
      if (iVar2 != 4) {
        FUN_0219c990(2,DAT_0219bf0c);
        return;
      }
      FUN_0219b8a8(1);
      FUN_0218d6e4(*(undefined4 *)(*DAT_0219bf08 + 0x54));
    }
  }
  return;
}

