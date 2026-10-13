/* Decompiled C draft; module arm9; ROM address 02111494. No matching claim. */
#include "types.h"
#include "deps/02111494_func_02111494.h"

void func_02111494(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *piRam021114ac;
  uVar1 = param_1[1];
  *(undefined4 *)(iVar2 + 0x18) = *param_1;
  *(undefined4 *)(iVar2 + 0x1c) = uVar1;
  uVar1 = param_1[3];
  *(undefined4 *)(iVar2 + 0x20) = param_1[2];
  *(undefined4 *)(iVar2 + 0x24) = uVar1;
  *(undefined4 *)(iVar2 + 0x28) = param_1[4];
  return;
}

