/* Decompiled C draft; module arm9_ov000; ROM address 02188114. No matching claim. */
#include "types.h"
#include "deps/02188114_FUN_02188114.h"

undefined4 FUN_02188114(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  if (*DAT_021881ac != 0) {
    return 4;
  }
  iVar2 = (*(code *)*param_1)(DAT_021881b0,DAT_021881b4);
  *DAT_021881ac = iVar2;
  if (iVar2 == 0) {
    return 4;
  }
  func_0x0214d168((uint *)(uintptr_t)(iVar2),0,DAT_021881b4);
  piVar1 = DAT_021881ac;
  *(undefined4 *)(*DAT_021881ac + 4) = DAT_021881b8;
  iVar2 = DAT_021881bc;
  iVar4 = *piVar1;
  puVar5 = (undefined4 *)(iVar4 + DAT_021881bc);
  uVar3 = param_1[1];
  *puVar5 = *param_1;
  puVar5[1] = uVar3;
  puVar5[2] = param_1[2];
  if (*DAT_021881c0 != 0) {
    return 4;
  }
  iVar2 = (**(code **)(iVar4 + iVar2))(DAT_021881c4,DAT_021881c8);
  *DAT_021881c0 = iVar2;
  if (iVar2 == 0) {
    return 4;
  }
  func_0x0200edc0(*DAT_021881ac + DAT_021881cc);
  FUN_02188008();
  return 0;
}

