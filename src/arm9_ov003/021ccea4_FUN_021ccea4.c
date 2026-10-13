/* Decompiled C draft; module arm9_ov003; ROM address 021ccea4. No matching claim. */
#include "types.h"
#include "deps/021ccea4_FUN_021ccea4.h"

void FUN_021ccea4(int param_1,undefined1 param_2,undefined4 param_3,int param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_021d283c(0x20,4);
  piVar1 = DAT_021ccf24;
  *DAT_021ccf24 = iVar2;
  *(char *)(iVar2 + 0x1b) = (char)param_1;
  *(undefined1 *)(*piVar1 + 0x19) = param_2;
  *(char *)(*piVar1 + 0x1a) = (char)param_5;
  FUN_021d2544(param_3,param_4,(undefined2 *)(uintptr_t)(*piVar1 + 0x10));
  uVar3 = FUN_021d1be4(0,*(undefined1 *)(DAT_021ccf28 + param_1),1);
  piVar1 = DAT_021ccf24;
  *(undefined4 *)*DAT_021ccf24 = uVar3;
  FUN_021d17d4(*(undefined4 *)*piVar1,0xffffffff,param_3,param_4 + param_5);
  FUN_021d1790(*(undefined4 *)*DAT_021ccf24,0xffffffff,1);
  uVar3 = FUN_021d3544(0,DAT_021ccf2c,0,0x80);
  *(undefined4 *)(*DAT_021ccf24 + 0xc) = uVar3;
  return;
}

