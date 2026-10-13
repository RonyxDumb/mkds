/* Decompiled C draft; module arm9_ov003; ROM address 021d1358. No matching claim. */
#include "types.h"
#include "deps/021d1358_FUN_021d1358.h"

void FUN_021d1358(int param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  *DAT_021d13fc = param_1;
  FUN_021cfa30(param_1 + DAT_021d1400);
  piVar1 = DAT_021d13fc;
  *(undefined2 *)(*DAT_021d13fc + DAT_021d1404) = 0;
  *(undefined2 *)(*piVar1 + DAT_021d1408) = 0;
  *(undefined1 *)(*piVar1 + DAT_021d140c) = 1;
  *(undefined1 *)(*piVar1 + DAT_021d1410) = 1;
  *(undefined4 *)(*piVar1 + DAT_021d1414) = 0;
  FUN_021d0a18();
  piVar1 = DAT_021d13fc;
  *(undefined4 *)(*DAT_021d13fc + DAT_021d1418) = *param_2;
  *(undefined4 *)(*piVar1 + DAT_021d141c) = param_2[1];
  *(undefined4 *)(*piVar1 + DAT_021d1420) = param_2[2];
  *(undefined4 *)(*piVar1 + DAT_021d1424) = param_2[3];
  *(undefined4 *)(*piVar1 + DAT_021d1428) = param_2[4];
  *(undefined4 *)(*piVar1 + DAT_021d142c) = param_2[5];
  *(undefined1 *)(*piVar1 + DAT_021d1430) = *(undefined1 *)(param_2 + 6);
  *(undefined1 *)(*piVar1 + DAT_021d1434) = 2;
  func_0x0200f5ac();
  func_0x02151804(*DAT_021d13fc + DAT_021d1438);
  func_0x0200f5ac();
  uVar2 = FUN_021cd4dc();
  *(undefined4 *)(*DAT_021d13fc + DAT_021d143c) = uVar2;
  return;
}

