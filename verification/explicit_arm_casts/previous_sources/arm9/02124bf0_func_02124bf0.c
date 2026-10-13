/* Decompiled C draft; module arm9; ROM address 02124bf0. No matching claim. */
#include "types.h"
#include "deps/02124bf0_func_02124bf0.h"

void func_02124bf0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  
  iVar1 = *(ushort *)(param_1 + 6) - 1;
  if (-1 < iVar1) {
    param_5 = param_5 + iVar1 * 0x40;
    do {
      func_02124c70(iVar1,param_2,param_1,param_3,param_4,param_5,0);
      param_5 = param_5 + -0x40;
      iVar1 = iVar1 + -1;
    } while (-1 < iVar1);
  }
  return;
}

