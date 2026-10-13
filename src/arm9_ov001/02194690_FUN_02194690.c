/* Decompiled C draft; module arm9_ov001; ROM address 02194690. No matching claim. */
#include "types.h"
#include "deps/02194690_FUN_02194690.h"

void FUN_02194690(void)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = DAT_021946cc;
  *(int *)(*DAT_021946cc + 0x68) = *(int *)(*DAT_021946cc + 0x68) + 1;
  uVar2 = func_0x020ae4c0(1,0xffffff40,0,*(undefined4 *)(*piVar1 + 0x68),10);
  piVar1 = DAT_021946cc;
  *(undefined4 *)(*DAT_021946cc + 0x6c) = uVar2;
  if (9 < *(int *)(*piVar1 + 0x68)) {
    FUN_02194a34();
  }
  return;
}

