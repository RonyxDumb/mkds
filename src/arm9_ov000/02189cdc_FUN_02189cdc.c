/* Decompiled C draft; module arm9_ov000; ROM address 02189cdc. No matching claim. */
#include "types.h"
#include "deps/02189cdc_FUN_02189cdc.h"

undefined4 FUN_02189cdc(int param_1)

{
  undefined8 uVar1;
  
  uVar1 = func_0x0200f5ac();
  *(int *)(param_1 + DAT_02189d14) = (int)uVar1;
  *(int *)(param_1 + DAT_02189d18) = (int)((ulonglong)uVar1 >> 0x20);
  *(undefined1 *)(param_1 + DAT_02189d1c) = 0;
  uVar1 = func_0x0200f5ac();
  *(int *)(param_1 + DAT_02189d14) = (int)uVar1;
  *(int *)(param_1 + DAT_02189d18) = (int)((ulonglong)uVar1 >> 0x20);
  FUN_02189868(DAT_02189d20,DAT_02189d24,(int)*(char *)(param_1 + DAT_02189d1c),DAT_02189d28);
  return 3;
}

