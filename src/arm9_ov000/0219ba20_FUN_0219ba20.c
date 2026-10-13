/* Decompiled C draft; module arm9_ov000; ROM address 0219ba20. No matching claim. */
#include "types.h"
#include "deps/0219ba20_FUN_0219ba20.h"

undefined4 FUN_0219ba20(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*(int *)*DAT_0219ba9c != 0) {
    return 0;
  }
  iVar1 = FUN_021a3448(DAT_0219baa0);
  iVar3 = *DAT_0219ba9c;
  uVar2 = FUN_0219a760(0,iVar1 + DAT_0219baa4 & 0xffff,0);
  uVar2 = FUN_02198ac4(*DAT_0219ba9c,uVar2,*(undefined4 *)(iVar3 + 0x14),
                       *(undefined4 *)(iVar3 + 0x18),DAT_0219baa8);
  iVar1 = FUN_0219b704();
  if (iVar1 != 0) {
    return uVar2;
  }
  thunk_FUN_0219a3f4(*(undefined4 *)*DAT_0219ba9c,DAT_0219baac);
  FUN_021988d4(*(undefined4 *)*DAT_0219ba9c,DAT_0219bab0);
  return uVar2;
}

