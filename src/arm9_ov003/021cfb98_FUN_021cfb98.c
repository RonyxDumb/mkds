/* Decompiled C draft; module arm9_ov003; ROM address 021cfb98. No matching claim. */
#include "types.h"
#include "deps/021cfb98_FUN_021cfb98.h"

undefined4 FUN_021cfb98(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = func_0x02144c6c(*DAT_021cfc00 + DAT_021cfc04,param_1,*DAT_021cfc00 + DAT_021cfc08);
  if (iVar1 == 7) {
    if ((code *)*DAT_021cfc0c != (code *)0x0) {
      (*(code *)*DAT_021cfc0c)(DAT_021cfc10,DAT_021cfc14);
    }
    return 0;
  }
  if (iVar1 == 5) {
    if ((code *)*DAT_021cfc0c != (code *)0x0) {
      (*(code *)*DAT_021cfc0c)(DAT_021cfc10,DAT_021cfc18);
    }
    FUN_021d079c(5);
    return 0;
  }
  if (iVar1 != 0) {
    FUN_021d079c();
    return 0;
  }
  return 1;
}

