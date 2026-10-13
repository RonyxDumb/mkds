/* Decompiled C draft; module arm9_ov000; ROM address 0219d8c8. No matching claim. */
#include "types.h"
#include "deps/0219d8c8_FUN_0219d8c8.h"

void FUN_0219d8c8(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_0219d930;
  *DAT_0219d930 = (int)param_1;
  *param_1 = 0;
  *(undefined4 *)(*piVar1 + 4) = param_2;
  *(undefined4 *)(*piVar1 + 8) = 0;
  iVar2 = *piVar1;
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(undefined4 *)(iVar2 + 0x10) = 0;
  *(undefined4 *)(iVar2 + 0x14) = param_5;
  *(undefined4 *)(*piVar1 + 0x18) = param_4;
  *(undefined1 *)(*piVar1 + 0x1c) = 0;
  *(undefined1 *)(*piVar1 + 0x1d) = 0;
  *(undefined1 *)(*piVar1 + 0x1e) = 0;
  *(undefined1 *)(*piVar1 + 0x1f) = 0;
  *(undefined4 *)(*piVar1 + 0x20) = 0;
  *(undefined4 *)(*piVar1 + 0x24) = 0;
  *(undefined4 *)(*piVar1 + 0x28) = param_3;
  *(undefined4 *)(*piVar1 + 0x2c) = 0;
  *(undefined4 *)(*piVar1 + 0x30) = 0;
  *(undefined4 *)(*piVar1 + 0x34) = 0;
  *(undefined4 *)(*piVar1 + 0x38) = 0;
  *(undefined4 *)(*piVar1 + 0x3c) = 0;
  *(undefined4 *)(*piVar1 + 0x40) = 0;
  *(undefined4 *)(*piVar1 + 0x44) = 0;
  *(undefined4 *)(*piVar1 + 0x48) = 0;
  *(undefined4 *)(*piVar1 + 0x4c) = 0;
  *(undefined4 *)(*piVar1 + 0x50) = 0;
  return;
}

