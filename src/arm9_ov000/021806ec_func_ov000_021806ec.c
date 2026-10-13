/* Decompiled C draft; module arm9_ov000; ROM address 021806ec. No matching claim. */
#include "types.h"
#include "deps/021806ec_func_ov000_021806ec.h"

void func_ov000_021806ec(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *piRam02180700;
  uVar1 = param_1[1];
  *(undefined4 *)(iVar2 + 0x1c) = *param_1;
  *(undefined4 *)(iVar2 + 0x20) = uVar1;
  uVar1 = param_1[3];
  *(undefined4 *)(iVar2 + 0x24) = param_1[2];
  *(undefined4 *)(iVar2 + 0x28) = uVar1;
  return;
}

