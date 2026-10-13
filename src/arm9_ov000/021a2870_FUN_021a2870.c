/* Decompiled C draft; module arm9_ov000; ROM address 021a2870. No matching claim. */
#include "types.h"
#include "deps/021a2870_FUN_021a2870.h"

void FUN_021a2870(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int *piVar1;
  undefined1 *puVar2;
  
  piVar1 = DAT_021a2914;
  *DAT_021a2914 = (int)param_1;
  *param_1 = param_2;
  *(undefined4 *)(*piVar1 + 4) = param_3;
  *(undefined4 *)(*piVar1 + 8) = param_4;
  *(undefined4 *)(*piVar1 + 0x10) = 0;
  *(undefined4 *)(*piVar1 + 0x1c) = 0;
  *(undefined2 *)(*piVar1 + 0x1a) = 0;
  *(undefined4 *)(*piVar1 + 0xe4) = 0;
  *(undefined4 *)(*piVar1 + DAT_021a2918) = 0;
  *(undefined1 *)(*piVar1 + 0xf) = 0;
  *(undefined1 *)(*piVar1 + 0x19) = 0;
  *(undefined1 *)(*piVar1 + DAT_021a291c) = 0;
  *(undefined4 *)(*piVar1 + DAT_021a2920) = 0;
  *(undefined4 *)(*piVar1 + DAT_021a2924) = param_5;
  *(undefined4 *)(*piVar1 + DAT_021a2928) = param_6;
  *(undefined4 *)(*piVar1 + DAT_021a292c) = param_7;
  *(undefined4 *)(*piVar1 + DAT_021a2930) = param_8;
  func_0x0214d168((uint *)(uintptr_t)(*piVar1 + DAT_021a2934),0,0x40);
  *(undefined4 *)(*piVar1 + DAT_021a2938) = 0;
  *(undefined4 *)(*piVar1 + DAT_021a293c) = 0;
  *(undefined4 *)(*piVar1 + DAT_021a2940) = 0;
  *(undefined4 *)(*piVar1 + DAT_021a2944) = 0;
  *(undefined4 *)(*piVar1 + DAT_021a2948) = 0;
  FUN_0219ea88();
  puVar2 = DAT_021a294c;
  *DAT_021a294c = 0;
  puVar2[1] = 0;
  *(undefined2 *)(puVar2 + 2) = 0;
  FUN_021a1140();
  return;
}

