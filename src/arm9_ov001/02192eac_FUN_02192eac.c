/* Decompiled C draft; module arm9_ov001; ROM address 02192eac. No matching claim. */
#include "types.h"
#include "deps/02192eac_FUN_02192eac.h"

void FUN_02192eac(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *DAT_02192ec0;
  uVar1 = param_1[1];
  *(undefined4 *)(iVar2 + 0x18) = *param_1;
  *(undefined4 *)(iVar2 + 0x1c) = uVar1;
  uVar1 = param_1[3];
  *(undefined4 *)(iVar2 + 0x20) = param_1[2];
  *(undefined4 *)(iVar2 + 0x24) = uVar1;
  return;
}

